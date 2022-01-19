/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:15:53 by mobrycki          #+#    #+#             */
/*   Updated: 2021/01/18 14:57:52 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_numlen(int num)
{
	int		size;

	size = 0;
	while (num > 9)
	{
		num = num / 10;
		size++;
	}
	size++;
	return (size);
}

static char		*ft_fill_table(char *n_conv, int size, int num, int is_nega)
{
	n_conv[size] = '\0';
	while (size)
	{
		if (is_nega > 1)
		{
			n_conv[size - 1] = (((num % 10) + 1) + 48);
			is_nega = 1;
		}
		else
			n_conv[size - 1] = (num % 10) + 48;
		num = num / 10;
		size--;
	}
	return (n_conv);
}

char			*ft_itoa(int n)
{
	char	*num_conv;
	int		size;
	int		is_negative;

	is_negative = 0;
	if (n == -2147483648)
	{
		is_negative = 2;
		n++;
		n = n * -1;
	}
	else if (n < 0)
	{
		is_negative++;
		n = n * -1;
	}
	size = ft_numlen(n);
	if (is_negative)
		size++;
	if (!(num_conv = malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_fill_table(num_conv, size, n, is_negative);
	if (is_negative)
		num_conv[0] = '-';
	return (num_conv);
}
