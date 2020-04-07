/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:10:04 by fhenrion          #+#    #+#             */
/*   Updated: 2020/04/07 11:28:53 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "signals.h"
#include "arguments.h"

// voir pour ne pas avoir besoin de close la ligne par \0 -> arrêt à \n
// mettre retour dans $?
int		prompt(char line[ARG_MAX], int ret)
{
	ssize_t	status;
	ssize_t	index;

	write(STDOUT, ret ? ERR_PROMPT : PROMPT, PROMPT_LEN);
	if ((status = read(STDIN, line, ARG_MAX)) == ERROR)
		RETURN_ERROR("DuckShell: commandline reading")
	else if (status)
	{
		index = status;
		while (line[index - 1] != '\n')
		{
			write(STDOUT, CLEAR_EOF, CLEAR_EOF_LEN);
			if ((status = read(STDIN, &line[index], ARG_MAX)) == ERROR)
				RETURN_ERROR("DuckShell: commandline reading")
			index += status;
		}
		line[index - 1] = '\0';
	}
	else
	{
		write(STDOUT, CLEAR_EOF, CLEAR_EOF_LEN);
		strlcpy(line, "exit", 5);
		write(STDOUT, PROMPT, PROMPT_LEN);
	}
	return (SUCCESS);
}

// ajouter protection -> toujours utile avec un bon parsing ?
int		check_token(char line[ARG_MAX], char token[3])
{
	while (*line)
	{
		while (*line == ' ')
			line++;
		if (!ft_strncmp(line, ";;", 2))
			return (ft_strcpy(token, ";;"));
		if (!ft_strncmp(line, "||", 2))
			return (ft_strcpy(token, "||"));
		if (*line == ';')
			return (ft_strcpy(token, ";"));
		if (*line == '|')
			return (ft_strcpy(token, "|"));
		while (!IS_SEP(*line))
			line++;
		if (*line)
			line++;
	}
	return (SUCCESS);
}
