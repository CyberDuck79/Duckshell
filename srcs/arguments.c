/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:15:21 by fhenrion          #+#    #+#             */
/*   Updated: 2020/03/12 17:02:48 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arguments.h"

// OK
static t_dir	get_redirection(char **line)
{
	t_dir	direction = NO_REDIR;

	if (!strncmp(**line, ">>", 2))
		direction = ADD;
	else if (!strncmp(**line, ">", 1))
		direction = OUT;
	else if (!strncmp(**line, "<", 1))
		direction = IN;
	if (direction)
	{
		(*line) += direction == ADD ? 2 : 1;
		while (**line == ' ')
			(*line)++;
	}
	return (direction);
}

// faire les 3 fonctions de copie d'argument
static int		get_arg(char **line, char *value)
{
	if (IS_TOKEN(**line))
		return (ERROR);
	if (**line == '"')
		double_quote_cpy(&value, line);
	else (**line == "\'")
		simple_quote_cpy(&value, line);
	else
		normal_cpy(&value, line);
	if (IS_TOKEN(**line))
		return (EXIT_SUCCESS);
	return (get_arg(line, value));
}

// OK
int				parse_args(char **line, t_arg **arg)
{
	while (**line == ' ')
		(*line)++;
	if (IS_TOKEN(**line))
		return (EXIT_SUCCESS);
	if ((*arg = ft_calloc(1, sizeof(t_arg))) == NULL)
		return (NULL);
	(*arg)->direction = get_redirection(line);
	if (get_arg(line, (*arg)->value) == ERROR)
		return (ERROR);
	return (parse_args(line, &(*arg)->next));
}

// OK
static size_t	args_count(t_arg *arg_lst)
{
	size_t	len = 1;

	while (arg_lst)
	{
		if (!arg_lst->direction)
			len++;
		arg_lst = arg_lst->next;
	}
	return (len);
}

// OK
char			**arg_conv(t_arg *arg_lst)
{
	char	**tab;
	size_t	index = 0;

	if ((tab = ft_calloc(args_count(arg_lst), sizeof(char*))) == NULL)
		return (NULL);
	while (arg_lst)
	{
		if (!arg_lst->direction)
		{
			tab[index] = arg_lst->value;
			index++;
		}
		arg_lst = arg_lst->next;
	}
	tab[index] = NULL;
	return (tab);
}
