/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:48:17 by mobrycki          #+#    #+#             */
/*   Updated: 2021/01/19 12:28:54 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_word(char const *s, char c)
{
	size_t i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			++i;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (i);
}

char			**ft_split(char const *s, char c)
{
	char	**ret;
	char	*from;
	size_t	i;
	size_t	size;

	if (!s || !(ret = (char**)malloc(sizeof(char*) * get_word(s, c) + 1)))
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			from = (char*)s;
			while (*s && *s != c)
				++s;
			size = s - from + 1;
			if (!(ret[i] = (char*)malloc(size)))
				return (0);
			ft_strlcpy(ret[i++], from, size);
		}
		else
			++s;
	}
	ret[i] = 0;
	return (ret);
}
