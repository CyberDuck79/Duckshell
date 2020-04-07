/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duckshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 20:06:14 by fhenrion          #+#    #+#             */
/*   Updated: 2020/04/07 12:42:27 by fhenrion         ###   ########.fr       */
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

// test comportement code retour
static void	duckshell(t_env *env)
{
	char	line[ARG_MAX];
	char	token[3];
	int		ret_code = 0;
	t_cmd	*cmd_lst = NULL;

	prompt(line, ret_code);
	while (strcmp("exit", line))
	{
		if (!strcmp("coin coin !", line))
			write(STDOUT, HIDDEN, HIDDEN_LEN);
		else
		{
			if (check_token(line, token))
				dprintf(STDERR, TOKEN_ERROR, token);
			else if (parse_cmds(line, &cmd_lst, env->path) == ERROR)
				perror("DuckShell: commands parsing");
			else if (parse_redir(cmd_lst) == ERROR)
				perror("DuckShell: redirections");
			ret_code = execute_cmds(cmd_lst, env->tab);
			free_cmd_list(&cmd_lst);
		}
		prompt(line, ret_code);
	}
}

// OK
int			main(int argc, char **argv, char **env_tab)
{
	t_env	env;

	VOID_ARGS;
	env.tab = env_tab;
	if ((env.path = get_path(env_tab)) == NULL)
		EXIT_ERROR("duckshell: environment variables")
	if ((env.list = env_list_conv(env_tab)) == NULL)
		EXIT_ERROR("duckshell: environment variables")
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	duckshell(&env);
	write(STDOUT, "exit\n", 5);
	free_path_tab(env.path);
	free_env_list(env.list);
	//system("leaks duckshell"); --> disable fsanitize to use leaks
	return (EXIT_SUCCESS);
}
