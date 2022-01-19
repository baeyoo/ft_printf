/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 11:46:59 by mobrycki          #+#    #+#             */
/*   Updated: 2021/02/20 11:47:03 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strshift(char *str, int shift)
{
	int		i;

	i = 0;
	if (!shift)
		return (str);
	if ((int)ft_strlen(str) <= shift)
	{
		str[0] = 0;
		return (str);
	}
	while (str[shift + i])
	{
		str[i] = str[shift + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_int_precision(char *ret, t_flags flags, int neg)
{
	char	*p;
	int		i;

	i = 0;
	if (!(p = ft_calloc(flags.precision + 1, 1)))
		return (NULL);
	if (flags.precision > -1)
	{
		while (flags.precision > (int)ft_strlen(ret))
		{
			p[i] = '0';
			i++;
			flags.precision--;
		}
		ret = ft_strjoin2(p, ret);
		if (neg == 1)
			ret = ft_strjoin("-", ret);
		flags.width = flags.width ? flags.width : flags.zero;
		if (flags.width > 0)
		{
			if (flags.width > flags.precision)
				ret = ft_int_width(ret, flags);
		}
	}
	return (ret);
}

char	*ft_int_width(char *ret, t_flags flags)
{
	char	*p;
	int		i;

	i = 0;
	if (!(p = ft_calloc(flags.width + 1, 1)))
		return (NULL);
	while (flags.width > (int)ft_strlen(ret))
	{
		p[i] = ' ';
		i++;
		flags.width--;
	}
	if (flags.minus > 0)
		ret = ft_strjoin1(ret, p);
	else
		ret = ft_strjoin(p, ret);
	free(p);
	return (ret);
}

char	*ft_int_zero(char *ret, t_flags flags, int neg)
{
	char	*p;
	int		i;

	i = 0;
	if (!(p = ft_calloc(flags.width + 1, 1)))
		return (NULL);
	if (flags.zero > 0)
	{
		while (flags.width > (int)ft_strlen(ret) + neg)
		{
			p[i] = '0';
			i++;
			flags.width--;
		}
		ret = ft_strjoin(p, ret);
	}
	if (neg == 1)
		ret = ft_strjoin("-", ret);
	free(p);
	return (ret);
}

char	*ft_integers(char *ret, t_flags flags)
{
	int neg;

	neg = (ret[0] == '-');
	if (flags.precision > -1)
	{
		if (neg || ret[0] == '0')
			ret = ft_strshift(ret, 1);
		ret = ft_int_precision(ret, flags, neg);
	}
	else if (flags.zero > 0 && !flags.minus)
	{
		if (neg)
			ret = ft_strshift(ret, 1);
		ret = ft_int_zero(ret, flags, neg);
	}
	else if (flags.width > 0)
		ret = ft_int_width(ret, flags);
	return (ret);
}
