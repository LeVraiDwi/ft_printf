/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:20:51 by tcosse            #+#    #+#             */
/*   Updated: 2020/09/24 16:43:48 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_add_int(va_list lst_arg, t_list *alst)
{
	alst->flag += 16;
	alst->content = ft_free(alst->content);
	if (!(alst->content = ft_itoa(va_arg(lst_arg, int))))
		return (0);
	return (1);
}

int	ft_add_u_int(va_list lst_arg, t_list *alst)
{
	alst->flag += 512;
	alst->content = ft_free(alst->content);
	if (!(alst->content = ft_u_itoa(va_arg(lst_arg, unsigned int))))
		return (0);
	return (1);
}
