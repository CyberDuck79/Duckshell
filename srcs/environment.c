/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 20:19:59 by fhenrion          #+#    #+#             */
/*   Updated: 2020/03/13 00:33:17 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "free.h"

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

static char	*path_join(char *path, char *name)
{
	size_t	path_len;
	size_t	name_len;
	char	*join;

	path_len = ft_strlen(path);
	name_len = ft_strlen(name);
	if ((join = malloc(path_len + name_len + 2)) == NULL)
		return (NULL);
	ft_memcpy(join, path, path_len);
	join[path_len] = '/';
	ft_strlcpy(join + path_len + 1, name, name_len + 1);
	return (join);
}

char		*get_bin(char *name, char **path)
{
	DIR				*dir;
	struct dirent	*entry;

	if (*name == '/' || !ft_strncmp(name, "./", 2))
		return (ft_strdup(name));
	while (*path)
	{
		if ((dir = opendir(*path)) != NULL)
		{
			while ((entry = readdir(dir)))
			{
				if (!strcmp(entry->d_name, name))
				{
					closedir(dir);
					return (path_join(*path, name));
				}
			}
			closedir(dir);
		}
		path++;
	}
	return (NULL);
}
