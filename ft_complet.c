/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:59:40 by tcosse            #+#    #+#             */
/*   Updated: 2020/09/18 12:12:49 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_determine_specifier(t_list *alst)
{
	if (spe == 'd' || spe == 'i')
		alst->flag += 16;
	else if (spe == 'c')
		alst->flag += 64;
	else if (spe == 'x')
		alst->flag += 8;
	else if (spe == 'X')
		alst->flag += 1024;
	else if (spe == 's')
		alst->flag += 256;
	else if (spe == 'u')
		alst->flag += 512;
	else if (spe == '%')
		alst->flag += 128;
	else
		return (0);
	return (1);
}

int		ft_if_precision(t_list *alst, int i)
{
	if ((char *)(alst->content)[i] == '.')
	{
		alst->flag += 1;
		i++;
		if ((char *)(alst->content)[i] == '*')
			i++;
		else
			while (ft_isdigit((char *)(alst->content)[i]))
				i++;
	}
	return (i);
}

void	ft_flag(t_list *alst)
{
	int		i;

	i = 1;
	if ((char *)(alst->content)[i] == '0' || (char *)(alst->content)[i] == '-')
	{
		if ((char *)(alst->content)[i++] == '0')
			alst->flag += 2;
		else
			alst->flag += 4;
	}
	if ((char *)(alst->content)[i] == '*')
		i++;
	else
		while (ft_isdigit((char *)(alst->content)[i]))
			i++;
	i = ft_if_precision(alst, i);
	if (!ft_determine_specifier((char *)alst->content[i]), *alst)
		(*alst)->flag = 0;
}
