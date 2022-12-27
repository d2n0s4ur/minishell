/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:29:15 by jnoh              #+#    #+#             */
/*   Updated: 2022/09/09 04:33:17 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_format(va_list ap, char format, int *status)
{
	int	result;

	if (format == '%')
		result = ft_putchar('%');
	if (format == 'c')
		result = ft_putchar(va_arg(ap, int));
	if (format == 's')
		result = ft_putstr(va_arg(ap, char *));
	if (format == 'p')
		result = ft_print_addr(va_arg(ap, void *));
	if (format == 'd' || format == 'i')
		result = ft_print_int(va_arg(ap, int));
	if (format == 'x')
		result = ft_print_small_hex(va_arg(ap, unsigned int));
	if (format == 'X')
		result = ft_print_big_hex(va_arg(ap, unsigned int));
	if (format == 'u')
		result = ft_print_unsigned_int(va_arg(ap, unsigned int));
	if (result == -1)
		*status = -1;
	return (result);
}

static int	ft_parse_format(va_list ap, char *format, int *status)
{
	int		result;
	int		write_size;

	result = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) != 0)
		{
			format++;
			result += ft_print_format(ap, *format, status);
			if (*status == -1)
				return (-1);
		}
		else
		{
			write_size = ft_putchar(*format);
			if (write_size == -1)
				return (-1);
			result += write_size;
		}
		format++;
	}
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		result;
	int		status;

	va_start(ap, format);
	status = 0;
	result = ft_parse_format(ap, (char *)format, &status);
	va_end(ap);
	if (status == -1)
		result = -1;
	return (result);
}
