/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:39:16 by dongjlee          #+#    #+#             */
/*   Updated: 2023/01/03 20:56:11 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_cmdtrim_quote_cnt(const char *s)
{
	int	quote;
	int	ret;

	quote = 0;
	ret = 0;
	if (!s)
		return (-1);
	while (*s)
	{
		if (!quote && (*s == '\"' || *s == '\''))
			quote = *s;
		else if (quote == *s)
			quote = 0;
		if ((!quote && (*s != '\'' && *s != '\"')) || (quote && quote != *s))
			ret++;
		s++;
	}
	if (quote)
		return (-1);
	return (ret);
}

static void	ft_strtrim_fill(const char *s, char *ret)
{
	int	quote;
	int	i;

	quote = 0;
	i = 0;
	while (*s)
	{
		if (!quote && (*s == '\"' || *s == '\''))
			quote = *s;
		else if (quote == *s)
			quote = 0;
		if ((!quote && (*s != '\'' && *s != '\"')) || (quote && quote != *s))
			ret[i++] = *s;
		s++;
	}
	ret[i] = 0;
}

char	*ft_strtrim_all(char const *s)
{
	int		quote_cnt;
	char	*ret;

	quote_cnt = ft_cmdtrim_quote_cnt(s);
	if (!s || quote_cnt == -1)
		return (0);
	ret = (char *)malloc(sizeof(char) * (quote_cnt + 1));
	if (!ret)
		return (0);
	ft_strtrim_fill(s, ret);
	return (ret);
}
