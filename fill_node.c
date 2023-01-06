/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:10:51 by dongjlee          #+#    #+#             */
/*   Updated: 2023/01/03 20:56:51 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_mini	*mini_init(void)
{
	t_mini	*mini;

	mini = malloc(sizeof(t_mini));
	if (!mini)
		return (0);
	mini->full_cmd = 0;
	mini->full_path = 0;
	mini->infile = STDIN_FILENO;
	mini->outfile = STDOUT_FILENO;
	mini->flag = 0;
	return (mini);
}

static t_mini	*get_params(t_mini *node, char **a[2], int *i)
{
	if (a[0][*i])
	{
		if (a[0][*i][0] == '>' && a[0][*i + 1] && a[0][*i + 1][0] == '>')
			node = get_outfile2(node, a[1], i);
		else if (a[0][*i][0] == '>')
			node = get_outfile1(node, a[1], i);
		else if (a[0][*i][0] == '<' && a[0][*i + 1] && \
			a[0][*i + 1][0] == '<')
			node = get_infile2(node, a[1], i);
		else if (a[0][*i][0] == '<')
			node = get_infile1(node, a[1], i);
		else if (a[0][*i][0] != '|')
			node->full_cmd = ft_extend_matrix(node->full_cmd, a[1][*i]);
		else
		{
			mini_perror(PIPENDERR, NULL, 2);
			*i = -2;
		}
		return (node);
	}
	mini_perror(PIPENDERR, NULL, 2);
	*i = -2;
	return (node);
}

static char	**ft_cmd_trim(char **args)
{
	char	**ret;
	char	*tmp;
	int		i;

	i = 0;
	ret = ft_dup_matrix(args);
	if (!ret)
		return (0);
	while (ret[i])
	{
		tmp = ft_strtrim_all(ret[i]);
		free(ret[i]);
		ret[i] = tmp;
		i++;
	}
	return (ret);
}

static t_list	*ft_cmds_free(t_list *cmds, char **args, char **tmp)
{
	ft_lstclear(&cmds, free_content);
	ft_free_matrix(&args);
	ft_free_matrix(&tmp);
	return (0);
}

t_list	*fill_nodes(char **args)
{
	t_list	*cmds[2];
	char	**temp[2];
	int		i;

	cmds[0] = NULL;
	temp[1] = ft_cmd_trim(args);
	i = 0;
	while (args[i])
	{
		cmds[1] = ft_lstlast(cmds[0]);
		if (i == 0 || (args[i][0] == '|' && args[i + 1] && args[i + 1][0]))
		{
			i += args[i][0] == '|';
			ft_lstadd_back(&cmds[0], ft_lstnew(mini_init()));
			cmds[1] = ft_lstlast(cmds[0]);
		}
		temp[0] = args;
		cmds[1]->content = get_params(cmds[1]->content, temp, &i);
		if (i < 0)
			return (ft_cmds_free(cmds[0], args, temp[1]));
		i++;
	}
	ft_free_matrix(&temp[1]);
	ft_free_matrix(&args);
	return (cmds[0]);
}
