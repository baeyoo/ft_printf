/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:02:23 by mobrycki          #+#    #+#             */
/*   Updated: 2021/01/18 12:49:49 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t i;

	i = 0;
	if (!dest || !src)
		return (0);
	if (size > 0)
	{
		while (src[i] != '\0' && i < size)
		{
			dest[i] = src[i];
			i++;
		}
		if (i == size)
			i--;
		dest[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}
