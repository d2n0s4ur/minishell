/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:37:53 by dongjlee          #+#    #+#             */
/*   Updated: 2022/03/20 13:05:10 by dongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	check_start_sign(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' '
		|| str[i] == '\t'
		|| str[i] == '\n'
		|| str[i] == '\v'
		|| str[i] == '\f'
		|| str[i] == '\r')
	{
		i++;
	}
	return (i);
}

int	check_sign_ret_num_point(const char *str, int start_point, int *sign)
{
	int	i;
	int	minus;
	int	count;

	i = 0;
	count = 0;
	minus = 0;
	while (*(str + start_point + i) == '+'
		|| *(str + start_point + i) == '-')
	{
		count++;
		if (*(str + start_point + i) == '-')
		{
			minus++;
		}
		i++;
	}
	if (minus % 2 == 0)
		*sign = 0;
	else
		*sign = 1;
	if (count >= 2)
		*sign = -1;
	return (i + start_point);
}

int	get_num_size_atoi(const char *str, int num_start_point)
{
	int	i;

	i = 0;
	while (*(str + num_start_point + i) >= '0'
		&& *(str + num_start_point + i) <= '9')
	{
		i++;
	}
	return (i);
}

void	set_num(const char *str, int num_start_point
	, int num_size, unsigned long long *result)
{
	int	i;
	int	weight;

	i = 0;
	weight = 1;
	while (i < num_size)
	{
		*result += (*(str + num_start_point + num_size - i - 1) - '0') * weight;
		weight *= 10;
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int						sign_start_point;
	int						num_start_point;
	int						num_size;
	int						sign;
	unsigned long long		result;

	result = 0;
	sign_start_point = check_start_sign(str);
	num_start_point = check_sign_ret_num_point(str, sign_start_point, &sign);
	num_size = get_num_size_atoi(str, num_start_point);
	set_num(str, num_start_point, num_size, &result);
	if ((result > (unsigned long) LONG_MAX && sign == 1) || sign == -1)
		return (0);
	if (result > (unsigned long) LONG_MAX - 1 && sign == 0)
		return (-1);
	if (sign == 0)
		return (result);
	else
	{
		if (result == 2147483648)
			return (-2147483648);
		else
			return (result * -1);
	}
	return (0);
}
