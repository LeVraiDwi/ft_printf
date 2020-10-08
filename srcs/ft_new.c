/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:12:29 by tcosse            #+#    #+#             */
/*   Updated: 2020/10/08 11:55:08 by tcosse           ###   ########.fr       */
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
	unsigned int	pr;
	unsigned int	l;

	pr = alst->precision;
	if (alst->flag & FLAG_S)
		return (ft_pr_string(alst, pr));
	else if (alst->flag & FLAG_P || (alst->flag & FLAG_D))
	{
		if (ft_atoi((char *)alst->content) == 0)
		{
			alst->content = ft_free(alst->content);
			if (!(alst->content = ft_strdup("")))
				return (0);
		}
		l = ft_strlen((char *)alst->content);
		if (alst->flag & FLAG_D && ((char *)alst->content)[0] == '-')
			l -= 1;
		if (pr > l)
			return (ft_pr_num(alst, pr, l));
	}
	return (1);
}

int	ft_format(t_list *alst)
{
	char	c;

	c = ft_zero_space(alst);
	if (alst->flag & FLAG_PR)
		if (!(ft_format_precision(alst)))
			return (0);
	if (alst->flag & FLAG_P && !(alst->flag & FLAG_Z))
		if (!(ft_insertstr(alst, 0, "0x")))
			return (0);
	if(!(ft_format_margin(alst)))
		return (0);
	if (alst->flag & FLAG_P && (alst->flag & FLAG_Z))
		if (!(ft_insertstr(alst, 0, "0x")))
			return (0);
	return (1);
}
