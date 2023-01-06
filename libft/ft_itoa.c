/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:32:49 by dongjlee          #+#    #+#             */
/*   Updated: 2022/12/29 17:45:12 by dongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_set_before_add(char before_arr[15], int n)
{
	int	pos;

	pos = 0;
	while (n / 10 != 0)
	{
		before_arr[pos++] = '0' + n % 10;
		n = n / 10;
	}
	before_arr[pos++] = '0' + n % 10;
	before_arr[pos] = '\0';
}

void	ft_check_minus(int *n, unsigned int *is_minus)
{
	if (*n < 0)
	{
		*n *= -1;
		*is_minus = 1;
	}
}

char	*ft_itoa(int n)
{
	char				before_arr[15];
	char				arr[15];
	unsigned int		pos;
	unsigned int		is_minus;

	is_minus = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	ft_check_minus(&n, &is_minus);
	ft_set_before_add(before_arr, n);
	pos = 0;
	if (is_minus == 1)
		arr[pos++] = '-';
	while (pos - is_minus < ft_strlen(before_arr))
	{
		arr[pos] = before_arr[ft_strlen(before_arr) - pos - 1 + is_minus];
		pos++;
	}
	arr[pos] = '\0';
	return (ft_strdup(arr));
}
