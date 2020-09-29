/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 14:31:56 by tcosse            #+#    #+#             */
/*   Updated: 2020/09/29 14:57:46 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	main()
{
	ft_printf("ft_print : qkjasf %-*i i %*..*s %-16.*s asf\n", 12, 14, 16, 16, "dsf");
	printf("print : qkjasf %-*i i %*..*s %-16.*s asf\n", 12, 14, 16, 16, "dsf");
	ft_printf("ft_print: qkjasf %-*i  %-*s %-12s asf\n", 12, 13, 13, "dsf", "ast");
	printf("print: qkjasf %-*i  %-*s %-12s asf\n", 12, 13, 13, "dsf", "ast");
	return (1);
}
