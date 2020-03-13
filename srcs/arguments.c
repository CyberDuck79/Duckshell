/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:15:21 by fhenrion          #+#    #+#             */
/*   Updated: 2020/03/13 12:35:59 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arguments.h"

// OK
static t_dir	get_redirection(char **line)
{
	t_dir	direction = NO_REDIR;

	if (!strncmp(*line, ">>", 2))
		direction = ADD;
	else if (**line == '>')
		direction = OUT;
	else if (**line == '<')
		direction = IN;
	if (direction)
	{
		(*line) += direction == ADD ? 2 : 1;
		while (**line == ' ')
			(*line)++;
	}
	return (direction);
}

static void		double_quote_cpy(char **line, char **value)
{
	(*line)++;
	while (**line && **line != '\"')
	{
		**value = **line;
		(*value)++;
		(*line)++;
	}
}

static void		simple_quote_cpy(char **line, char **value)
{
	(*line)++;
	while (**line && **line != '\'')
	{
		**value = **line;
		(*value)++;
		(*line)++;
	}
}

static void		normal_cpy(char **line, char **value)
{
	while (!IS_TOKEN(**line))
	{
		**value = **line;
		(*value)++;
		(*line)++;
	}
}

// faire les 3 fonctions de copie d'argument
static int		get_arg(char **line, char *value)
{
	if (IS_TOKEN(**line))
		return (ERROR);
	if (**line == '"')
		double_quote_cpy(line, &value);
	else if (**line == '\'')
		simple_quote_cpy(line, &value);
	else
		normal_cpy(line, &value);
	if (IS_TOKEN(**line))
	{
		*value = '\0';
		return (SUCCESS);
	}
	return (get_arg(line, value));
}

// OK
int				parse_args(char **line, t_arg **arg)
{
	while (**line == ' ')
		(*line)++;
	if (IS_SEP(**line))
		return (ERROR);
	if ((*arg = ft_calloc(1, sizeof(t_arg))) == NULL)
		return (ERROR);
	(*arg)->direction = get_redirection(line);
	if (get_arg(line, (*arg)->value) == ERROR)
		return (ERROR);
	while (**line == ' ')
		(*line)++;
	if (IS_SEP(**line))
		return (SUCCESS);
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
