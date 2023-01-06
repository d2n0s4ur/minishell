/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmatrix_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:28:44 by dongjlee          #+#    #+#             */
/*   Updated: 2023/01/02 01:25:28 by dongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putmatrix_fd(char **matrix, int nl, int fd)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (matrix && matrix[i])
	{
		if (nl)
			count += ft_putendl_fd(matrix[i], fd);
		else
			count += ft_putstr_fd(matrix[i], fd);
		i++;
	}
	return (count);
}
