/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 10:33:01 by fhenrion          #+#    #+#             */
/*   Updated: 2020/03/13 14:28:55 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "executions.h"
#include "redirections.h"
#include "signals.h"
#include "free.h"

// diviser le ficher -> mettre dans commands certaines fonctions

void	dup_stdio(int pipe_fd, int std_fileno)
{
	if (dup2(pipe_fd, std_fileno) == ERROR)
		EXIT_ERROR("dup2")
	if (close(pipe_fd) == ERROR)
		EXIT_ERROR("close")
}

void	execute_cmd(t_cmd *cmd)
{
	if (apply_redir(cmd->redir_lst) == ERROR)
		EXIT_ERROR(cmd->argv[0])
	if (execve(cmd->path, cmd->argv, g_env) == ERROR)
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
	pid_t	pid;
	int		pipe_fd[2];
	int		pipe_in = 0;
	t_cmd	*cmd = cmd_lst;

	bzero(pipe_fd, sizeof(pipe_fd));
	while (cmd)
	{
		if (pipe_fd[0])
			pipe_in = pipe_fd[0];
		if (cmd->pipe && pipe(pipe_fd) == ERROR)
			RETURN_ERROR("pipe")
		else if (!cmd->pipe)
			bzero(pipe_fd, sizeof(pipe_fd));
		if ((pid = fork()) == ERROR)
			EXIT_ERROR("fork")
		if (pid == 0)
		{
			signal(SIGINT, SIG_DFL);
			signal(SIGQUIT, SIG_DFL);
			if (pipe_in)
				dup_stdio(pipe_in, STDIN_FILENO);
			if (cmd->pipe)
				dup_stdio(pipe_fd[1], STDOUT_FILENO);
			execute_cmd(cmd);
		}
		cmd = cmd->next;
	}
	return (wait_childs());
}
