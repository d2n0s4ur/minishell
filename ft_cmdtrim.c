/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:11:13 by jnoh              #+#    #+#             */
/*   Updated: 2023/01/03 20:56:19 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_cmdtrim_cnt(const char *s, char *c)
{
	int	quote;
	int	ret;

	ret = 0;
	while (*s)
	{
		if (!ft_strchr(c, *s))
		{
			ret++;
			quote = 0;
			while (*s && (!ft_strchr(c, *s) || quote))
			{
				if (!quote && (*s == '\"' || *s == '\''))
					quote = *s;
				else if (quote == *s)
					quote = 0;
				s++;
			}
			if (quote)
				return (-1);
		}
		else
			s++;
	}
	return (ret);
}

static void	ft_cmdtrim_alloc(char **ret, char const *s, char *c, int idx)
{
	int		quote;
	char	*start;

	while (*s)
	{
		if (!ft_strchr(c, *s))
		{
			start = (char *)s;
			quote = 0;
			while (*s && (!ft_strchr(c, *s) || quote))
			{
				if (!quote && (*s == '\"' || *s == '\''))
					quote = *s;
				else if (quote == *s)
					quote = 0;
				s++;
			}
			if (ft_strchr(c, *s))
				ret[idx++] = ft_substr(start, 0, s - start);
			else
				ret[idx++] = ft_substr(start, 0, s - start + 1);
		}
		else
			s++;
	}
}

char	**ft_cmdtrim(char const *s, char *set)
{
	char	**ret;
	int		cnt;
	int		idx;

	idx = 0;
	if (!s)
		return (0);
	cnt = ft_cmdtrim_cnt(s, set);
	if (cnt == -1)
		return (0);
	ret = (char **)malloc((cnt + 1) * sizeof(char *));
	if (!ret)
		return (0);
	ft_cmdtrim_alloc(ret, s, set, idx);
	ret[cnt] = 0;
	return (ret);
}
