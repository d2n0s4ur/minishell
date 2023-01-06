/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:21:06 by dongjlee          #+#    #+#             */
/*   Updated: 2023/01/02 01:24:34 by dongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_matrix(char ***martix)
{
	int	i;

	i = 0;
	while (martix && martix[0] && martix[0][i])
	{
		free(martix[0][i]);
		i++;
	}
	if (martix)
	{
		free(martix[0]);
		*martix = NULL;
	}
}
