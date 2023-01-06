/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:25:05 by dongjlee          #+#    #+#             */
/*   Updated: 2022/10/31 14:54:36 by dongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_strcpy_t(char *dest, const char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strdup(char *s1)
{
	int		size;
	char	*dest;

	size = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (dest == 0)
		return (0);
	ft_strcpy_t(dest, s1, size);
	return (dest);
}
