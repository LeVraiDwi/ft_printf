/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:03:24 by tcosse            #+#    #+#             */
/*   Updated: 2020/08/31 17:08:05 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_new_hexa(unsigned int nb, t_list **new, int upper)
{
	if (!(*new = ft_lstnew(ft_int_hexa(nb, upper))))
		return (0);
	return (1);
}
