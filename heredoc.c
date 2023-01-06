/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:09:29 by dongjlee          #+#    #+#             */
/*   Updated: 2023/01/03 20:55:30 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_status;

char	*get_here_str(size_t len, char *endstr)
{
	char	*tmp;
	char	*line;
	char	*ret;

	line = 0;
	ret = 0;
	while (g_status != 130 && (!line || !(!ft_strncmp(line, endstr, len) && \
		ft_strlen(endstr) == len)))
	{
		tmp = ret;
		ret = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
		line = readline("> ");
		if (!line)
			break ;
		tmp = line;
		line = ft_strjoin(tmp, "\n");
		free(tmp);
		len = ft_strlen(line) - 1;
	}
	free(line);
	return (ret);
}

int	get_here_doc(char *endstr)
{
	char	*ret;
	int		fd[2];

	signal(SIGINT, handle_sigint);
	g_status = 0;
	if (pipe(fd) == -1)
	{
		mini_perror(PIPERR, NULL, 1);
		return (-1);
	}
	ret = get_here_str(0, endstr);
	write(fd[WRITE_END], ret, ft_strlen(ret));
	close(fd[WRITE_END]);
	free(ret);
	if (g_status == 130)
	{
		close(fd[READ_END]);
		return (-1);
	}
	return (fd[READ_END]);
}
