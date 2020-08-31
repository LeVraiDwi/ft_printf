/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:03:24 by tcosse            #+#    #+#             */
/*   Updated: 2020/08/31 17:52:16 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_new_hexa(unsigned int nb, t_list **new, int upper)
{
	if (!(*new = ft_lstnew(ft_int_hexa(nb, upper))))
		return (0);
	return (1);
}

int	ft_new_pointer(void *p, t_list **new)
{
	if (!(*new = ft_lstnew(ft_pointer_hexa(p))))
		return (0);
	return (1);
}
