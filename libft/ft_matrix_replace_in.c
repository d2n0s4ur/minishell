/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_replace_in.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:37:02 by dongjlee          #+#    #+#             */
/*   Updated: 2023/01/02 01:24:49 by dongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_matrix_replace_in(char ***big, char **small, int number)
{
	char	**tmp;
	int		i[3];

	i[0] = -1;
	i[1] = -1;
	i[2] = -1;
	if (!big || !*big || number < 0 || number >= ft_matrixlen(*big))
		return (NULL);
	tmp = ft_calloc(ft_matrixlen(*big) + ft_matrixlen(small), sizeof(char *));
	while (tmp && big[0][++i[0]])
	{
		if (i[0] != number)
			tmp[++i[2]] = ft_strdup(big[0][i[0]]);
		else
		{
			while (small && small[++i[1]])
				tmp[++i[2]] = ft_strdup(small[i[1]]);
		}
	}
	ft_free_matrix(big);
	*big = tmp;
	return (*big);
}
