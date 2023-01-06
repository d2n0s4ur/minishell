/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 23:40:52 by dongjlee          #+#    #+#             */
/*   Updated: 2023/01/03 01:45:35 by dongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*ret;
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = 0;
	if (s == 0)
		return (0);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == 0)
		return (0);
	while (s[i] != '\0')
	{
		if (start <= i && len > j)
		{
			ret[j] = s[i];
			j++;
		}
		i++;
	}
	ret[j] = '\0';
	return (ret);
}
