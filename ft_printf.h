/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:20:55 by tcosse            #+#    #+#             */
/*   Updated: 2020/08/31 17:51:56 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_new_int(int i, t_list **alst);
int		ft_new_u_int(unsigned int i, t_list **alst);
int		ft_new_str(char *str, t_list **alst);
int		ft_new_char(char c, t_list **alst);
int		ft_new_hexa(unsigned int n, t_list **alst, int upper);
int		ft_new_pointer(void *p, t_list **alst);
void	ft_display(t_list *alst);
#endif
