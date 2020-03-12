/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duckshell_globals.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:26:34 by fhenrion          #+#    #+#             */
/*   Updated: 2020/03/12 16:43:02 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUCKSHELL_GLOBALS_H
# define DUCKSHELL_GLOBALS_H

# include <sys/types.h>
# include <limits.h>
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <dirent.h>
# include "libft.h"
# include "duckshell_structs.h"

# define PROMPT "\n\033[0;32mDuckShell ( ^)> \033[0m"
# define PROMPT_LEN 28
# define ERR_PROMPT "\n\033[0;31mDuckShell ( X)> \033[0m"
# define ERR_PROMPT_LEN 28
# define HIDDEN "\n\033[0;32mDuckShell ('O)>\033[0m COIN COIN !?\n"
# define HIDDEN_LEN 41
# define CLEAR_KEYS "\033[2C\033[K"
# define CLEAR_LEN 7
# define TOKEN_ERROR "microshell: syntax error near unexpected token `%s'\n"
# define EXIT_ERROR(message) {perror(message); exit(errno);}
# define RETURN_ERROR(message) {perror(message); return (ERROR);}

char				**g_env;
char				**g_env_path;
t_var				*g_env_lst;

#endif
