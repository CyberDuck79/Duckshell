/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:18:41 by fhenrion          #+#    #+#             */
/*   Updated: 2020/04/07 12:19:49 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"
#include "arguments.h"
#include "environment.h"

// voir pour placer des fonctions ici ?

// OK
int			parse_cmds(char line[ARG_MAX], t_cmd **cmd, char **path)
{
	if ((*cmd = ft_calloc(1, sizeof(t_cmd))) == NULL)
		return (ERROR);
	if (parse_args(&line, &(*cmd)->arg_lst) == ERROR)
		return (ERROR);
	if (((*cmd)->argv = arg_conv((*cmd)->arg_lst)) == NULL)
		return (ERROR);
	if (((*cmd)->path = get_bin((*cmd)->argv[0], path)) == NULL)
		return (ERROR);
	if (!*line)
		return (SUCCESS);
	if (*line == '|')
		(*cmd)->pipe = OUT;
	return (parse_cmds(line + 1, &(*cmd)->next, path));
}
