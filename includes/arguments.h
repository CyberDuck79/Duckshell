/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:37:28 by fhenrion          #+#    #+#             */
/*   Updated: 2020/03/13 12:17:12 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENTS_H
# define ARGUMENTS_H

# include "duckshell_structs.h"
# include "duckshell_globals.h"

# define IS_TOKEN(chr) (chr == '\0' || chr == ';' || chr == '|' || chr == ' ')
# define IS_SEP(chr) (chr == '\0' || chr == ';' || chr == '|')

int		parse_args(char **line, t_arg **arg);
char	**arg_conv(t_arg *arg_lst);

#endif
