/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:59:40 by tcosse            #+#    #+#             */
/*   Updated: 2020/09/18 11:37:15 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_determine_specifier(char spe, t_list *alst)
{
	if (spe == 'd' || spe == 'i')
		alst->flag += 16;
	else if (spe == 'c')
		alst->flag += 64;
	else if (spe == 'x')
		alst->flag += 8;
	else if (spe == 'X')
		alst->flag += 1024;
	else if (spe == 's')
		alst->flag += 256;
	else if (spe == 'u')
		alst->flag += 512;
	else if (spe == '%')
		alst->flag += 128;
	else
		return (0);
	return (1);
}

int	ft_flag(va_list lst_arg, t_list *alst)
{
	int	i;

	i = 1;
	if (((char *)alst->content)[i] == '0' || ((char *)alst->content)[i] == '-')
	{
		if (((char *)alst->content)[i++] == '0')
			alst->flag += 2;
		else
			alst->flag += 4;
	}
	if (((char *)alst->content)[i] == '*')
	{
		if ((i = ft_addstr(alst, i + 1, ft_itoa(va_arg(lst_arg, int)))) == -1)
			return (0);
	}
	else
		while (ft_isdigit(((char *)alst->content)[i]))
			i++;
	if (((char *)alst->content)[i] == '.')
	{
		alst->flag += 1;
		i++;
	}
	if (((char *)alst->content)[i] == '*')
	{
		if ((i = ft_addstr(alst, i + 1, ft_itoa(va_arg(lst_arg, int)))) == -1)
			return (0);
	}
	else
		while (ft_isdigit(((char *)alst->content)[i]))
			i++;
	if (!ft_determine_specifier(((char *)alst->content)[i], alst))
		alst->flag = 0;
	return (1);
}
