/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:34:04 by fhenrion          #+#    #+#             */
/*   Updated: 2020/04/07 11:29:14 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "duckshell_globals.h"
# include "duckshell_structs.h"

# define CLEAR_KEYS "\033[1C\b\b \b\b \b\b\033[1C"
# define CLEAR_KEYS_LEN 16
# define CLEAR_EOF "  \b\b"
# define CLEAR_EOF_LEN 4

void	signal_handler(int sig);
void	parent_handler(int sig);

#endif
