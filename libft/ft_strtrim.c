/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 00:10:40 by dongjlee          #+#    #+#             */
/*   Updated: 2022/12/29 17:44:10 by dongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char *set, char target)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == target)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	get_count_before(char *s1, char *set)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s1[i] != '\0')
	{
		if (is_in_set(set, s1[i]) == 1)
		{
			count++;
		}
		else
		{
			return (count);
		}
		i++;
	}
	return (count);
}

int	get_count_after(char *s1, char *set)
{
	int	i;
	int	count;

	i = ft_strlen(s1) - 1;
	count = 0;
	while (i >= 0)
	{
		if (is_in_set(set, s1[i]) == 1)
		{
			count++;
		}
		else
		{
			return (count);
		}
		i--;
	}
	return (count);
}

char	*ft_strtrim(char *s1, char *set)
{
	unsigned int		before;
	unsigned int		after;

	if (s1 == 0 || set == 0)
		return (0);
	before = get_count_before(s1, set);
	after = get_count_after(s1, set);
	if (ft_strlen(s1) == before && ft_strlen(s1) == after)
	{
		return (ft_strdup(""));
	}
	return (ft_substr(s1, before, ft_strlen(s1) - after - before));
}
