/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:14:47 by mobrycki          #+#    #+#             */
/*   Updated: 2021/01/22 11:56:11 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (i < len && (start + i < ft_strlen(s)))
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}
