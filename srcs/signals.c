/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:54:50 by fhenrion          #+#    #+#             */
/*   Updated: 2020/03/09 11:35:02 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, CLEAR_KEYS, CLEAR_LEN);
		write(STDOUT_FILENO, PROMPT, PROMPT_LEN);
	}
	if (sig == SIGQUIT)
		write(STDOUT_FILENO, CLEAR_KEYS, CLEAR_LEN);
}

void	parent_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
}
