/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:58:16 by dongjlee          #+#    #+#             */
/*   Updated: 2022/07/09 16:04:43 by dongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	char			target;
	int				i;

	target = c;
	i = ft_strlen(s);
	while (i != -1)
	{
		if (s[i] == target)
		{
			return ((char *)s + i);
		}
		i--;
	}
	return (0);
}
