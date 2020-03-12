/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 20:19:59 by fhenrion          #+#    #+#             */
/*   Updated: 2020/03/12 14:56:47 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

static t_var	*free_env_lst(t_var *env_lst)
{
	t_var	*node;

	while (env_lst)
	{
		node = env_lst;
		env_lst = env_lst->next;
		if (node->key)
			free(env_lst->key);
		if (node->value)
			free(env_lst->value);
		free(node);
	}
	return (NULL);
}

char			**get_path(char *env[])
{
	size_t	index = 0;

	while (env[index])
	{
		if (!strncmp(env[index], "PATH=", 5))
			return (ft_split(strchr(env[index], '=') + 1, ':'));
		index++;
	}
	return (NULL);
}

t_var			*env_lst_conv(char *env[])
{
	t_var	*env_lst;
	t_var	*env_var;

	if ((env_lst = malloc(sizeof(t_var))) == NULL)
		return (NULL);
	env_var = env_lst;
	while (*env)
	{
		if ((env_var->key = ft_substrchr(*env, '=')) == NULL)
			return (free_env_lst(env_lst));
		if ((env_var->value = ft_substrrchr(*env, '=')) == NULL)
			return (free_env_lst(env_lst));
		env++;
		if (*env && ((env_var->next = malloc(sizeof(t_var))) == NULL))
			return (free_env_lst(env_lst));
		env_var = env_var->next;
	}
	return (env_lst);
}
