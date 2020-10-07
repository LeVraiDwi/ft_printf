/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:03:24 by tcosse            #+#    #+#             */
/*   Updated: 2020/10/07 15:52:37 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_add_hexa(va_list lst_arg, t_list *alst, int upper)
{
	alst->flag = 16;
	alst->content = ft_free(alst->content);
	if (!(alst->content = ft_int_hexa(va_arg(lst_arg, unsigned int), upper)))
		return (0);
	return (1);
}

int	ft_add_pointer(va_list lst_arg, t_list *alst)
{
	void *p;

	alst->flag += 32;
	alst->content = ft_free(alst->content);
	p = va_arg(lst_arg, void *);
	if (!(alst->content = ft_pointer_hexa(p)))
		return (0);
	return (1);
}

int	ft_pr_pointer(t_list *alst, int pr)
{
	char	*str;
	char	*new;
	int		l;
	int		i;

	str = alst->content;
	l = ft_strlen(str);
	if (pr <= l)
		return (1);
	if (!(new = (char *)malloc(sizeof(char) * (pr + 3))))
		return (0);
	i = 0;
	l = pr - (l - 2);
	new[i++] = *str++;
	new[i++] = *str++;
	while (l--)
		new[i++] = '0';
	while (*str)
		new[i++] = *str++;
	new[i] = 0;
	free(alst->content);
	alst->content = new;
	return (1);
}
