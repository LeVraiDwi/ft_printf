/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 14:10:50 by tcosse            #+#    #+#             */
/*   Updated: 2020/10/08 12:06:29 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_pr_num(t_list *alst, int pr, int l)
{
	char	*str;
	char	*new;
	int		i;

	str = alst->content;
	if (!(new = (char *)malloc(sizeof(char) * (pr + 1))))
		return (0);
	i = 0;
	l = pr - l;
	if (alst->flag & FLAG_D && str[0] == '-')
		new[i++] = *str++;
	while (l--)
		new[i++] = '0';
	while (*str)
		new[i++] = *str++;
	new[i] = 0;
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
