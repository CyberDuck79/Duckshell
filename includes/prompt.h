/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:35:34 by fhenrion          #+#    #+#             */
/*   Updated: 2020/03/09 11:36:35 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# include "duckshell_structs.h"
# include "duckshell_globals.h"

int		prompt(char line[ARG_MAX], int ret);
int		check_token(char line[ARG_MAX], char token[3]);

#endif
