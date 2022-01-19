/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 11:46:06 by mobrycki          #+#    #+#             */
/*   Updated: 2021/02/20 11:46:11 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_rev(char *tab)
{
	size_t	i;
	int		tmp;
	size_t	size;

	size = ft_strlen(tab);
	i = 0;
	while (i < size)
	{
		tmp = tab[i];
		tab[i] = tab[size - 1];
		tab[size - 1] = tmp;
		i++;
		size--;
	}
}

char	*conv_hexa(unsigned int n)
{
	int		i;
	int		resto;
	char	*rev_hexa;

	if (!(rev_hexa = ft_calloc(sizeof(char) * 9, 1)))
		return (0);
	i = 0;
	while (n > 0)
	{
		resto = n % 16;
		rev_hexa[i] = "0123456789abcdef"[resto];
		n = n / 16;
		i++;
	}
	ft_rev(rev_hexa);
	if (rev_hexa[0] == 0)
		rev_hexa[i] = '0';
	return (rev_hexa);
}

char	*conv_caphexa(unsigned int n)
{
	int		i;
	int		resto;
	char	*rev_hexa;

	if (!(rev_hexa = ft_calloc(sizeof(char) * 9, 1)))
		return (0);
	i = 0;
	while (n > 0)
	{
		resto = n % 16;
		rev_hexa[i] = "0123456789ABCDEF"[resto];
		n = n / 16;
		i++;
	}
	ft_rev(rev_hexa);
	if (rev_hexa[0] == 0)
		rev_hexa[i] = '0';
	return (rev_hexa);
}

char	*conv_add(size_t n)
{
	int		i;
	int		resto;
	char	*rev_hexa;

	if (!(rev_hexa = ft_calloc(sizeof(char) * 17, 1)))
		return (0);
	i = 0;
	while (n > 0)
	{
		resto = n % 16;
		rev_hexa[i] = "0123456789abcdef"[resto];
		n = n / 16;
		i++;
	}
	ft_rev(rev_hexa);
	if (rev_hexa[0] == 0)
		rev_hexa[i] = '0';
	return (rev_hexa);
}
