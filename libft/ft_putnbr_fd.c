/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:23:03 by dongjlee          #+#    #+#             */
/*   Updated: 2022/07/09 14:43:25 by dongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	get_exp(unsigned int ori_num)
{
	int	exp;
	int	num_size;

	exp = 1;
	num_size = 1;
	while (ori_num >= 10)
	{
		ori_num /= 10;
		num_size++;
		exp *= 10;
	}
	return (exp);
}

void	put_text(unsigned int num, int num_size, int flag, int fd)
{
	char	result[15];
	int		i;
	int		minus;
	int		exp;

	i = 0;
	minus = '-';
	exp = get_exp(num);
	while (i < num_size)
	{
		result[i] = num / exp + '0';
		num = num % exp;
		exp /= 10;
		i++;
	}
	i = 0;
	if (flag == 1)
	{
		write(fd, &minus, 1);
	}
	while (i < num_size)
	{
		write(fd, &result[i], 1);
		i++;
	}
}

unsigned int	get_num_size_fd(unsigned int ori_num)
{
	int	exp;
	int	num_size;

	exp = 1;
	num_size = 1;
	while (ori_num >= 10)
	{
		ori_num /= 10;
		num_size++;
		exp *= 10;
	}
	exp--;
	return (num_size);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	new_nb;
	int				flag;

	if (n == -2147483648)
	{
		new_nb = 2147483648;
		flag = 1;
	}
	else if (n < 0)
	{
		new_nb = n * -1;
		flag = 1;
	}
	else
	{		
		new_nb = n;
		flag = 0;
	}
	put_text(new_nb, get_num_size_fd(new_nb), flag, fd);
}
