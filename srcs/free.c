/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 10:00:23 by fhenrion          #+#    #+#             */
/*   Updated: 2020/03/13 00:31:58 by fhenrion         ###   ########.fr       */
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
void		free_cmd_lst(t_cmd **cmd_lst)
{
	t_cmd	*tmp_cmd;

	while (*cmd_lst)
	{
		tmp_cmd = *cmd_lst;
		*cmd_lst = tmp_cmd->next;
		free_lst((t_list*)tmp_cmd->arg_lst);
		free_lst((t_list*)tmp_cmd->redir_lst);
		free(tmp_cmd->argv);
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
void		*free_env_lst(t_var *env_lst)
{
	t_var	*tmp;

	while (env_lst)
	{
		tmp = env_lst;
		env_lst = env_lst->next;
		if (tmp->key)
			free(tmp->key);
		if (tmp->value)
			free(tmp->value);
		free(tmp);
	}
	return (NULL);
}
