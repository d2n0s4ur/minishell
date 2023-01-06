/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:30:17 by dongjlee          #+#    #+#             */
/*   Updated: 2022/03/13 18:31:32 by dongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;
	size_t			i;

	if (dst == 0 && src == 0)
		return (0);
	i = -1;
	new_dst = (unsigned char *)dst;
	new_src = (unsigned char *)src;
	if (new_dst < new_src)
	{
		while (++i < len)
		{
			new_dst[i] = new_src[i];
		}
	}
	else
	{
		while (++i < len)
		{
			new_dst[len - i - 1] = new_src[len - i - 1];
		}
	}
	return ((unsigned char *)dst);
}
