/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:31:34 by fhenrion          #+#    #+#             */
/*   Updated: 2020/03/13 00:34:06 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "duckshell_globals.h"
# include "duckshell_structs.h"

char				**g_env;
char				**g_env_path;
t_var				*g_env_lst;

char				**get_path(char *env[]);
t_var				*env_lst_conv(char *env[]);
char				*get_bin(char *name, char **path);

#endif
