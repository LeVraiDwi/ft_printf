/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_per.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 16:11:44 by tcosse            #+#    #+#             */
/*   Updated: 2020/09/29 17:13:04 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_add_per(t_list *alst)
{
	char	*str;

	alst->flag = 128;
	alst->content = ft_free(alst->content);
	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (0);
	str[0] = '%';
	str[1] = 0;
	alst->content = str;
	return (1);
}
