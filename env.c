/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:09:56 by dongjlee          #+#    #+#             */
/*   Updated: 2023/01/03 18:11:41 by dongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	var_in_envp(char *argv, char **envp, int array[2])
{
	int	pos;

	array[1] = 0;
	pos = ft_strchr_i(argv, '=');
	if (pos == -1)
		return (-1);
	while (envp[array[1]])
	{
		if (!ft_strncmp(envp[array[1]], argv, pos + 1))
			return (1);
		array[1]++;
	}
	return (0);
}

char	*mini_getenv(char *var, char **envp, int number)
{
	int	i;
	int	tmp;

	i = 0;
	while (!ft_strchr(var, '=') && envp && envp[i])
	{
		tmp = number;
		if (tmp < ft_strchr_i(envp[i], '='))
			tmp = ft_strchr_i(envp[i], '=');
		if (!ft_strncmp(envp[i], var, tmp))
			return (ft_substr(envp[i], tmp + 1, ft_strlen(envp[i])));
		i++;
	}
	return (NULL);
}

char	**mini_setenv(char *var, char *value, char **envp, int number)
{
	int		tmp[2];
	char	*str[2];

	tmp[0] = -1;
	str[0] = ft_strjoin(var, "=");
	str[1] = ft_strjoin(str[0], value);
	free(str[0]);
	while (!ft_strchr(var, '=') && envp && envp[++tmp[0]])
	{
		tmp[1] = number;
		if (tmp[1] < ft_strchr_i(envp[tmp[0]], '='))
			tmp[1] = ft_strchr_i(envp[tmp[0]], '=');
		if (!ft_strncmp(envp[tmp[0]], var, tmp[1]))
		{
			str[0] = envp[tmp[0]];
			envp[tmp[0]] = str[1];
			free(str[0]);
			return (envp);
		}
	}
	envp = ft_extend_matrix(envp, str[1]);
	free(str[1]);
	return (envp);
}

int	mini_export_child(t_prompt *prompt, char **argv)
{
	int		pos;
	int		array[2];

	if (ft_matrixlen(argv) >= 2)
	{
		array[0] = 1;
		while (argv[array[0]])
		{
			if (check_export_valid(argv[array[0]]) == -1)
			{
				mini_perror(EXP, argv[array[0]], 2);
				return (1);
			}
			pos = var_in_envp(argv[array[0]], prompt->envp, array);
			if (pos == 1)
			{
				free(prompt->envp[array[1]]);
				prompt->envp[array[1]] = ft_strdup(argv[array[0]]);
			}
			else if (!pos)
				prompt->envp = ft_extend_matrix(prompt->envp, argv[array[0]]);
			array[0]++;
		}
	}
	return (0);
}

int	mini_unset(t_prompt *prompt)
{
	char	**argv;
	char	*aux;
	int		array[2];

	array[0] = 0;
	argv = ((t_mini *)prompt->cmds->content)->full_cmd;
	if (ft_matrixlen(argv) >= 2)
	{
		while (argv[++array[0]])
		{
			if (argv[array[0]][ft_strlen(argv[array[0]]) - 1] != '=')
			{
				aux = ft_strjoin(argv[array[0]], "=");
				free(argv[array[0]]);
				argv[array[0]] = aux;
			}
			if (var_in_envp(argv[array[0]], prompt->envp, array))
				ft_matrix_replace_in(&prompt->envp, NULL, array[1]);
		}
	}
	return (0);
}
