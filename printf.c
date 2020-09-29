/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:26:30 by tcosse            #+#    #+#             */
/*   Updated: 2020/09/29 15:14:08 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf( const char *format, ...)
{
	va_list	lst_args;
	t_list	*alst;

	va_start(lst_args, format);
	if (!(alst = ft_creat_lst(format, lst_args)))
		return (0);
	va_end(lst_args);
	ft_display(alst);
	ft_lstclear(&alst, &ft_del);
	return (1);
}
