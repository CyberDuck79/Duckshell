/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:38:54 by fhenrion          #+#    #+#             */
/*   Updated: 2020/04/07 10:22:05 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "duckshell_structs.h"
# include "duckshell_globals.h"

int		parse_cmds(char line[ARG_MAX], t_cmd **cmd, char **env_path);

#endif
