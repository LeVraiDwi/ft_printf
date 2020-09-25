/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:59:40 by tcosse            #+#    #+#             */
/*   Updated: 2020/09/25 15:59:46 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_determine_specifier(va_list lst_arg, char spe, t_list *alst)
{
	if (spe == 'd' || spe == 'i')
	{
		if (!(ft_add_int(lst_arg, alst)))
			return (0);
	}
	else if (spe == 'c')
	{
		if (!(ft_add_char(lst_arg, alst)))
			return (0);
	}
	else if (spe == 'x')
	{
		if (!(ft_add_hexa(lst_arg, alst, 0)))
			return (0);
	}
	else
	{
		return (ft_determine_specifier_(lst_arg, spe, alst));
	}
	return (1);
}

int	ft_determine_specifier_(va_list lst_arg, char spe, t_list *alst)
{
	if (spe == 's')
	{
		if (!(ft_add_str(lst_arg, alst)))
			return (0);
	}
	else if (spe == 'X')
	{
		if (!(ft_add_hexa(lst_arg, alst, 1)))
			return (0);
	}
	else if (spe == 'u')
	{
		if (!(ft_add_u_int(lst_arg, alst)))
			return (0);
	}
	else if (spe == '%')
	{
		if (!(ft_add_per(alst)))
			return (0);
	}
	else
		alst->flag = 0;
	return (1);
}

int	ft_is_number(va_list lst_arg, t_list *alst, int i)
{
	char	*tmp;

	if (((char *)alst->content)[i] == '*')
	{
		if (!(tmp = ft_itoa(va_arg(lst_arg, int))))
			return (0);
		if ((i = ft_addstr(alst, i + 1, tmp)) == -1)
			return (0);
		tmp = ft_free(tmp);
	}
	else if (!(ft_isdigit(((char *)alst->content)[i])))
	{
		if (!(ft_insertstr(alst, i, "0")))
			return (0);
		i++;
	}
	else
		while (ft_isdigit(((char *)alst->content)[i]))
			i++;
	return (i);
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
	i = ft_is_number(lst_arg, alst, i);
	if (((char *)alst->content)[i] == '.')
	{
		alst->flag += 1;
		i++;
		i = ft_is_number(lst_arg, alst, i);
	}
	if (!(ft_new(lst_arg, alst, ((char *)alst->content)[i])))
		return (0);
	return (1);
}
