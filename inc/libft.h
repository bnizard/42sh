/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmellado <dmellado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 20:19:13 by dmellado          #+#    #+#             */
/*   Updated: 2014/03/26 19:19:43 by dmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

int			ft_atoi(const char *str);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
char		*ft_itoa(int n);
void		ft_putchar(char c);
void		ft_putendl(char *s);
void		ft_putstr(char *s);
char		*ft_strchr(const char *s, int c);
int			ft_space_error(char *test);
char		*ft_strchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *s1, const char *s2);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char *s);
char		*ft_strncat(char *dst, const char *src, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strncpy(char *s1, const char *s2, size_t n);
char		**ft_strsplit(char *s, char c);
char		*ft_strtrim(char const *s);

#endif
