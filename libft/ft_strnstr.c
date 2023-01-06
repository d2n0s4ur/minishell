/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:29:10 by dongjlee          #+#    #+#             */
/*   Updated: 2022/03/13 18:34:06 by dongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_size(const char *str)
{
	int	str_size;

	str_size = 0;
	while (*(str + str_size) != '\0')
	{
		str_size++;
	}
	return (str_size);
}

char	*do_find(const char *str \
				, const char *to_find \
				, size_t str_pos)
{
	size_t			to_find_pos;
	int				flag;

	flag = 1;
	to_find_pos = 0;
	while ((*(to_find + to_find_pos) != '\0'))
	{
		if (*(str + str_pos + to_find_pos) != *(to_find + to_find_pos))
		{
			flag = 0;
			to_find_pos++;
			break ;
		}
		to_find_pos++;
	}
	if (flag == 1)
	{
		return ((char *)str + str_pos);
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		str_size;
	int			to_find_size;
	size_t		str_pos;
	char		*find_return;

	str_size = 0;
	str_pos = 0;
	str_size = get_size(haystack);
	to_find_size = get_size(needle);
	if (to_find_size == 0)
		return ((char *)haystack);
	while (str_pos < str_size && (str_pos + to_find_size) <= len)
	{
		find_return = do_find(haystack, needle, str_pos);
		str_pos++;
		if ((find_return != 0) || *(needle) == '\0')
		{
			return (find_return);
		}
	}
	return (0);
}
