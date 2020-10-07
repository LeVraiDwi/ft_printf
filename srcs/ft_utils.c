/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 14:10:50 by tcosse            #+#    #+#             */
/*   Updated: 2020/10/07 16:20:46 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_addstr(t_list *alst, int start, char *add)
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
		(ft_strlen((char *)alst->content) + ft_strlen(add) - 1))))
		return (-1);
	while (start--)
		new[i++] = *(char *)alst->content++;
	i--;
	while (*add)
		new[i++] = *add++;
	while (*(char *)alst->content)
		new[i++] = *(char *)alst->content++;
	new[i] = 0;
	tmp = ft_free(tmp);
	alst->content = new;
	return (l - 1);
}

int	ft_zero_space(t_list *alst)
{
	if (!(alst->flag & FLAG_M))
	{
		if (!(alst->flag & FLAG_PR) || (alst->flag & FLAG_S))
			return ('0');
	}
	return (' ');
}

int	ft_addfront(t_list *alst, int n, char c)
{
	int		l;
	char	*str;
	int		i;

	i = 0;
	l = ft_strlen((char *)alst->content);
	if (alst->flag & FLAG_P)
		l += 2;
	if (n <= l)
		return (1);
	if (!(str = malloc(sizeof(char) * n + 1)))
		return (0);
	n = n - l;
	while (l--)
	{
		str[i] = ((char *)alst->content)[i];
		i++;
	}
	while (n--)
		str[i++] = c;
	str[i] = 0;
	free(alst->content);
	alst->content = str;
	return (1);
}

int	ft_addback(t_list *alst, int n, char c)
{
	int		l;
	char	*str;
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)alst->content;
	l = ft_strlen((char *)alst->content);
	if (alst->flag & FLAG_P)
		l += 2;
	if (n <= l)
		return (1);
	if (!(str = malloc(sizeof(char) * n + 1)))
		return (0);
	n = n - l;
	while (n--)
		str[i++] = c;
	while (l--)
		str[i++] = *tmp++;
	str[i] = 0;
	free(alst->content);
	alst->content = str;
	return (1);
}
