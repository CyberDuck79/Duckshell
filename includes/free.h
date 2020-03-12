/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 09:57:56 by fhenrion          #+#    #+#             */
/*   Updated: 2020/03/12 14:50:50 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FREE_H
# define FREE_H

#include "duckshell_structs.h"
#include "duckshell_globals.h"

void	free_cmd_lst(t_cmd **cmd_lst);
void	free_path_tab(char **path_tab);
void	free_env_lst(t_var *g_env_lst);

#endif
