/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 14:31:56 by tcosse            #+#    #+#             */
/*   Updated: 2020/10/08 12:44:08 by tcosse           ###   ########.fr       */
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

	str = "asdgasdg";
	str1 = "asdgasdg";
	str2 = "asdgasdg";
	str3 = "asdgasdg";
	str4 = "asdgasdg";

	ft_printf("ft_print : %-70p \n", str, str1, str2, str3, str4);
	printf("___print : %-70p%-70p%-70p%-70p%-70p\n", str, str1, str2, str3, str4);
	return (1);
}
