/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:02:51 by dongjlee          #+#    #+#             */
/*   Updated: 2022/10/31 14:57:47 by dongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_seprate(const char str, char c)
{
	if (str == c || str == '\0')
		return (1);
	return (0);
}

int	get_word_count(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (ft_is_seprate(str[i], c) == 0
			&& (ft_is_seprate(str[i + 1], c) == 1 || str[i + 1] == '\0'))
		{
			count++;
		}
		i++;
	}
	return (count);
}

char	*ft_strdup_(const char *str, char c, int *start_point)
{
	char	*tmp_arr;
	int		i;
	int		j;

	i = *start_point;
	while (str[i] != '\0')
	{
		if (ft_is_seprate(str[i], c) == 0 && ft_is_seprate(str[i + 1], c) == 1)
		{
			i++;
			break ;
		}
		i++;
	}
	tmp_arr = malloc(sizeof(char) * (i - *start_point) + 1);
	if (tmp_arr == 0)
		exit(1);
	j = 0;
	while (*start_point < i)
	{
		tmp_arr[j++] = str[*start_point];
		*start_point += 1;
	}
	tmp_arr[j] = '\0';
	return (tmp_arr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		start_point;
	char	**arr;

	if (s == 0)
		return (0);
	start_point = 0;
	arr = malloc(sizeof(char *) * (get_word_count(s, c) + 1));
	if (arr == 0)
		return (0);
	i = 0;
	while (i < get_word_count(s, c))
	{
		while (ft_is_seprate(s[start_point], c) == 1)
		{
			start_point++;
		}
		arr[i] = ft_strdup_(s, c, &start_point);
		i++;
	}
	arr[i] = 0;
	return (arr);
}
