/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:30:17 by tcosse            #+#    #+#             */
/*   Updated: 2020/10/13 16:03:37 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_display(t_list *alst)
{
	int				i;
	unsigned int	l;

	i = 0;
	while (alst)
	{
		l = ft_strlen((char *)alst->content);
		if (alst->precision == -1)
			l++;
		i += ft_strlen((char *)alst->content);
		write(1, alst->content, l);
		alst = alst->next;
	}
	return (i);
}
