/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:26:30 by tcosse            #+#    #+#             */
/*   Updated: 2020/10/21 11:46:05 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	lst_arg;

	va_start(lst_arg, format);
	if (!(ft_creat_lst(format, lst_arg)))
		return (-1);
	va_end(lst_args);
	return (i);
}
