/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:26:30 by tcosse            #+#    #+#             */
/*   Updated: 2020/10/07 18:15:51 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int	i;
	va_list	lst_args;
	t_list	*alst;

	va_start(lst_args, format);
	if (!(alst = ft_creat_lst(format, lst_args)))
		return (0);
	va_end(lst_args);
	i = ft_display(alst);
	ft_lstclear(&alst, &ft_del);
	return (i);
}
