/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 18:32:25 by eseveno           #+#    #+#             */
/*   Updated: 2014/02/27 18:55:25 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __42SH_H__
# define __42SH_H__

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


# define BUFF_SIZE 4096 


typedef struct	s_info
{
	char		*buf;
	char		**env;
	char		**argv;
	int			ret;
}				t_info;

#endif
