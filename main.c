/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 14:31:56 by tcosse            #+#    #+#             */
/*   Updated: 2020/10/08 15:42:54 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main()
{
	char *str;
	char *str1;
	char *str2;
	char *str3;
	char *str4;

	str = "asd";
	str1 = "sdg";
	str2 = "asdgasdg";
	str3 = "asdgasdg";
	str4 = "asdgasdg";
	ft_printf("%*.*s\n", 5, -7, "LYDI");
	printf("|%*.*s|\n", 5, -7, "LYDI");
	return (1);
}
