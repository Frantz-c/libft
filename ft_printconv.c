/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printconv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 12:16:54 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 14:43:31 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

typedef void	(*t_conversion)(t_buffer *, t_format *, va_list);

static t_conversion	g_format_table[58] =
{
	NULL, NULL, NULL, NULL, &ft_print_sci,
	NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, &ft_print_hex, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, &ft_print_bin, &ft_print_chr, &ft_print_int, &ft_print_sci,
	&ft_print_flt, NULL, NULL, &ft_print_int, NULL,
	NULL, NULL, NULL, &ft_print_npt, &ft_print_oct,
	&ft_print_hex, NULL, NULL, &ft_print_str, NULL,
	&ft_print_uns, NULL, NULL, &ft_print_hex, NULL, NULL
};

static int	get_flags(const char **fmt)
{
	int		flags;

	flags = 0;
	while (1)
	{
		if (**fmt == '0')
			flags |= PF_ZERO;
		else if (**fmt == '+')
			flags |= PF_PLUS;
		else if (**fmt == '-')
			flags |= PF_MINUS;
		else if (**fmt == ' ')
			flags |= PF_SPACE;
		else if (**fmt == '#')
			flags |= PF_SHARP;
		else
			break ;
		(*fmt)++;
	}
	return (flags);
}

static int	get_width(const char **fmt)
{
	int		width;

	width = 0;
	while (**fmt >= '0' && **fmt <= '9')
	{
		width *= 10;
		width += **fmt;
		width -= '0';
		(*fmt)++;
	}
	return (width);
}

static int	get_precision(const char **fmt, int *flags)
{
	int		precision;

	precision = 0;
	if (**fmt != '.')
		return (precision);
	(*fmt)++;
	*flags |= PF_PRECISION;
	while (**fmt >= '0' && **fmt <= '9')
	{
		precision *= 10;
		precision += **fmt;
		precision -= '0';
		(*fmt)++;
	}
	return (precision);
}

static int	get_length(const char **fmt)
{
	int		length;

	length = 0;
	while (1)
	{
		if (**fmt == 'h')
			length |= (length & PF_SHORT) ? PF_CHAR : PF_SHORT;
		else if (**fmt == 'l' || **fmt == 'j' || **fmt == 'z')
			length |= PF_LONG;
		else if (**fmt == 'L')
			length |= PF_LDOUBLE;
		else
			break ;
		(*fmt)++;
	}
	return (length);
}

char		*ft_printconv(t_buffer *buffer, const char *fmt, va_list ap)
{
	t_format	info;

	fmt++;
	info.flags = get_flags(&fmt);
	info.width = get_width(&fmt);
	info.precision = get_precision(&fmt, &(info.flags));
	info.flags |= get_length(&fmt);
	info.specifier = (int)*fmt;
	fmt += (*fmt != '\0');
	ft_clean_format(&info);
	if (info.specifier < 'A' || info.specifier > 'z' ||
		g_format_table[info.specifier - 'A'] == NULL)
	{
		buffer->next_data = (char *)malloc(2);
		buffer->next_data[0] = info.specifier;
		buffer->next_data[1] = '\0';
	}
	else
		g_format_table[info.specifier - 'A'](buffer, &info, ap);
	ft_apply_width(buffer, &info);
	return ((char *)fmt);
}
