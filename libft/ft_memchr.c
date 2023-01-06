/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:11:57 by dongjlee          #+#    #+#             */
/*   Updated: 2022/03/13 18:31:43 by dongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	unsigned char			*new_s;
	unsigned char			target;

	new_s = (unsigned char *)s;
	target = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (new_s[i] == target)
		{
			return ((void *)s + i);
		}
		i++;
	}
	return (0);
}
