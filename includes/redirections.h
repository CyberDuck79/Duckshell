/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 20:34:56 by fhenrion          #+#    #+#             */
/*   Updated: 2020/03/09 20:36:45 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H

# include "duckshell_structs.h"
# include "duckshell_globals.h"

int		parse_redir(t_cmd *cmd_lst);
int		apply_redir(t_redir *redir_lst);

#endif
