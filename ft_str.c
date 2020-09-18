/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 09:03:57 by tcosse            #+#    #+#             */
/*   Updated: 2020/09/14 17:11:55 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_add_str(char *str, t_list **new)
{
	if (!(*new = ft_lstnew(str)))
		return (0);
	return (1);
}

int	ft_add_char(char c, t_list **new)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (0);
	*str = c;
	str[1] = 0;
	if (!(*new = ft_lstnew(str)))
		return (0);
	return (1);
}
