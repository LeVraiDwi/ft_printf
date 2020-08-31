/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:34:39 by tcosse            #+#    #+#             */
/*   Updated: 2020/08/17 16:13:38 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void ft_del(void *content)
{
	content = 0;
}

int	main(int argv, char **argc)
{
	unsigned int c;
	t_list *alst;

	(void)argv;
	c = -23;
	if(!(ft_new_u_int(c, &alst)))
		return (0);
	ft_display(alst);
	printf("\n%u\n", c);
	ft_lstclear(&alst, &ft_del);
}
