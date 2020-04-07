/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 10:00:23 by fhenrion          #+#    #+#             */
/*   Updated: 2020/04/07 12:19:55 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

// OK
static void	free_lst(t_list *lst)
{
	t_list *tmp;

	while (lst)
	{
		tmp = lst;
		lst = tmp->next;
		free(tmp);
	}
}

// OK
void		free_cmd_list(t_cmd **cmd_list)
{
	t_cmd	*tmp_cmd;

	while (*cmd_list)
	{
		tmp_cmd = *cmd_list;
		*cmd_list = tmp_cmd->next;
		free_lst((t_list*)tmp_cmd->arg_lst);
		free_lst((t_list*)tmp_cmd->redir_lst);
		free(tmp_cmd->argv);
		free(tmp_cmd->path);
		free(tmp_cmd);
	}
}

// OK
void		free_path_tab(char **path_tab)
{
	char	**tmp;

	tmp = path_tab;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(path_tab);
}

// OK
void		*free_env_list(t_var *env_list)
{
	t_var	*tmp;

	while (env_list)
	{
		tmp = env_list;
		env_list = env_list->next;
		if (tmp->key)
			free(tmp->key);
		if (tmp->value)
			free(tmp->value);
		free(tmp);
	}
	return (NULL);
}
