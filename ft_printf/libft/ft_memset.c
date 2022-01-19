/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:46:29 by mobrycki          #+#    #+#             */
/*   Updated: 2021/01/15 12:16:04 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char *p;

	p = (unsigned char *)dest;
	while (len)
	{
		*p = c;
		p++;
		len--;
	}
	return (dest);
}
