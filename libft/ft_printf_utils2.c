/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 20:39:08 by jnoh              #+#    #+#             */
/*   Updated: 2022/09/09 04:33:24 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putchar(int c)
{
	int	write_size;

	write_size = write(1, &c, 1);
	return (write_size);
}

int	ft_putstr(char *str)
{
	int	result;
	int	write_size;

	if (!str)
	{
		write_size = write(1, "(null)", 6);
		if (write_size < 0)
			return (-1);
		return (write_size);
	}
	result = 0;
	while (*str)
	{
		write_size = ft_putchar(*(str++));
		if (write_size < 0)
			return (-1);
		result += write_size;
	}
	return (result);
}
