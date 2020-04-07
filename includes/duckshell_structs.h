/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duckshell_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:24:01 by fhenrion          #+#    #+#             */
/*   Updated: 2020/04/07 11:07:32 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUCKSHELL_STRUCTS_H
# define DUCKSHELL_STRUCTS_H

# include <stdlib.h>

# define MAX_ARG_STRLEN 131072

typedef enum		e_dir
{
	NO_REDIR,
	IN,
	OUT,
	ADD
}					t_dir;

typedef struct		s_var
{
	struct s_var	*next;
	char			*key;
	char			*value;
}					t_var;

typedef struct		s_env
{
	char			**tab;
	char			**path;
	t_var			*list;
}					t_env;

typedef struct		s_arg
{
	struct s_arg	*next;
	t_dir			direction;
	char			value[MAX_ARG_STRLEN];
}					t_arg;

typedef struct		s_redir
{
	struct s_redir	*next;
	int				fd;
	int				std;
}					t_redir;

typedef struct		s_cmd
{
	struct s_cmd	*next;
	t_arg			*arg_lst;
	char			**argv;
	char			*path;
	t_redir			*redir_lst;
	int				pipe;
}					t_cmd;

#endif
