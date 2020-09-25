/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:12:29 by tcosse            #+#    #+#             */
/*   Updated: 2020/09/19 16:50:24 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_precision(va_list lst_arg, char *str)
{
	while (*str && *str != '.')
		str++;
	if (!(*str))
		return (1);
	if (*str + 1 == '*')
		return (va_arg(lst_arg, int));
	else
		return (ft_atoi(str));
}

int	ft_margin(va_list lst_arg, char *str)
{
	if (*str == '0' || *str == '-')
		str++;
	if (*str == '*')
		return (va_arg(lst_arg, int));
	else
		return (ft_atoi(str));
}

int	ft_new(va_list lst_arg, t_list *alst, char c)
{
	int	margin;
	int	precision;

	margin = ft_margin(lst_arg, (char *)alst->content);
	if ((alst->flag & FLAG_PR) == 1)
		precision = ft_precision(lst_arg, (char *)alst->content);
	if (!(ft_determine_specifier(lst_arg, c, alst)))
		return (0);
	return (1);
}
