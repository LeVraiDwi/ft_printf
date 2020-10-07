/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:12:29 by tcosse            #+#    #+#             */
/*   Updated: 2020/10/07 18:47:49 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_precision(va_list lst_arg, t_list *alst, int i)
{
	char	*str;

	str = alst->content;
	if (!(alst->flag & FLAG_PR))
		alst->flag += FLAG_PR;
	i++;
	if (str[i] == '*')
	{
		alst->precision = va_arg(lst_arg, int);
		i++;
	}
	else
	{
		alst->precision = ft_atoi(str + i);
		while (str[i] && ft_isdigit(str[i]))
			i++;
	}
	return (i);
}

int	ft_margin(va_list lst_arg, t_list *alst, int i)
{
	char	*str;

	str = alst->content;
	if (str[i] == '*')
	{
		alst->margin = va_arg(lst_arg, int);
		i++;
	}
	else
	{
		alst->margin = ft_atoi(str + i);
		while (str[i] && ft_isdigit(str[i]))
			i++;
	}
	return (i);
}

int	ft_format_precision(t_list *alst)
{
	int	pr;

	pr = alst->precision;
	 if (alst->flag & FLAG_S)
		return (ft_pr_string(alst, pr));
	else if (alst->flag & FLAG_P || (alst->flag & FLAG_D))
		return (ft_pr_num(alst, pr));
	else
		return (1);
}

int	ft_format(t_list *alst)
{
	char	c;

	c = ft_zero_space(alst);
	if (alst->flag & FLAG_PR)
		if (!(ft_format_precision(alst)))
			return (0);
	if (alst->flag & FLAG_M)
	{
		if (!(ft_addfront(alst, alst->margin, c)))
			return (0);
	}
	else
		if (!(ft_addback(alst, alst->margin, c)))
			return (0);
	if (alst->flag & FLAG_P)
		if (!(ft_insertstr(alst, 0, "0x")))
			return (0);
	return (1);
}
