/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:05:01 by dongjlee          #+#    #+#             */
/*   Updated: 2022/03/13 18:31:35 by dongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t					i;
	unsigned char			*new_dst;
	unsigned char			*new_src;

	if (dst == 0 && src == 0)
	{
		return (0);
	}
	new_dst = (unsigned char *)dst;
	new_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		new_dst[i] = new_src[i];
		i++;
	}
	return (dst);
}
