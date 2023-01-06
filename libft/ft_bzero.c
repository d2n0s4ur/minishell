/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:58:57 by dongjlee          #+#    #+#             */
/*   Updated: 2022/03/13 18:29:11 by dongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp_dest;
	size_t			i;

	i = 0;
	tmp_dest = s;
	while (i < n)
	{
		(*tmp_dest++) = 0;
		i++;
	}
}
