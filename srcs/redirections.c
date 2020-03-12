/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:21:58 by fhenrion          #+#    #+#             */
/*   Updated: 2020/03/12 16:52:24 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections.h"

// OK
static int	open_redir(t_arg *arg, t_redir *redir)
{
	if (arg->direction == IN)
	{
		if ((redir->fd = open(arg->value, O_RDONLY)) == ERROR)
			return (ERROR);
	}
	else if (arg->direction == OUT)
	{
		if ((redir->fd = \
		open(arg->value, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == ERROR)
			return (ERROR);
	}
	else if ((redir->fd = \
	open(arg->value, O_WRONLY | O_CREAT | O_APPEND, 0644)) == ERROR)
		return (ERROR);
	redir->std = arg->direction == IN ? STDIN_FILENO : STDOUT_FILENO;
	return (EXIT_SUCCESS);
}

// forcément besoin de pointeur sur pointeur ?
int			parse_redir(t_cmd *cmd_lst)
{
	t_arg	**tmp_arg;
	t_redir	**tmp_redir;

	while (cmd_lst)
	{
		tmp_arg = &cmd_lst->arg_lst;
		tmp_redir = &cmd_lst->redir_lst;
		while (*tmp_arg)
		{
			if ((*tmp_arg)->direction)
			{
				if ((*tmp_redir = ft_calloc(1, sizeof(t_redir))) == NULL)
					return (ERROR);
				if (open_redir(*tmp_arg, *tmp_redir) == ERROR)
					return (ERROR);
				tmp_redir = &(*tmp_redir)->next;
			}
			tmp_arg = &(*tmp_arg)->next;
		}
		cmd_lst = cmd_lst->next;
	}
	return (EXIT_SUCCESS);
}

// OK
int			apply_redir(t_redir *redir_lst)
{
	while (redir_lst)
	{
		if (dup2(redir_lst->fd, redir_lst->std) == ERROR)
			return (ERROR);
		if (close(redir_lst->fd) == ERROR)
			return (ERROR);
		redir_lst = redir_lst->next;
	}
	return (EXIT_SUCCESS);
}
