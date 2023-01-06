/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:23:25 by dongjlee          #+#    #+#             */
/*   Updated: 2023/01/02 01:23:44 by dongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_dup_matrix(char **matrix)
{
	char	**result;
	int		i;

	result = malloc(sizeof(char *) * (ft_matrixlen(matrix) + 1));
	if (result == 0)
		return (NULL);
	i = 0;
	while (matrix[i])
	{
		result[i] = ft_strdup(matrix[i]);
		if (result[i] == 0)
		{
			ft_free_matrix(&result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
