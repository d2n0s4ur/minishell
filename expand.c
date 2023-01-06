/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:45:28 by jnoh              #+#    #+#             */
/*   Updated: 2023/01/03 20:27:31 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_status;

char	*expand_path(char *str, char *var)
{
	char	*ret;
	char	*tmp;
	int		quote;
	int		i;

	quote = 0;
	i = -1;
	while (str[++i])
	{
		if (!quote && (str[i] == '\"' || str[i] == '\''))
			quote = str[i];
		else if (quote == str[i])
			quote = 0;
		if (!quote && str[i] == '~' && (!str[i + 1] || str[i + 1] == '/'))
		{
			tmp = ft_substr(str, 0, i);
			ret = ft_str3join(tmp, var, &str[i + 1]);
			free(tmp);
			free(str);
			str = ret;
			i += ft_strlen(var) - 1;
		}
	}
	return (str);
}

static int	ft_expand_search(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (!ft_isalpha(str[i]) && str[i] != '_')
		return (0);
	i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_isalpha(str[i]) && str[i] != '_')
			break ;
		i++;
	}
	return (i);
}

static char	*get_substr_var(char *str, int i, t_prompt *prompt)
{
	char	*ret;
	int		skip_idx;
	char	*tmp;
	char	*var;

	skip_idx = ft_expand_search(&str[i]) + \
		(ft_strchr("$?0123456789", str[i]) > 0);
	if (skip_idx == -1)
		skip_idx = ft_strlen(str) - 1;
	var = mini_getenv(&str[i], prompt->envp, ft_expand_search(&str[i]));
	if (!var && str[i] == '?')
		var = ft_itoa(g_status);
	else if (!var && str[i] == '$')
		var = ft_itoa(prompt->pid);
	else if (!var && str[i] == '0')
		var = mini_getenv("_", prompt->envp, 1);
	else if (!var)
		var = ft_strdup("");
	tmp = ft_substr(str, 0, i - 1);
	ret = ft_str3join(tmp, var, &str[i + skip_idx]);
	free(tmp);
	free(var);
	free(str);
	return (ret);
}

char	*expand_vars(char *str, t_prompt *prompt)
{
	int	quote;
	int	i;

	quote = 0;
	i = 0;
	while (str[i])
	{
		if (!quote && (str[i] == '\"' || str[i] == '\''))
			quote = str[i];
		else if (quote == str[i])
			quote = 0;
		if ((!quote || quote == '\"') && str[i] == '$' && \
			str[i + 1] && (ft_expand_search(&str[i + 1]) + \
				(ft_strchr("$?0123456789", str[i + 1]) > 0)))
			return (expand_vars(get_substr_var(str, i + 1, prompt), prompt));
		i++;
	}
	return (str);
}
