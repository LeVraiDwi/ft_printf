/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:12:29 by tcosse            #+#    #+#             */
/*   Updated: 2020/10/06 15:48:31 by tcosse           ###   ########.fr       */
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
	if (alst->flag & FLAG_PE)
		return (1);
	else if (pr == 0 && !(alst->flag & FLAG_P))
		return (ft_pr_zero(alst));
	if (alst->flag & FLAG_S)
	{
		if (alst->flag & FLAG_PR)
			return (ft_pr_string(alst, pr));
		else
			return (1);
	}
	else if (alst->flag & FLAG_P)
		return (ft_pr_pointer(alst, pr));
	else
		return (ft_pr_num(alst, pr));
}

int	ft_format(t_list *alst)
{
	if (alst->flag & FLAG_PR)
		if (!(ft_format_precision(alst)))
			return (0);
	if (alst->flag & FLAG_M)
	{
		if (!(ft_addfront(alst, alst->margin, ' ')))
			return (0);
	}
	else
		if (!(ft_addback(alst, alst->margin, ft_zero_space(alst))))
			return (0);
	return (1);
}
