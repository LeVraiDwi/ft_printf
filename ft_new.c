/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:12:29 by tcosse            #+#    #+#             */
/*   Updated: 2020/09/29 15:02:55 by tcosse           ###   ########.fr       */
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
	str++;
	if (*str == '0' || *str == '-')
		str++;
	if (*str == '*')
		return (va_arg(lst_arg, int));
	else
		return (ft_atoi(str));
}

int	ft_format_precision(t_list *alst, int pr)
{
	if (pr == 0 && !(alst->flag & FLAG_P))
		return (ft_pr_zero(alst));
	if (alst->flag & FLAG_S)
			return (ft_pr_string(alst, pr));
	else
		return (ft_pr_num(alst, pr));
}

int	ft_new(va_list lst_arg, t_list *alst, char c)
{
	int	margin;
//	int	precision;

	margin = ft_margin(lst_arg, (char *)alst->content);
//	precision = 1;
//	if ((alst->flag & FLAG_PR) == 1)
//		precision = ft_precision(lst_arg, (char *)alst->content);
	if (!(ft_determine_specifier(lst_arg, c, alst)))
		return (0);
//	if (!(ft_format_precision(alst, precision)))
//		return (0);
//	if (alst->flag & FLAG_M && alst->flag != 0)
//	{
//		if (!(ft_addfront(alst, margin, ft_zero_space(alst))))
//			return (0);
//	}
//	else if (alst->flag != 0)
//		if (!(ft_addback(alst, margin, ft_zero_space(alst))))
//			return (0);
	return (1);
}
