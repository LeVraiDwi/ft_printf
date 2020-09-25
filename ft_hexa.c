/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:03:24 by tcosse            #+#    #+#             */
/*   Updated: 2020/09/24 16:43:29 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_add_hexa(va_list lst_arg, t_list *alst, int upper)
{
	alst->flag = 8;
	alst->content = ft_free(alst->content);
	if (!(alst->content = ft_int_hexa(va_arg(lst_arg, unsigned int), upper)))
		return (0);
	return (1);
}

int	ft_add_pointer(va_list lst_arg, t_list *alst)
{
	alst->flag = 8;
	alst->content = ft_free(alst->content);
	if (!(alst->content = ft_pointer_hexa(va_arg(lst_arg, void *))))
		return (0);
	return (1);
}
