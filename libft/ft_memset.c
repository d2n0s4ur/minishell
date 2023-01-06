/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:39:27 by dongjlee          #+#    #+#             */
/*   Updated: 2022/03/13 18:32:03 by dongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	chr;
	unsigned char	*tmp_dest;
	size_t			i;

	i = 0;
	tmp_dest = dest;
	chr = c;
	while (i < n)
	{
		(*tmp_dest++) = chr;
		i++;
	}
	return (dest);
}
