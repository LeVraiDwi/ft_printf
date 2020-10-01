/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:21:56 by tcosse            #+#    #+#             */
/*   Updated: 2020/09/17 15:42:17 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list lst_arg, t_list *alst)
{
	while (alst)
	{
		if (alst->flag != 0)
		{
			if (((alst->flag) & FLAG_D) == 16)
				if (ft_new_int(lst_arg, alst))
					return (0);
		}
		alst = alst->next;
	}
	return (1);
}
