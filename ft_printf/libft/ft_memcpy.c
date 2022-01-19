/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:22:37 by mobrycki          #+#    #+#             */
/*   Updated: 2021/01/15 12:44:33 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *a;
	char *b;

	if (!(dst) && !(src))
		return (NULL);
	a = (char *)src;
	b = (char *)dst;
	while (n--)
	{
		*b++ = *a++;
	}
	return (dst);
}
