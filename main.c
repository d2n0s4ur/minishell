/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:09:46 by dongjlee          #+#    #+#             */
/*   Updated: 2023/01/04 00:18:43 by dongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_status;

static void	mini_getpid(t_prompt *prompt)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0 || !pid)
	{
		if (pid < 0)
			mini_perror(FORKERR, NULL, 1);
		ft_free_matrix(&prompt->envp);
		exit(1);
	}
	waitpid(pid, NULL, 0);
	prompt->pid = pid - 1;
}

static t_prompt	init_vars(t_prompt prompt, char **argv)
{
	char	*tmp;
	char	*str;

	str = mini_getenv("SHLVL", prompt.envp, 5);
	if (!str || ft_atoi(str) <= 0)
		tmp = ft_strdup("1");
	else
		tmp = ft_itoa(ft_atoi(str) + 1);
	free(str);
	prompt.envp = mini_setenv("SHLVL", tmp, prompt.envp, 5);
	free(tmp);
	str = getcwd(NULL, 0);
	prompt.envp = mini_setenv("PWD", str, prompt.envp, 3);
	free(str);
	str = mini_getenv("PATH", prompt.envp, 4);
	if (!str)
		prompt.envp = mini_setenv("PATH", \
		"/usr/local/sbin:/usr/local/bin:/usr/bin:/bin", prompt.envp, 4);
	free(str);
	str = mini_getenv("_", prompt.envp, 1);
	if (!str)
		prompt.envp = mini_setenv("_", argv[0], prompt.envp, 1);
	free(str);
	return (prompt);
}

static t_prompt	init_prompt(char **argv, char **envp)
{
	t_prompt	prompt;

	g_status = 0;
	prompt.cmds = NULL;
	prompt.envp = ft_dup_matrix(envp);
	mini_getpid(&prompt);
	prompt = init_vars(prompt, argv);
	return (prompt);
}

void	terminal_set(struct termios *old_term)
{
	tcgetattr(STDIN_FILENO, old_term);
	old_term->c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, old_term);
}

int	main(int argc, char **argv, char **envp)
{
	char				*str;
	char				*result;
	t_prompt			prompt;
	struct termios		term[2];

	tcgetattr(STDIN_FILENO, &term[0]);
	prompt = init_prompt(argv, envp);
	while (argv && argc)
	{
		terminal_set(&term[1]);
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		str = mini_getprompt(prompt);
		if (str)
			result = readline(str);
		else
			result = readline("guest@minishell $ ");
		free(str);
		if (!check_args(result, &prompt))
			break ;
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &term[0]);
	exit(g_status);
}
