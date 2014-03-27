/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnizard <bnizard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 18:32:25 by eseveno           #+#    #+#             */
/*   Updated: 2014/03/27 19:30:37 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTSH_H
# define FTSH_H

# include <libft.h>
# include <structs.h>
# include <string.h>
# include <dirent.h>

# define BUFF_SIZE 4097

/*
**		42sh.c
*/

int		ft_strlen_2d(char **tab);
char	**ft_exit(t_info *my, char ***env);
char	**set_builtins(t_info *my, char ***env);
void	ft_exec_fork(t_info *my, char **env);
void	ft_int(int c);
int		ft_read(t_info *my, char ***env);
char	*ft_coppath(char *path, int i);
char	**ft_join(char **c, t_info *my);
char	**ft_sort(t_info *my, char ***env);
char	*ft_complete(char *env);
char	**ft_copyenv(t_info *my, char **env);
void	ft_freebuf(t_info *my);
void	ft_freearg(t_info *my);
void	ft_freeway(t_info *my);
void	ft_freeall(t_info *my);
int		ft_space_error(char *test);
int		ft_set_tree(t_tab **tab, char ***env);

/*
**		arg.c
*/

void	ft_trim_arg(char **arg);

/*
**		ft_cd.c
*/

char	*ft_othertilde(t_info *my, char **env);
char	*ft_tilde(char *newway, t_info *my, int arg, char **env);
void	ft_go(t_info *my, int i, int arg, char ***env);
void	ft_noarg(t_info *my, char ***env);
char	**ft_cd(t_info *my, char ***env);

/*
**		ft_check1.c
*/

char	*ft_quote(char c);
int		ft_is_op(char *str);
int		ft_pipe(char *str);
char	*ft_is_cmd(char *str, char **env);
char	*ft_is_arg(char *str);

/*
**		ft_check2.c
*/

int		ft_is_other(char c);
int		ft_op(char c);
char	*ft_is_builtin(char *str);
int		ft_is_log(char *str);

/*
**		ft_check_lexem.c
*/

int		ft_check_lexem2(t_data **lexem, int i);
int		ft_check_lexem(t_data **lexem);

/*
**		ft_data.c
*/

void	ft_put_node(t_stuff *st, char *arg);
void	ft_cpy_data(t_tab **tab, t_stuff *st);
void	ft_set_data(t_tab **tab, t_stuff *st);

/*
**		ft_echo.c
*/

char	backslash_char(char c);
int		*init_int_tab(void);
int		*find_options(t_info *my);
int		execute_option(t_info *my, int *arg, int max, char ***env);
int		ft_echo(t_info *my, char ***env);

/*
**		ft_echo_check_char.c
*/

int		check_env(char *s, char **env);
int		print_env_var(char *s, int i, char **env);
int		check_condition(char *s, int i, int value);
int		print_char(char *s, int i, int value);
void	echo_putstr(char *s, char ***env);

/*
**		ft_echo_convert.c
*/

int		ft_power(int value, int power);
char	*ft_strcpy2(char *s, int i);
int		convert_octal(char *s, int i);
int		tool_for_hexa(char c);
int		convert_hexa(char *s, int i);

/*
**		ft_env.c
*/

void	ft_free_env(char **env);
void	generate_env(char **ft_env);
int		ft_strlen_chr(char *line, int c);
char	**confirm_path(char **ft_env, char *path);
char	**modify_env(char **ft_env, char *path);
char	*ft_pathway(char **ft_env);
void	ft_strdel(char **as);
void	ft_env(t_info *my, char ***env);
char	*command_search(char *table, char *env);
void	ft_env5(char **arg, int i, int j, char **ft_env);
void	ft_env4(char *cmd, char **arg, int i, char **ft_env);
char	*ft_env3(char **ft_env, int j, char *arg, char *path);
void	ft_env2(t_info *my, char **ft_env, char *path, int i);
char	*ft_set_path(DIR *directory, char **pathway, int i, char *table);

/*
**		ft_env2.c
*/

char	**add_to_env(char **ft_env, char *path);
char	**cpy_env(char **ft_env);

/*
**		ft_env_errors.c
*/

void	ft_putchar_fd(char c, int fd);
void	ft_env_file_error(char *name);
void	ft_env_error(char *name);
char	*ft_strcat(char *s1, const char *s2);

/*
**		error.c
*/

int		ft_accesserror(char *newway, t_info *my);
void	ft_pwd_error(char ***env);

/*
**		ft_set_all.c
*/

int		ft_set_lexem(char *arg, t_stuff *st);

/*
**		ft_set_tab.c
*/

t_tab	**ft_set_tab(t_stuff *st);

/*
**		ft_set_type.c
*/

t_data	**ft_set_type(t_data **lexem, char **env);

/*
**		ft_setenv.c
*/

char	*ft_setenvchange(t_info *my, int k);
char	*ft_setenvcrea(char *env);
char	**ft_setenvcreate(char ***env, t_info *my, int k);
char	**ft_setenvupdate(t_info *my, int k, char ***env);
char	**ft_setenv(t_info *my, char ***env);

/*
**		ft_unsetenv.c
*/

char	**ft_unsetenv(t_info *my, char ***env);
void	ft_unset(t_info *my, char **env);

/*
**		minishell.c
*/

void	ft_free_tree(t_info *tree);

/*
**		parser.c
*/

t_tab	**ft_parser(char *arg, char **env);

/*
**		path.c
*/

char	*ft_find_path(char *str, char **env);

/*
**		ft_exit.c
*/

char	**ft_exit(t_info *my, char ***env);

/*
**		tree1.c
*/

void	ft_set_node(t_info *tree, t_tab **arg, int i);
void	ft_op_left(t_info *oldtree, int *fd, int *fd1);
void	ft_op_left_double(t_info *oldtree, int *fd, int *fd1);

/*
**		tree2.c
*/

t_info	*ft_set_info(t_info *tree, t_tab **arg, int i);
void	ft_exec_root(t_info *tree, char ***env);
void	ft_tree_root(t_info *tree, int *fd, int *fd1, char ***env);

/*
**		tree3.c
*/

int		ft_set_fd1(int fd, t_info *tree);
int		ft_set_fd2(int fd, t_info *tree);
int		ft_set_fd3(int fd, t_info *tree);
int		ft_set_fd(int fd, t_info *tree);
void	ft_close_fd(int *fd, int *fd1);

/*
**		tree.c
*/

t_info	*ft_init_info(void);
int		ft_ptrlen(char **ptr);
void	ft_free_tab(t_tab **tab);
char	**ft_search_tree(t_info *tree, t_info *oldtree, int *fd1, char ***env);
t_info	*ft_create_tree(t_tab **tab);

#endif
