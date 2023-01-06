/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:06:42 by dongjlee          #+#    #+#             */
/*   Updated: 2023/01/04 00:58:48 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_char_pos(int target, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == target)
			return (i);
		i++;
	}
	return (-1);
}

int	is_a_before_b(int a, int b, char *str)
{
	int	a_pos;
	int	b_pos;

	a_pos = find_char_pos(a, str);
	b_pos = find_char_pos(b, str);
	if (a_pos != -1 && b_pos != -1 && a_pos < b_pos)
		return (1);
	return (0);
}

int	check_export_valid(char *argv)
{
	if (ft_is_all_digit(argv) == 1 || is_a_before_b('-', '=', argv))
		return (-1);
	else if ((find_char_pos('-', argv) != -1) && \
		(find_char_pos('=', argv) == -1))
		return (-1);
	else if (argv[0] == '=')
		return (-1);
	return (1);
}

static void	ft_export_argv_1(t_prompt *prompt)
{
	int		i;
	int		idx;
	char	*tmp;
	int		flag;

	i = 0;
	flag = 0;
	while (prompt->envp[i])
	{
		idx = ft_strchr(prompt->envp[i], '=') - prompt->envp[i];
		tmp = ft_substr(prompt->envp[i], 0, idx);
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(tmp, 1);
		ft_putstr_fd("=\"", 1);
		ft_putstr_fd(prompt->envp[i] + idx + 1, 1);
		ft_putstr_fd("\"\n", 1);
		if (ft_strncmp(tmp, "OLDPWD", 6) == 0 && ft_strlen(tmp) == 6)
			flag = 1;
		free(tmp);
		i++;
	}
	if (flag == 0)
		ft_putstr_fd("declare -x OLDPWD\n", 1);
	return ;
}

int	mini_export(t_prompt *prompt)
{
	char	**argv;

	argv = ((t_mini *)prompt->cmds->content)->full_cmd;
	if (ft_matrixlen(argv) >= 2)
		return (mini_export_child(prompt, argv));
	else
		ft_export_argv_1(prompt);
	return (1);
}
