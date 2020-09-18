/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:03:24 by tcosse            #+#    #+#             */
/*   Updated: 2020/09/14 17:11:31 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_add_hexa(unsigned int nb, t_list **new, int upper)
{
	if (!(*new = ft_lstnew(ft_int_hexa(nb, upper))))
		return (0);
	return (1);
}

int	ft_add_pointer(void *p, t_list **new)
{
	if (!(*new = ft_lstnew(ft_pointer_hexa(p))))
		return (0);
	return (1);
}
