/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:12:36 by dongjlee          #+#    #+#             */
/*   Updated: 2023/01/04 00:37:49 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_status;

int	builtin(t_prompt *prompt, t_list *cmd, int *is_exit, int n)
{
	char	**a;

	while (cmd)
	{
		a = ((t_mini *)cmd->content)->full_cmd;
		n = 0;
		if (a)
			n = ft_strlen(*a);
		if (a && !ft_strncmp(*a, "exit", n) && n == 4)
			g_status = mini_exit(cmd, is_exit);
		else if (!cmd->next && a && !ft_strncmp(*a, "cd", n) && n == 2)
			g_status = mini_cd(prompt);
		else if (!cmd->next && a && !ft_strncmp(*a, "unset", n) && n == 5)
			g_status = mini_unset(prompt);
		else
		{
			signal(SIGINT, SIG_IGN);
			signal(SIGQUIT, SIG_IGN);
			exec_cmd(prompt, cmd);
		}
		cmd = cmd->next;
	}
	return (g_status);
}

int	is_builtin(t_mini *number)
{
	int		length;

	if (!number->full_cmd)
		return (0);
	if ((number->full_cmd && ft_strchr(*number->full_cmd, '/')) || \
		(number->full_path && ft_strchr(number->full_path, '/')))
		return (0);
	length = ft_strlen(*number->full_cmd);
	if (!ft_strncmp(*number->full_cmd, "pwd", length) && length == 3)
		return (1);
	if (!ft_strncmp(*number->full_cmd, "env", length) && length == 3)
		return (1);
	if (!ft_strncmp(*number->full_cmd, "cd", length) && length == 2)
		return (1);
	if (!ft_strncmp(*number->full_cmd, "export", length) && length == 6)
		return (1);
	if (!ft_strncmp(*number->full_cmd, "unset", length) && length == 5)
		return (1);
	if (!ft_strncmp(*number->full_cmd, "echo", length) && length == 4)
		return (1);
	if (!ft_strncmp(*number->full_cmd, "exit", length) && length == 4)
		return (1);
	return (0);
}

int	mini_cd(t_prompt *prompt)
{
	char	**str[2];
	char	*aux;

	g_status = 0;
	str[0] = ((t_mini *)prompt->cmds->content)->full_cmd;
	aux = mini_getenv("HOME", prompt->envp, 4);
	if (!aux)
		aux = ft_strdup("");
	str[1] = ft_extend_matrix(NULL, aux);
	free(aux);
	aux = getcwd(NULL, 0);
	str[1] = ft_extend_matrix(str[1], aux);
	free(aux);
	cd_error(str);
	if (!g_status)
		prompt->envp = mini_setenv("OLDPWD", str[1][1], prompt->envp, 6);
	aux = getcwd(NULL, 0);
	if (!aux)
		aux = ft_strdup("");
	str[1] = ft_extend_matrix(str[1], aux);
	free(aux);
	prompt->envp = mini_setenv("PWD", str[1][2], prompt->envp, 3);
	ft_free_matrix(&str[1]);
	return (g_status);
}

int	mini_pwd(void)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	ft_putendl_fd(buf, 1);
	free(buf);
	return (0);
}

int	mini_echo(t_list *cmd)
{
	int		newline;
	int		i[2];
	char	**argv;
	t_mini	*node;

	i[0] = 0;
	i[1] = 0;
	newline = 1;
	node = cmd->content;
	argv = node->full_cmd;
	while (argv && argv[++i[0]])
	{
		if (!i[1] && !ft_strncmp(argv[i[0]], "-n", 2) && \
			(ft_countchar(argv[i[0]], 'n') == \
			(int)(ft_strlen(argv[i[0]]) - 1)))
			newline = 0;
		else
		{
			i[1] = 1;
			ft_putstr_fd(argv[i[0]], 1);
			if (argv[i[0] + 1])
				ft_putchar_fd(' ', 1);
		}
	}
	return (write(1, "\n", newline) == 2);
}
