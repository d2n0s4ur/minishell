/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdsubsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:46:06 by jnoh              #+#    #+#             */
/*   Updated: 2023/01/03 20:45:38 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_skip_quote(const char **s, char **c)
{
	int	quote;

	quote = 0;
	while (**s && (!ft_strchr(*c, **s) || quote))
	{
		if (!quote && (**s == '\"' || **s == '\''))
			quote = **s;
		else if (quote == **s)
			quote = 0;
		(*s)++;
	}
	return (quote);
}

static int	ft_cmdsubsplit_cnt(const char *s, char *c)
{
	int	quote;
	int	ret;

	ret = 0;
	while (*s)
	{
		if (!ft_strchr(c, *s))
		{
			quote = ft_skip_quote(&s, &c);
			if (quote)
				return (-1);
		}
		else
			s++;
		ret++;
	}
	return (ret);
}

static void	ft_cmdsubsplit_alloc(char **ret, char const *s, char *c, int idx)
{
	char	*start;

	while (*s)
	{
		if (!ft_strchr(c, *s))
		{
			start = (char *)s;
			ft_skip_quote(&s, &c);
			if (ft_strchr(c, *s))
				ret[idx++] = ft_substr(start, 0, s - start);
			else
				ret[idx++] = ft_substr(start, 0, s - start + 1);
		}
		else
		{
			ret[idx++] = ft_substr(s, 0, 1);
			s++;
		}
	}
}

char	**ft_cmdsubsplit(char const *s, char *set)
{
	char	**ret;
	int		cnt;
	int		idx;

	idx = 0;
	if (!s)
		return (0);
	cnt = ft_cmdsubsplit_cnt(s, set);
	if (cnt == -1)
		return (0);
	ret = (char **)malloc((cnt + 1) * sizeof(char *));
	if (!ret)
		return (0);
	ft_cmdsubsplit_alloc(ret, s, set, idx);
	ret[cnt] = 0;
	return (ret);
}
