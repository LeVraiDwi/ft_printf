/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 14:31:56 by tcosse            #+#    #+#             */
/*   Updated: 2020/09/29 16:59:38 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	main()
{
	char *c;

	c = "la bi";
	ft_printf("ft_print : qkjasf %-*i i %*..*s %-16.*s %.6i asf\n", 12, 14, 16, 16, "dsf", 12);
	printf("___print : qkjasf %-*i i %*..*s %-16.*s %.6i asf\n", 12, 14, 16, 16, "dsf", 12);
	ft_printf("ft_print: qkjasf %-*i  %-*s %.15p asf %% %-*.13%\n", 12, 13, 13, "dsf", c, 12);
	printf("___print: qkjasf %-*i  %-*s %.15p asf %% %-*.13%\n", 12, 13, 13, "dsf", c, 12);
	return (1);
}
