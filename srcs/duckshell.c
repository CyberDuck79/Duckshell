/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duckshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 20:06:14 by fhenrion          #+#    #+#             */
/*   Updated: 2020/03/13 12:24:48 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "signals.h"
#include "prompt.h"
#include "commands.h"
#include "redirections.h"
#include "executions.h"
#include "free.h"

#define VOID_ARGS (void)argc;(void)argv

// corriger le clear des keys
// test comportement code retour
static void	duckshell(void)
{
	char	line[ARG_MAX];
	char	token[3];
	int		ret_code = 0;
	t_cmd	*cmd_lst = NULL;

	prompt(line, ret_code);
	while (strcmp("exit", line))
	{
		if (!strcmp("coin coin !", line))
			write(STDOUT_FILENO, HIDDEN, HIDDEN_LEN);
		else
		{
			if (check_token(line, token))
				dprintf(STDERR_FILENO, TOKEN_ERROR, token);
			else if (parse_cmds(line, &cmd_lst) == ERROR)
				perror("DuckShell: commands parsing");
			else if (parse_redir(cmd_lst) == ERROR)
				perror("DuckShell: redirections");
			ret_code = execute_cmds(cmd_lst);
			free_cmd_lst(&cmd_lst);
		}
		prompt(line, ret_code);
	}
}

// OK
int			main(int argc, char **argv, char **env)
{
	VOID_ARGS;
	g_env = env;
	if ((g_env_path = get_path(env)) == NULL)
		EXIT_ERROR("duckshell: environment variables")
	if ((g_env_lst = env_lst_conv(env)) == NULL)
		EXIT_ERROR("duckshell: environment variables")
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	duckshell();
	dprintf(STDOUT_FILENO, "exit\n");
	free_path_tab(g_env_path);
	free_env_lst(g_env_lst);
	system("leaks duckshell");
	return (EXIT_SUCCESS);
}
