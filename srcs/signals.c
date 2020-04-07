/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:54:50 by fhenrion          #+#    #+#             */
/*   Updated: 2020/04/07 11:33:13 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include "prompt.h"

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(STDOUT, CLEAR_KEYS, CLEAR_KEYS_LEN);
		write(STDOUT, PROMPT, PROMPT_LEN);
	}
	if (sig == SIGQUIT)
		write(STDOUT, CLEAR_KEYS, CLEAR_KEYS_LEN);
}

void	parent_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
}
