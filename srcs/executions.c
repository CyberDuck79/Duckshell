/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 10:33:01 by fhenrion          #+#    #+#             */
/*   Updated: 2020/04/07 16:45:14 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "executions.h"
#include "redirections.h"
#include "signals.h"
#include "free.h"

void	execute_cmd(t_cmd *cmd, char **env)
{
	if (apply_redir(cmd->redir_lst) == ERROR)
		EXIT_ERROR(cmd->argv[0])
	if (execve(cmd->path, cmd->argv, env) == ERROR)
		EXIT_ERROR(cmd->argv[0])
}

int				execute_cmds(t_cmd *cmd_lst, char **env)
{
	pid_t	pid;
	int		status;
	t_cmd	*cmd = cmd_lst;

	while (cmd)
	{
		if ((pid = fork()) == ERROR)
			EXIT_ERROR("fork")
		if (pid == 0)
		{
			signal(SIGINT, SIG_DFL);
			signal(SIGQUIT, SIG_DFL);
			execute_cmd(cmd, env);
		}
		cmd = cmd->next;
		if (wait(&status) == ERROR)
			perror("duckshell");
		if (WIFSIGNALED(status) && (WTERMSIG(status) == SIGQUIT))
			write(STDERR, "Quit: 3", 8);
	}
	return (status);
}
/*
SI PIPE :
ouvrir un pipe avant le fork
dup stdout avec le pipe d'entrée dans l'enfant
donner le pipe de sortie a la commande suivante et dup la stdin
-----> qui doit attendre qui et comment ?
la première commande n'a pas besoin d'attendre,
elle écrit sur stdout et envoi dans le buffer du pipe si pas lu tout de suite

*/