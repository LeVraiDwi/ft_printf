/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:26:30 by tcosse            #+#    #+#             */
/*   Updated: 2020/09/18 11:40:42 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prinft.h"

int	ft_printf(char *format, ...)
{
	va_list	lst_args;
	t_list	*alst;

	va_start(args, format);
	if (!(alst = ft_creat_lst(format)))
		return (0);
	if (!(ft_complet(alst, lst_args)))
		return (0);
	va_end(lst_args);
}
