/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 10:33:01 by fhenrion          #+#    #+#             */
/*   Updated: 2020/03/13 00:50:24 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "executions.h"
#include "redirections.h"
#include "signals.h"
#include "free.h"

// diviser le ficher -> mettre dans commands certaines fonctions

// to test
static int		pipe_start(t_cmd *cmd)
{
	t_redir	*tmp_redir;

	if (cmd->pipe)
	{
		tmp_redir = cmd->redir_lst;
		while (tmp_redir)
		{
			if (tmp_redir->std == STDOUT_FILENO)
				return (FAILURE);
			tmp_redir = tmp_redir->next;
		}
		return (SUCCESS);
	}
	return (FAILURE);
}

// to test
static int		pipe_end(t_cmd *cmd)
{
	t_redir *tmp_redir;

	if (cmd->pipe)
		return (ERROR);
	tmp_redir = cmd->redir_lst;
	while (tmp_redir)
	{
		if (tmp_redir->std == STDIN_FILENO)
			return (SUCCESS);
		tmp_redir = tmp_redir->next;
	}
	return (FAILURE);
}

// to test
static t_cmd	*next_node(t_cmd *cmd)
{
	if (pipe_start(cmd) == SUCCESS)
	{
		if (pipe_end(cmd->next) == SUCCESS)
			return (cmd->next);
		else if (!cmd->next->pipe)
			return (cmd->next->next);
		cmd = cmd->next;
	}
	return (cmd->next);
}

void	dup_stdio(int pipe_fd[2], int std_fileno)
{
	if (dup2(pipe_fd[std_fileno], std_fileno) == ERROR)
		EXIT_ERROR("dup2")
	if (close(pipe_fd[1]) == ERROR)
		EXIT_ERROR("close")
	if (close(pipe_fd[0]) == ERROR)
		EXIT_ERROR("close")
}

void	execute_cmd(t_cmd *cmd)
{
	if (apply_redir(cmd->redir_lst) == ERROR)
		perror(cmd->argv[0]);
	else if (execve(get_bin(cmd->argv[0], g_env_path), cmd->argv, g_env) == ERROR)
		EXIT_ERROR(cmd->argv[0])
}

// to test
void	execute_pipes(t_cmd *cmd, int pipe_in, int parent_fd[2])
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe_in)
		dup_stdio(parent_fd, STDIN_FILENO);
	if (cmd->pipe)
	{
		if (pipe(pipe_fd) == ERROR)
			EXIT_ERROR("pipe")
		if (pipe_end(cmd->next) == EXIT_FAILURE)
		{
			if ((pid = fork()) == ERROR)
				EXIT_ERROR("fork")
			if (pid == 0)
				execute_pipes(cmd->next, 1, pipe_fd);
		}
		dup_stdio(pipe_fd, STDOUT_FILENO);
	}
	if (execve(get_bin(cmd->argv[0], g_env_path), cmd->argv, g_env) == ERROR)
		EXIT_ERROR(cmd->argv[0])
}

// calcul a faire sur le status pour le code de retour ?
static int		wait_childs(void)
{
	int	status;
	int	last_status;

	while (wait(&status) != ERROR)
		last_status = status;
	if (errno != ECHILD)
		perror("duckshell");
	if (WIFSIGNALED(last_status) && (WTERMSIG(last_status) == SIGQUIT))
	{
		write(STDERR_FILENO, "Quit: 3", 8);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (last_status);
}

// a tester :
// execution des pipes
// calcul de la commande suivante
// code de retour
int				execute_cmds(t_cmd *cmd_lst)
{
	t_exec	exec;

	bzero(&exec, sizeof(t_exec));
	exec.cmd_node = cmd_lst;
	while (exec.cmd_node)
	{
		if ((exec.pid = fork()) == ERROR)
			EXIT_ERROR("fork")
		if (exec.pid == 0)
		{
			signal(SIGINT, SIG_DFL);
			signal(SIGQUIT, SIG_DFL);
			if (pipe_start(exec.cmd_node) == SUCCESS)
				execute_pipes(exec.cmd_node, 0, 0);
			else
				execute_cmd(exec.cmd_node);
		}
		exec.cmd_node = next_node(exec.cmd_node);
		signal(SIGINT, parent_handler);
		exec.ret = wait_childs();
		signal(SIGINT, signal_handler);
	}
	return (exec.ret);
}
