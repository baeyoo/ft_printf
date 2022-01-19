/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 12:11:34 by mobrycki          #+#    #+#             */
/*   Updated: 2021/02/20 12:14:40 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_flags
{
	int zero;
	int precision;
	int width;
	int minus;
	int point;
	int star;
	int spec;
	int null;
}				t_flags;

void			ft_putchar(char c);
int				is_spec(const char ch);
int				ft_printf(const char *format, ...);
void			ft_struct_init(t_flags *flags);
int				ft_wombo_combo(const char **str, va_list args);
void			ft_flags_mod(const char **str, t_flags *flags, va_list args);
int				ft_precision(const char **str);
char			*ft_strdup(const char *s);
char			*conv_hexa(unsigned int n);
char			*conv_caphexa(unsigned int n);
char			*conv_add(size_t n);
void			ft_rev(char *tab);
char			*parse_spec(char c, va_list args, t_flags *flags);
void			ft_putstr(char *str);
char			*ft_uitoa(unsigned int n);
char			*ft_strshift(char *str, int shift);
char			*ft_int_precision(char *ret, t_flags flags, int neg);
char			*ft_int_width(char *ret, t_flags flags);
char			*ft_int_zero(char *ret, t_flags flags, int neg);
char			*ft_integers(char *ret, t_flags flags);
char			*ft_char(char *ret, t_flags flags);
void			ft_flags_mod_p(const char **str, t_flags *flags, va_list args);
char			*ft_spaces(char *str, t_flags flags);
char			*ft_char(char *ret, t_flags flags);
char			*ft_strings(char *ret, t_flags flags);
char			*ft_hexa_pr(char *ret, t_flags flags, int pointer);
char			*ft_hexa_zero(char *ret, t_flags flags, int pointer);
char			*ft_hexa(char *ret, t_flags flags, char c);

#endif
