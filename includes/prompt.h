/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:35:34 by fhenrion          #+#    #+#             */
/*   Updated: 2020/04/07 11:30:05 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# include "duckshell_structs.h"
# include "duckshell_globals.h"

# define PROMPT "\n\033[0;32mDuckShell ( ^)> \033[0m"
# define ERR_PROMPT "\n\033[0;31mDuckShell ( X)> \033[0m"
# define PROMPT_LEN 28
# define HIDDEN "\n\033[0;32mDuckShell ('O)>\033[0m COIN COIN !?\n"
# define HIDDEN_LEN 41

int		prompt(char line[ARG_MAX], int ret);
int		check_token(char line[ARG_MAX], char token[3]);

#endif
