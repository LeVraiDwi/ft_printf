/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:20:51 by tcosse            #+#    #+#             */
/*   Updated: 2020/08/31 17:05:06 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_new_int(int nb, t_list **new)
{
	if (!(*new = ft_lstnew(ft_itoa(nb))))
		return (0);
	return (1);
}

int	ft_new_u_int(unsigned int nb, t_list **new)
{
	if (!(*new = ft_lstnew(ft_u_itoa(nb))))
		return (0);
	return (1);
}
