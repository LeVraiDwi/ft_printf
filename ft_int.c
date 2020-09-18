/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:20:51 by tcosse            #+#    #+#             */
/*   Updated: 2020/09/14 17:11:11 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_add_int(int nb, t_list **new)
{
	if (!(*new = ft_lstnew(ft_itoa(nb))))
		return (0);
	return (1);
}

int	ft_add_u_int(unsigned int nb, t_list **new)
{
	if (!(*new = ft_lstnew(ft_u_itoa(nb))))
		return (0);
	return (1);
}
