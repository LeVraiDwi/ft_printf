/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:34:39 by tcosse            #+#    #+#             */
/*   Updated: 2020/10/06 15:44:16 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_flag(char *format)
{
	int		l;
	int		i;

	l = 0;
	if (format[l] == '%')
	{
		l++;
		while (format[l])
		{
			i = 0;
			while (SPECIFIER[i])
				if (format[l] == SPECIFIER[i++])
					return (l + 1);
			l++;
		}
	}
	return (0);
}

int		ft_add_lst(va_list lst_arg, char **format, t_list **alst, int i)
{
	char	*tmp;
	t_list	*add_lst;
	int		l;

	l = ft_is_flag((*format) + i);
	tmp = *format;
	if (!(add_lst = ft_lstnew(ft_substr(*format, 0, i))))
		return (0);
	ft_lstadd_back(alst, add_lst);
	if (!(add_lst = ft_lstnew(ft_substr(*format, i, l))))
		return (0);
	ft_lstadd_back(alst, add_lst);
	if (!(*format = ft_substr(*format, i + l, ft_strlen(*format))))
		return (0);
	tmp = ft_free((void *)tmp);
	ft_flag(lst_arg, add_lst);
	ft_format(add_lst);
	return (1);
}

int		ft_split_args(va_list lst_arg, const char *format, t_list **alst)
{
	int		i;
	t_list	*add_lst;
	char	*str;

	if (!(str = ft_strdup(format)))
		return (0);
	i = 0;
	while (str[i++] != 0)
	{
		if ((ft_is_flag(str + i - 1)))
		{
			if (!(ft_add_lst(lst_arg, &str, alst, i - 1)))
				return (0);
			i = 0;
		}
	}
	if (*str)
	{
		if (!(add_lst = ft_lstnew(str)))
			return (0);
		ft_lstadd_back(alst, add_lst);
	}
	else
		str = ft_free(str);
	return (1);
}

t_list	*ft_creat_lst(const char *format, va_list lst_arg)
{
	t_list	*alst;

	alst = 0;
	if (!(ft_split_args(lst_arg, format, &alst)))
		return (0);
	return (alst);
}
