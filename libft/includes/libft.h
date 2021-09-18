/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:06:39 by ncoudsi           #+#    #+#             */
/*   Updated: 2021/09/18 16:20:59 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "libft_includes.h"

/*
** Prototypage des STRINGS.
*/

char			*ft_strnew(size_t p_len);
char			*ft_strdup(char *p_src);
char			*ft_strndup(const char *src, size_t n);
char			*ft_strdup_c(char p_c);
size_t			ft_strlen(char	*p_src);
size_t			ft_strnlen(const char *s, size_t maxlen);
size_t			ft_strlen_arg(char *p_str, char p_c);
char			*ft_strcpy(char *p_src, char *p_dest);
char			*ft_strsub(char *p_src, size_t p_start, size_t p_len);
char			*ft_strjoin(char *p_str1, char *p_str2);
char			*ft_strjoinfre(char *s1, char *s2, int free_s1, int free_s2);
char			*ft_strappend(char *s1, char *s2, int free_s1, int free_s2);
char			*ft_strprepend(char *s1, char *s2, int free_s1, int free_s2);
char			*ft_strstr(char *p_haystack, char *p_needle);
char			**ft_split(char *p_src, char p_sep);
void			ft_str_add_prefixe(char *p_prefixe, char **p_str);
void			ft_str_add_suffix(char **p_str, char *p_suffix);
int				ft_str_count_c(char *str, char c);
char			*ft_strnstr(char *haystack, char *needle, size_t len);
char			*ft_rm_charset(char *p_str, char *p_charset);
int				ft_count_charset(char *p_src, char p_c);

/*
** Prototypage des CHECKS.
*/

t_bool			ft_str_is_only_digit(char *str);
t_bool			ft_is_digit(char c);
int				ft_strcmp(char *p_src, char *p_target);
t_bool			ft_strcmp_c(char *p_src, char p_target);
t_bool			ft_str_is_only_whitespaces(char *str);
t_bool			ft_is_whitespaces(char p_c);
t_bool			ft_is_upper(char p_c);
t_bool			ft_is_lower(char p_c);
t_bool			ft_is_alpha(char p_c);
t_bool			ft_is_alpha_num(char p_c);
t_bool			ft_file_exist(char *p_path);
int				ft_strncmp(char *p_src, char *p_target, int len);

/*
** Prototypage des CONVERTS.
*/

float			ft_f_roof(float p_value);
int				ft_i_roof(float p_value);
float			ft_f_floor(float p_value);
float			ft_f_round(float p_value);
int				ft_i_abs(int p_value);
float			ft_f_abs(float p_value);
char			*ft_itoa_base(long long int nbr, char *base);
char			*ft_itoa(long long int nbr);
char			*ft_itoa_hexa(long long int nbr);
char			*ft_itoa_octa(long long int nbr);
char			*ft_itoa_unsigned_deci(unsigned int nbr);
long long		ft_atoi(char *p_str);
void			ft_swap_char(char *x, char *y);
void			ft_swap_int(int *x, int *y);

/*
** Prototypage des LISTS.
*/
/*
**	ft_lst_create_node cree un maillon
**	ft_lst_add_back ajoute un maillon a la fin
**	ft_lst_add_front ajoute un maillon au debut
**	ft_lst_clear supprime la liste
**	ft_lst_rm_data supprime la data d un maillon
**	ft_lst_iter applique une fonction sur tout la liste
**	ft_lst_map applique une foncton sur chaque maillon et retourne une liste
**	resultente des application ne supprime pas la premiere
**	ft_lst_size retourne la taille de la liste
**	ft_lst_rm_node supprime un maillon d une liste
*/

t_list			*ft_lst_create_node(void *p_data);
void			ft_lst_add_back(t_list **p_list, t_list *p_node);
void			ft_lst_add_front(t_list **p_list, t_list *p_node);
void			ft_lst_clear(t_list **lst, void (*del)(void*));
void			ft_lst_rm_data(t_list *lst, void (*del)(void*));
void			ft_lst_iter(t_list *lst, void (*f)(void*));
t_list			*ft_lst_map(t_list *lst, void *(*f)(void*), void (*del)(void*));
int				ft_lst_size(t_list *lst);
void			ft_lst_rm_node(t_list **lst, size_t num, void (*del)(void*));

/*
**	List inf de char
*/

typedef struct s_char_list
{
	char	**data;
	size_t	size;
}			t_char_list;

char			**ft_chartab_new(size_t nb);
t_char_list		create_char_list(size_t p_size);
t_char_list		*malloc_char_list(size_t p_push_size);
void			destroy_t_char_list(t_char_list to_delete);
void			free_t_char_list(t_char_list *to_free);
void			ft_chartab_cpy(char **old, char **new);
void			ft_char_list_push_back(t_char_list *list, char *to_add);

/*
** Prototypage des IO.
*/

unsigned long	ft_nbrlen(int nbr);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar(char c);
void			ft_putchar_fd(int fd, char c);
void			ft_putchar_fp(char *path, char c, char *mode);
void			ft_putstr(char *str);
void			ft_putstr_fd(int fd, char *str);
void			ft_putstr_fp(char *path, char *str, char *mode);
void			ft_putnbr(int nb);
void			ft_putnbr_fd(int fd, int nb);
void			ft_putnbr_fp(char *path, int nb, char *mode);
char			**ft_get_file(char *path);
void			ft_print_str_tab(char *p_name, char **p_tab);
void			ft_print_str_tab_fd(int fd, char *p_name, char **p_tab);
void			ft_print_str_tab_fp(char *path, char *p_name, char **p_tab,
					char *mode);
void			ft_print_int_tab(char *p_name, int *p_tab, size_t len);
void			ft_print_int_tab_fd(int fd, char *p_name, int *p_tab,
					size_t len);

/*
**	Prototypage des TABS.
*/

void			**ft_tab_new(int size);
int				ft_tab_len(void	**tab);
void			ft_free_tab(void **tab);
void			ft_tab_cpy(void **dst, void **src);
void			ft_add_to_tab(void *to_add, void ***tab);

#endif
