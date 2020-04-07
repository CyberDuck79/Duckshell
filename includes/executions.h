/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 20:37:57 by fhenrion          #+#    #+#             */
/*   Updated: 2020/04/07 10:30:04 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTIONS_H
# define EXECUTIONS_H

# include "duckshell_structs.h"
# include "duckshell_globals.h"

int		execute_cmds(t_cmd *cmd_lst, char **env);

#endif
