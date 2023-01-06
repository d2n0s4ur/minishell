/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:39:22 by dongjlee          #+#    #+#             */
/*   Updated: 2023/01/03 20:55:35 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_status;

t_mini	*get_outfile1(t_mini *node, char **args, int *i)
{
	int		flags[2];
	int		result;

	flags[0] = 1;
	flags[1] = 0;
	(*i)++;
	if (ft_check_token(args[*i], i))
		return (node);
	if (args[*i] && node->infile >= 0)
		result = get_fd(&node->outfile, args[*i], flags);
	if ((!args[*i] || result < 0))
	{
		if (result == -2)
		{
			node->outfile = -1;
			while (args[*i] && args[*i][0] != '|')
				(*i)++;
			(*i)--;
		}
		g_status = 1;
	}
	if (!args[*i])
		*i = -1;
	return (node);
}

t_mini	*get_outfile2(t_mini *node, char **args, int *i)
{
	int		flags[2];
	int		result;

	flags[0] = 1;
	flags[1] = 1;
	(*i) += 2;
	if (ft_check_token(args[*i], i))
		return (node);
	if (args[*i] && node->infile >= 0)
		result = get_fd(&node->outfile, args[*i], flags);
	if (!args[*i] || result < 0)
	{
		if (result == -2)
		{
			node->outfile = -1;
			while (args[*i] && args[*i][0] != '|')
				(*i)++;
			(*i)--;
		}
		g_status = 1;
	}
	if (!args[*i])
		*i = -1;
	return (node);
}

t_mini	*get_infile1(t_mini *node, char **args, int *i)
{
	int		flags[2];
	int		result;

	flags[0] = 0;
	flags[1] = 0;
	(*i)++;
	if (ft_check_token(args[*i], i))
		return (node);
	if (args[*i])
		result = get_fd(&node->infile, args[*i], flags);
	if (!args[*i] || result < 0)
	{
		if (result == -2)
		{
			while (args[*i] && args[*i][0] != '|')
				(*i)++;
			(*i)--;
			node->flag = 1;
		}
		g_status = 1;
	}
	if (!args[*i])
		*i = -1;
	return (node);
}

t_mini	*get_infile2(t_mini *node, char **args, int *i)
{
	(*i) += 2;
	if (ft_check_token(args[*i], i))
		return (node);
	if (args[(*i)])
		node->infile = get_here_doc(args[*i]);
	if (!args[*i] || node->infile == -1)
		*i = -1;
	return (node);
}
