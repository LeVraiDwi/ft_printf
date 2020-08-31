/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:30:17 by tcosse            #+#    #+#             */
/*   Updated: 2020/08/07 08:47:18 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display(t_list *alst)
{
	while (alst)
	{
		write(1, alst->content, ft_strlen(alst->content));
		alst = alst->next;
	}
}
