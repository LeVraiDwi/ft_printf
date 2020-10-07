/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:30:17 by tcosse            #+#    #+#             */
/*   Updated: 2020/10/07 19:08:23 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_display(t_list *alst)
{
	int	i;
	
	i = 0;
	while (alst)
	{
		i += ft_strlen((char *)alst->content);
		write(1, alst->content, ft_strlen(alst->content));
		alst = alst->next;
	}
	return (i);
}
