/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirect_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:47:04 by jnoh              #+#    #+#             */
/*   Updated: 2023/01/03 20:55:37 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_status;

static int	ft_check_perror(char *path, int flags[2])
{
	if (access(path, F_OK) == -1 && !flags[0])
		mini_perror(NDIR, path, 127);
	else if (!flags[0] && access(path, R_OK) == -1)
		mini_perror(NPERM, path, 126);
	else if (flags[0] && access(path, W_OK) == -1 && access(path, F_OK) == 0)
		mini_perror(NPERM, path, 126);
	else
		return (1);
	return (0);
}

int	get_fd(int *oldfd, char *path, int flags[2])
{
	int	ret;
	int	fd;

	ret = -2;
	if (*oldfd > 2)
		close(*oldfd);
	if (!path)
		return (-1);
	if (ft_check_perror(path, flags))
	{
		if (flags[0] && flags[1])
			fd = open(path, O_CREAT | O_WRONLY | O_APPEND, 0644);
		else if (flags[0] && !flags[1])
			fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else if (!flags[0] && *oldfd != -1)
			fd = open(path, O_RDONLY);
		else
			fd = *oldfd;
		*oldfd = fd;
		ret = fd;
	}
	return (ret);
}

int	ft_check_token(char *arg, int *i)
{
	if (arg && ft_strchars_i(arg, "|<>&;\n") != -1)
	{
		printf("arg: %s\n", arg);
		ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
		if (ft_strchr(arg, '\n'))
			ft_putstr_fd("newline", 2);
		else
			ft_putstr_fd(arg, 2);
		ft_putstr_fd("'\n", 2);
		g_status = 258;
		*i = -1;
		return (1);
	}
	return (0);
}
