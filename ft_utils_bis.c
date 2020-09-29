/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 14:10:50 by tcosse            #+#    #+#             */
/*   Updated: 2020/09/29 14:11:04 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_insertstr(t_list *alst, int start, char *add)
{
	int		l;
	char	*tmp;
	char	*new;
	int		i;

	if (!add || !alst->content)
		return (0);
	tmp = (char *)alst->content;
	l = ft_strlen(add) + start;
	i = 0;
	if (!(new = (char *)malloc(sizeof(char) *
		(ft_strlen((char *)alst->content) + ft_strlen(add)))))
		return (-1);
	while (start--)
		new[i++] = *(char *)alst->content++;
	while (*add)
		new[i++] = *add++;
	while (*(char *)alst->content)
		new[i++] = *(char *)alst->content++;
	new[i] = 0;
	tmp = ft_free(tmp);
	alst->content = new;
	return (l - 1);
}

int	ft_pr_zero(t_list *alst)
{
	if (alst->flag & FLAG_D || alst->flag & FLAG_S || alst->flag & FLAG_X || alst->flag & FLAG_U)
		if (!ft_atoi((char *)alst->content))
		{
			alst->content = ft_free(alst->content);
			if (!(alst->content = malloc(sizeof(char) * 1)))
				return (0);
			((char *)alst->content)[0] = 0;
		}
	return (1);
}

int	ft_pr_num(t_list *alst, int pr)
{
	char	*str;
	char	*new;
	int		l;
	int		i;

	str = alst->content;
	l = ft_strlen(str);
	if (pr <= l)
		return (1);
	if (!(new = (char *)malloc(sizeof(char) * (pr + 1))))
		return (0);
	i = 0;
	l = pr - l;
	if (alst->flag & FLAG_P)
	{
		new[i++] = '0';
		new[i++] = 'x';
		str += 2;
	}
	while (l--)
		new[i++] = '0';
	while (*str)
		new[i++] = *str++;
	free(alst->content);
	alst->content = new;
	return (1);
}

int	ft_pr_string(t_list *alst, int pr)
{
	char	*str;

	str = alst->content;
	if (!(alst->content = ft_substr(str, 0, pr)))
		return (0);
	str = ft_free(str);
	return (1);
}