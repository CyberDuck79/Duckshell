/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duckshell_globals.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:26:34 by fhenrion          #+#    #+#             */
/*   Updated: 2020/04/07 11:29:37 by fhenrion         ###   ########.fr       */
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

# define STDIN STDIN_FILENO
# define STDOUT STDOUT_FILENO
# define STDERR STDERR_FILENO
# define TOKEN_ERROR "microshell: syntax error near unexpected token `%s'\n"
# define EXIT_ERROR(message) {perror(message); exit(errno);}
# define RETURN_ERROR(message) {perror(message); return (ERROR);}

#endif
