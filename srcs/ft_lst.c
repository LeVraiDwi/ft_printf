/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:34:39 by tcosse            #+#    #+#             */
/*   Updated: 2020/10/21 12:25:15 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_flag(char *format)
{
	int		l;
	int		i;

	l = 0;
	if (format[l] == '%')
	{
		l++;
		while (format[l])
		{
			i = 0;
			while (SPECIFIER[i])
				if (format[l] == SPECIFIER[i++])
					return (l + 1);
			l++;
		}
	}
	return (0);
}

int	ft_print_format(const char *format, va_list lst_arg)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	if (l = ft_is_flag(format))
	{
		if ((i = ft_flag(format, lst_arg)) == -1)
			return (-1);
		return (i + ft_print_format(format + l, lst_arg));
	}
	else if (*format)
	{
		write(1, format, 1);
		return (1 + ft_print_format(format + 1, lst_arg));
	}
	else
		return (0);
}
