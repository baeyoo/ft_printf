/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 11:49:14 by mobrycki          #+#    #+#             */
/*   Updated: 2021/02/20 11:49:20 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_struct_init(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->precision = -1;
	flags->width = 0;
	flags->spec = 0;
	flags->null = 0;
}

void	ft_flags_mod_p(const char **str, t_flags *flags, va_list args)
{
	flags->point = 1;
	if ('0' <= str[0][1] && str[0][1] <= '9')
	{
		(*str)++;
		flags->precision = ft_precision(str);
	}
	else if (str[0][1] == '*')
	{
		flags->precision = va_arg(args, int);
		(*str)++;
	}
	else if (is_spec(str[0][1]))
		flags->precision = 0;
}

void	ft_flags_mod(const char **str, t_flags *flags, va_list args)
{
	while (!(is_spec(**str)))
	{
		if (**str == '-')
			flags->minus = 1;
		else if (**str == '0')
			flags->zero = 1;
		else if (('1' <= **str && **str <= '9') || **str == '*')
		{
			if (**str == '*')
				flags->width = va_arg(args, int);
			else
				flags->width = ft_precision(str);
			if (flags->width < 0)
			{
				flags->width = -flags->width;
				flags->minus = 1;
			}
		}
		else if (**str == '*')
			flags->star = 1;
		else if (**str == '.')
			ft_flags_mod_p(str, flags, args);
		(*str)++;
	}
}

int		ft_wombo_combo(const char **str, va_list args)
{
	t_flags flags;
	int		dim;
	char	*ret;

	ft_struct_init(&flags);
	ft_flags_mod(str, &flags, args);
	ret = parse_spec(**str, args, &flags);
	if (**str == 'i' || **str == 'd' || **str == 'u' ||
			**str == 'x' || **str == 'X')
		ret = ft_integers(ret, flags);
	else if (**str == 'c' || **str == '%')
		ret = ft_char(ret, flags);
	else if (**str == 's')
		ret = ft_strings(ret, flags);
	else if (**str == 'p')
		ret = ft_hexa(ret, flags, **str);
	if (flags.null == 0)
		ft_putstr(ret);
	dim = ft_strlen(ret) + flags.null;
	if (ret)
		free(ret);
	return (dim);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	va_list		copy;
	int			prov_count;

	prov_count = 0;
	va_start(args, format);
	va_copy(copy, args);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			prov_count++;
		}
		else
		{
			format++;
			prov_count += ft_wombo_combo(&format, args);
		}
		format++;
	}
	va_end(copy);
	return (prov_count);
}
