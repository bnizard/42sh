/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmellado <dmellado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 20:12:27 by dmellado          #+#    #+#             */
/*   Updated: 2014/03/26 20:14:03 by dmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct			s_env
{
	char				*name;
	char				*value;
}						t_env;

typedef struct			s_tab
{
	char				**data;
	int					type;
	int					nb;
}						t_tab;

typedef struct			s_data
{
	char				*data;
	int					type;
	int					nb;
}						t_data;

typedef struct			s_info
{
	char				*buf;
	char				*realbuf;
	char				**env;
	char				**arg;
	int					ret;
	char				**way;
	char				*oldway;
	int					envcpy;
	struct s_info		*left;
	struct s_info		*right;
	struct s_info		*root;
	int					type;
}						t_info;

typedef struct			s_stuff
{
	t_data				**lexem;
	int					l;
	int					k;
	int					j;
	int					i;
	int					n;
	char				*m;
}						t_stuff;

typedef char			**(*t_builts)(t_info *i, char ***);

typedef struct			s_builtins
{
	char				*name;
	t_builts			fnt;
}						t_builtins;

#endif
