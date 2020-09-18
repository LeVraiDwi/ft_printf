/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:12:29 by tcosse            #+#    #+#             */
/*   Updated: 2020/09/18 11:13:26 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_precision(va_list lst_arg, t_list *alst)
{
	while (*(char*)alst->content && *(char *)alst->content != '.')
		alst->content += 1;
	if (*(char *)alst->content + 1 == '*')
		return (va_arg(lst_arg, int));
	else
		return(ft_atoi(((char *)alst->content)));
}

int	ft_margin(va_list lst_arg, t_list *alst)
{
	if(*(char *)alst->content == '0' || *(char *)alst->content == '-'	)
		(char *)alst->content++;
	if (*(char *)alst->content == '*')
		return (va_arg(lst_arg, int));
	else
		return(ft_atoi(((char *)alst->content)));
	
}

int	ft_replace(va_list lst_arg, t_list *alst)
{
	while (*(char *)alst->content)
	{
		if(*(char *)alst->content == '*')
	}
}

int	ft_new_int(va_list lst_arg, t_list *alst)
{
	int	margin;
	int	precision;

	(char *)alst->content++;
	margin = ft_margin(lst_arg, alst);
	if ((alst->flag & FLAG_PR) == 1)
		precision = ft_precision(lst_arg, alst);
	if ((alst->flag & FLAG_PR) == 1 && (alst->flag & FLAG_Z))
}
