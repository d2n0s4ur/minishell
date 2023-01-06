/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:12:15 by dongjlee          #+#    #+#             */
/*   Updated: 2022/07/09 16:04:15 by dongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	dest_size;
	int		src_size;
	size_t	src_pos;

	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	src_pos = 0;
	if (size < dest_size)
	{
		return (size + src_size);
	}
	while ((*(src + src_pos) != '\0')
		&& (src_pos + 1 + dest_size < size))
	{
		*(dest + dest_size + src_pos) = *(src + src_pos);
		src_pos++;
	}
	*(dest + dest_size + src_pos) = '\0';
	return (dest_size + src_size);
}
