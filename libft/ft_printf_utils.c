/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 21:25:17 by jnoh              #+#    #+#             */
/*   Updated: 2022/09/09 04:33:25 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_small_hex(unsigned long long hex)
{
	int		result;
	int		write_size;

	result = 0;
	if (hex < 16)
		return (ft_putchar("0123456789abcdef"[hex]));
	else
	{
		write_size = ft_print_small_hex(hex / 16);
		if (write_size == -1)
			return (-1);
		result += write_size;
		write_size = ft_putchar("0123456789abcdef"[hex % 16]);
		if (write_size == 0)
			return (-1);
		result += write_size;
		return (result);
	}
}

int	ft_print_big_hex(unsigned long long hex)
{
	int		result;
	int		write_size;

	result = 0;
	if (hex < 16)
		return (ft_putchar("0123456789ABCDEF"[hex]));
	else
	{
		write_size = ft_print_big_hex(hex / 16);
		if (write_size == -1)
			return (-1);
		result += write_size;
		write_size = ft_putchar("0123456789ABCDEF"[hex % 16]);
		if (write_size == -1)
			return (-1);
		result += write_size;
		return (result);
	}
}

int	ft_print_addr(void *addr)
{
	int	result;

	result = ft_putstr("0x");
	if (result == -1)
		return (-1);
	result += ft_print_small_hex((unsigned long long)addr);
	if (result == 1)
		return (-1);
	return (result);
}

int	ft_print_int(int nb)
{
	int	result;
	int	write_size;

	result = 0;
	if (nb == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (nb == 0)
		return (ft_putchar('0'));
	else if (nb < 0)
	{
		result = ft_putchar('-');
		if (result == -1)
			return (-1);
		nb = nb * (-1);
	}
	write_size = ft_print_unsigned_int(nb);
	if (write_size == -1)
		return (-1);
	result += write_size;
	return (result);
}

int	ft_print_unsigned_int(unsigned int nb)
{
	int		result;
	int		write_size;

	result = 0;
	if (nb >= 10)
	{
		result = ft_print_unsigned_int(nb / 10);
		if (result == -1)
			return (-1);
		nb %= 10;
	}
	if (nb < 10)
	{
		write_size = ft_putchar(nb + '0');
		if (write_size == -1)
			return (-1);
		result += write_size;
	}
	return (result);
}
