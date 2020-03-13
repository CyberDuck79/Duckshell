/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:10:04 by fhenrion          #+#    #+#             */
/*   Updated: 2020/03/13 12:34:25 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "signals.h"
#include "arguments.h"

// voir pour ne pas avoir besoin de close la ligne par \0 -> arrêt à \n
int		prompt(char line[ARG_MAX], int ret)
{
	ssize_t	read_status;
	ssize_t	read_index;

	ft_putstr(ret ? ERR_PROMPT : PROMPT);
	if ((read_status = read(STDIN_FILENO, line, ARG_MAX)) == ERROR)
		RETURN_ERROR("DuckShell: commandline reading")
	else if (read_status)
	{
		read_index = read_status;
		while (line[read_index - 1] != '\n')
		{
			write(STDOUT_FILENO, CLEAR_EOF, CLEAR_EOF_LEN);
			read_status = read(STDIN_FILENO, &line[read_index], ARG_MAX);
			if (read_status == ERROR)
				RETURN_ERROR("DuckShell: commandline reading")
			read_index += read_status;
		}
		line[read_index - 1] = '\0';
	}
	else
	{
		write(STDOUT_FILENO, CLEAR_EOF, CLEAR_EOF_LEN);
		strlcpy(line, "exit", 5);
		write(STDOUT_FILENO, PROMPT, PROMPT_LEN);
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
