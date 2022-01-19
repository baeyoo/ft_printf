/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:48:43 by mobrycki          #+#    #+#             */
/*   Updated: 2021/02/20 11:39:35 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	n;
	char	*s;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	n = ft_strlen(s1) + ft_strlen(s2);
	s = (char *)malloc(sizeof(char) * (n + 1));
	if (s)
	{
		ft_strlcpy(s, s1, n + 1);
		ft_strlcat(s, s2, n + 1);
	}
	free(s2);
	return (s);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	size_t	n;
	char	*s;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	n = ft_strlen(s1) + ft_strlen(s2);
	s = (char *)malloc(sizeof(char) * (n + 1));
	if (s)
	{
		ft_strlcpy(s, s1, n + 1);
		ft_strlcat(s, s2, n + 1);
	}
	free(s1);
	return (s);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	size_t	n;
	char	*s;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	n = ft_strlen(s1) + ft_strlen(s2);
	s = (char *)malloc(sizeof(char) * (n + 1));
	if (s)
	{
		ft_strlcpy(s, s1, n + 1);
		ft_strlcat(s, s2, n + 1);
	}
	free(s1);
	free(s2);
	return (s);
}
