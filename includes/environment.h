/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:31:34 by fhenrion          #+#    #+#             */
/*   Updated: 2020/03/09 11:33:14 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "duckshell_globals.h"
# include "duckshell_structs.h"

char				**get_path(char *env[]);
t_var				*env_lst_conv(char *env[]);

#endif
