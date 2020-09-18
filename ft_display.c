/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:30:17 by tcosse            #+#    #+#             */
/*   Updated: 2020/09/16 14:21:29 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_display(t_list *alst)
{
	while (alst)
	{
		write(1, "bloc:\n", 6);
		write(1, alst->content, ft_strlen(alst->content));
		write(1, "\n", 1);
		printf("%i\n", alst->flag);
		alst = alst->next;
	}
}
