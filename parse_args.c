/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:40:16 by dongjlee          #+#    #+#             */
/*   Updated: 2023/01/03 17:42:11 by dongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_status;

static char	**split_all(char **args, t_prompt *prompt)
{
	char	**subsplit;
	int		i;
	char	*tmp;

	i = 0;
	if (!args)
		return (0);
	while (args[i])
	{
		args[i] = expand_vars(args[i], prompt);
		tmp = mini_getenv("HOME", prompt->envp, 4);
		args[i] = expand_path(args[i], tmp);
		free(tmp);
		subsplit = ft_cmdsubsplit(args[i], "<>|");
		ft_matrix_replace_in(&args, subsplit, i);
		i += ft_matrixlen(subsplit);
		ft_free_matrix(&subsplit);
	}
	return (args);
}

static void	*parse_args(char **args, t_prompt *p)
{
	int		is_exit;
	int		i;
	t_list	*last;

	is_exit = 0;
	p->cmds = fill_nodes(split_all(args, p));
	if (!p->cmds)
		return (p);
	i = ft_lstsize(p->cmds);
	g_status = builtin(p, p->cmds, &is_exit, 0);
	while (i-- > 0)
		waitpid(-1, &g_status, 0);
	last = (t_list *)ft_lstlast(p->cmds);
	if (g_status == 0 && ((t_mini *)last->content)->outfile < 0)
		g_status = 1;
	if (!is_exit && g_status == 13)
		g_status = 0;
	if (g_status > 255)
		g_status = g_status / 255;
	if (args && is_exit)
	{
		ft_lstclear(&p->cmds, free_content);
		return (0);
	}
	return (p);
}

void	*check_args(char *out, t_prompt *p)
{
	char	**full_cmd;
	t_mini	*proc;

	if (!out)
	{
		printf("exit\n");
		return (0);
	}
	if (out[0])
		add_history(out);
	full_cmd = ft_cmdtrim(out, " ");
	free(out);
	if (!full_cmd)
		mini_perror(QUOTE, NULL, 1);
	if (!full_cmd)
		return ("");
	p = parse_args(full_cmd, p);
	if (p && p->cmds)
		proc = p->cmds->content;
	if (p && p->cmds && proc && proc->full_cmd && ft_lstsize(p->cmds) == 1)
		p->envp = mini_setenv("_", \
		proc->full_cmd[ft_matrixlen(proc->full_cmd) - 1], p->envp, 1);
	if (p && p->cmds)
		ft_lstclear(&p->cmds, free_content);
	return (p);
}
