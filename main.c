/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 14:31:56 by tcosse            #+#    #+#             */
/*   Updated: 2020/09/25 15:56:38 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	main()
{
	t_list	*alst;
	
	alst = ft_creat_lst("qkjasf %*i i %*..*s %16.*s asf\n", 12, 14, 16, 16, "dsf");
	ft_display(alst);
	printf("qkjasf %*i i %*..*s %16.*s asf\n", 12, 14, 16, 16, "dsf");
	ft_lstclear(&alst, &ft_del);
}
