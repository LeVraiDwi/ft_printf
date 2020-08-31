/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:34:39 by tcosse            #+#    #+#             */
/*   Updated: 2020/08/31 17:28:02 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void ft_del(void *content)
{
	free(content);
	content = 0;
}

int	main(int argv, char **argc)
{
	char c;
	t_list *alst;

	(void)argv;
	if(!(ft_new_hexa(c, &alst, 1)))
		return (0);
	ft_display(alst);
	printf("\n%X\n", c);
	if(!(ft_new_hexa(c, &alst, 0)))
		return (0);
	ft_display(alst);
	printf("\n%x\n", c);
	ft_lstclear(&alst, &ft_del);
}
