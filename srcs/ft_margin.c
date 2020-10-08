/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_margin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:59:49 by tcosse            #+#    #+#             */
/*   Updated: 2020/10/08 15:53:54 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_margin(t_list *alst)
{
	unsigned int	l;

	l = ft_strlen((char *)alst->content);
	if (alst->flag & FLAG_P && alst->flag & FLAG_Z && !(alst->flag & FLAG_PR))
		l += 2;
	if (alst->margin > l)
	{
		if (alst->flag & FLAG_M)
		{
			if (!(ft_addfront(alst, alst->margin, ' ')))
				return (0);
		}
		else if (!(ft_addback(alst, alst->margin, l, ft_zero_space(alst))))
			return (0);
	}
	return (1);
}
