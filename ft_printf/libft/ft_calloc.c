/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:47:11 by mobrycki          #+#    #+#             */
/*   Updated: 2021/01/15 15:05:02 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*dst;
	unsigned int	tot;
	unsigned int	i;

	tot = count * size;
	if (!(dst = malloc(tot)))
		return (NULL);
	i = 0;
	while (tot--)
	{
		dst[i] = 0;
		i++;
	}
	return ((void *)dst);
}
