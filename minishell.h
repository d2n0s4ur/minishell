/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:38:08 by dongjlee          #+#    #+#             */
/*   Updated: 2023/01/03 20:50:29 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <termios.h>

# define READ_END 0
# define WRITE_END 1
# define DEFAULT "\001\033[0;39m\002"

typedef struct s_prompt
{
	t_list	*cmds;
	char	**envp;
	pid_t	pid;
}			t_prompt;

typedef struct s_mini
{
	char	**full_cmd;
	char	*full_path;
	int		infile;
	int		outfile;
	int		flag;
}			t_mini;

enum	e_mini_error
{
	QUOTE = 1,
	NDIR = 2,
	NPERM = 3,
	NCMD = 6,
	DUPERR = 7,
	FORKERR = 8,
	PIPERR = 9,
	PIPENDERR = 10,
	MEM = 11,
	IS_DIR = 12,
	NOT_DIR = 13,
	EXP = 14
};

char		*mini_readline(t_prompt *prompt, char *str);
void		*mini_here_fd(int fd[2]);
int			builtin(t_prompt *prompt, t_list *cmd, int *is_exit, int n);
int			is_builtin(t_mini *number);
int			mini_cd(t_prompt *prompt);
void		cd_error(char **str[2]);
int			mini_pwd(void);
int			mini_echo(t_list *cmd);
int			mini_export(t_prompt *prompt);
int			mini_unset(t_prompt *prompt);
int			mini_exit(t_list *cmd, int *is_exit);
void		*check_args(char *out, t_prompt *p);
char		**ft_cmdtrim(char const *s, char *set);
char		**ft_cmdsubsplit(char const *s, char *set);
char		*ft_strtrim_all(char const *s);
t_list		*fill_nodes(char **args);
t_mini		*get_outfile1(t_mini *node, char **args, int *i);
t_mini		*get_outfile2(t_mini *node, char **args, int *i);
t_mini		*get_infile1(t_mini *node, char **args, int *i);
t_mini		*get_infile2(t_mini *node, char **args, int *i);
void		*exec_cmd(t_prompt *prompt, t_list *cmd);
void		*check_to_fork(t_prompt *prompt, t_list *cmd, int fd[2]);
void		child_builtin(t_prompt *prompt, t_mini *n, int l, t_list *cmd);
void		get_username(char ***username, char *full, char *args, char **envp);
int			exec_builtin(t_prompt *prompt, int (*func)(t_prompt *));
void		get_cmd(t_prompt *prompt, t_list *start, \
					char **split_path, char *path);
char		*expand_vars(char *str, t_prompt *prompt);
char		*expand_path(char *str, char *var);
int			get_here_doc(char *endstr);
void		*mini_perror(int err_type, char *param, int err);
char		*mini_getenv(char	*var, char **envp, int n);
char		**mini_setenv(char *var, char *value, char **envp, int n);
char		*mini_getprompt(t_prompt prompt);
void		free_content(void *content);
void		handle_sigint(int sig);
void		handle_sigint_child(int sig);
int			ft_atoi2(const char *nptr, long *nbr);
int			find_char_pos(int target, char *str);
int			is_a_before_b(int a, int b, char *str);
int			check_export_valid(char *argv);
int			mini_export_child(t_prompt *prompt, char **argv);
int			get_fd(int *oldfd, char *path, int flags[2]);
int			ft_check_token(char *arg, int *i);

#endif
