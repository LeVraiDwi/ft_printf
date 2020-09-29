/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:20:55 by tcosse            #+#    #+#             */
/*   Updated: 2020/09/29 16:29:27 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>
# define SPECIFIER "cspdiuxX%"
# define FLAG_PR 1
# define FLAG_Z 2
# define FLAG_M 4
# define FLAG_X 8
# define FLAG_D 16
# define FLAG_P 32
# define FLAG_C 64
# define FLAG_PE 128
# define FLAG_S 256
# define FLAG_U 512
# define FLAG_XX 1024

int		ft_new(va_list lst_arg, t_list *alst, char spe);
int		ft_margin(char *str);
int		ft_precision(char *str);
int		ft_printf(const char *format, ...);
int		ft_is_flag(char *format);
int		ft_add_lst(va_list lst_arg, char **format, t_list **alst, int i);
int		ft_split_args(va_list lst_arg, const char *format, t_list **alst);
int		ft_determine_specifier(va_list lst_arg, char spe, t_list *alst);
int		ft_determine_specifier_(va_list lst_arg, char spe, t_list *alst);
int		ft_addstr(t_list *alst, int start, char *add);
int		ft_insertstr(t_list *alst, int start, char *add);
int		ft_flag(va_list lst_arg, t_list *alst);
int		ft_if_precision(t_list *alst, int i);
int		ft_is_number(va_list lst_arg, t_list *alst, int i);
int		ft_add_int(va_list lst_arg, t_list *alst);
int		ft_add_u_int(va_list lst_arg, t_list *alst);
int		ft_add_str(va_list lst_arg, t_list *alst);
int		ft_add_char(va_list lst_arg, t_list *alst);
int		ft_add_hexa(va_list lst_arg, t_list *alst, int upper);
int		ft_add_per(t_list *alst);
int		ft_add_pointer(va_list lst_arg, t_list *alst);
int		ft_addback(t_list *alst, int n, char c);
int		ft_addfront(t_list *alst, int n, char c);
int		ft_zero_space(t_list *alst);
int		ft_pr_zero(t_list *alst);
int		ft_pr_num(t_list *alst, int pr);
int		ft_pr_string(t_list *alst, int pr);
int		ft_pr_pointer(t_list *alst, int pr);
int		ft_format_precision(t_list *alst, int pr);
char	ft_is_specifier(char c);
void	ft_del(void *content);
void	ft_display(t_list *alst);
t_list	*ft_creat_lst(const char *format, va_list lst_arg);
#endif
