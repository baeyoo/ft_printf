/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:28:10 by mobrycki          #+#    #+#             */
/*   Updated: 2021/01/15 15:03:36 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	memspace;
	char	*s2;
	char	*res;

	memspace = ft_strlen(s1) + 1;
	s2 = (char *)malloc(memspace);
	if (s2 == NULL)
		return (NULL);
	if (!(res = (char *)ft_memcpy(s2, s1, memspace)))
	{
		free(s2);
		return (NULL);
	}
	return (res);
}
