/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 11:44:39 by mobrycki          #+#    #+#             */
/*   Updated: 2021/02/20 11:45:32 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_spaces(char *str, t_flags flags)
{
	char	*spaces;
	int		i;

	spaces = NULL;
	if (!(spaces = malloc((flags.width - ft_strlen(str)) + 1)))
		return (NULL);
	i = 0;
	while ((size_t)flags.width-- > ft_strlen(str))
		spaces[i++] = ' ';
	spaces[i] = '\0';
	if (flags.minus)
		str = ft_strjoin1(str, spaces);
	else
		str = ft_strjoin(spaces, str);
	free(spaces);
	return (str);
}

char	*ft_char(char *ret, t_flags flags)
{
	char *p;

	if (*ret == '%' && flags.zero == 1 && flags.minus == 0)
		ret = ft_int_zero(ret, flags, 0);
	else if (flags.null == 1)
	{
		ret = ft_spaces(ret, flags);
		if (flags.minus)
			ft_putchar('\0');
		ft_putstr(&ret[1]);
		if (!flags.minus)
			ft_putchar('\0');
		if (!(ret[0] == 0))
			p = ft_strdup(&ret[1]);
		else
			p = ft_strdup("");
		free(ret);
		return (p);
	}
	else if (flags.width)
		ret = ft_spaces(ret, flags);
	return (ret);
}
