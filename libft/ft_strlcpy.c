/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:31:11 by dongjlee          #+#    #+#             */
/*   Updated: 2022/03/13 18:33:39 by dongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_size_cpy(char *src)
{
	int	i;

	i = 0;
	while ((*(src + i) != '\0'))
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	while ((*(src + i) != '\0') && (i + 1 < size))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	if (size >= 1)
	{
		*(dest + i) = '\0';
	}
	return (get_size_cpy(src));
}
