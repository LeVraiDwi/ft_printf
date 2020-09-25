/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_per.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 16:11:44 by tcosse            #+#    #+#             */
/*   Updated: 2020/09/24 16:41:16 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_add_per(t_list *alst)
{
	alst->flag += 128;
	alst->content = ft_free(alst->content);
	((char *)alst->content)[0] = '%';
	return (1);
}
