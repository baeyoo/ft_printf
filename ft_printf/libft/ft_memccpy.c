/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:23:51 by mobrycki          #+#    #+#             */
/*   Updated: 2021/01/15 16:44:52 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *a;
	unsigned char *b;

	a = (unsigned char *)src;
	b = (unsigned char *)dst;
	while (n-- > 0)
	{
		*b = *a;
		if (*a == (unsigned char)c)
			return ((void *)b + 1);
		a++;
		b++;
	}
	return (NULL);
}
