/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 09:57:56 by fhenrion          #+#    #+#             */
/*   Updated: 2020/04/07 12:12:19 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FREE_H
# define FREE_H

#include "duckshell_structs.h"
#include "duckshell_globals.h"

void	free_cmd_list(t_cmd **cmd_list);
void	free_path_tab(char **path_tab);
void	*free_env_list(t_var *env_list);

#endif
