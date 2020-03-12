/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:18:41 by fhenrion          #+#    #+#             */
/*   Updated: 2020/03/12 16:59:43 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"
#include "arguments.h"

// voir pour placer des fonctions ici ?
// OK
int			parse_cmds(char line[ARG_MAX], t_cmd **cmd)
{
	if ((*cmd = ft_calloc(1, sizeof(t_cmd))) == NULL)
		return (ERROR);
	if (parse_args(&line, &(*cmd)->arg_lst) == ERROR)
		return (ERROR);
	if (((*cmd)->argv = arg_conv((*cmd)->arg_lst)) == NULL)
		return (ERROR);
	if (!*line)
		return (EXIT_SUCCESS);
	if (*line == '|')
		(*cmd)->pipe = OUT;
	return (parse_cmds(line + 1, &(*cmd)->next));
}
