/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:40:57 by mobrycki          #+#    #+#             */
/*   Updated: 2021/01/20 11:28:12 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check(char const *set, char c)
{
	int i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		else
			i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t i;
	size_t k;
	size_t len;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	if (ft_check(set, s1[0]))
	{
		while (ft_check(set, s1[i]) && s1[i] != '\0')
			i++;
	}
	k = ft_strlen(s1) - 1;
	if (ft_check(set, s1[k]))
	{
		while (k > i && ft_check(set, s1[k]))
			k--;
	}
	len = k - i + 1;
	return (ft_substr(s1, i, len));
}
