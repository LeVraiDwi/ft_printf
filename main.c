/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:34:39 by tcosse            #+#    #+#             */
/*   Updated: 2020/08/31 18:10:46 by tcosse           ###   ########.fr       */
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
	int c = -1541351;
	t_list *alst;

	(void)argv;
	if(!(ft_new_pointer(c, &alst)))
		return (0);
	ft_display(alst);
	printf("\n%p\n", c);
	ft_lstclear(&alst, &ft_del);
}
