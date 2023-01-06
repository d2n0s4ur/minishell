# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 17:13:55 by dongjlee          #+#    #+#              #
#    Updated: 2023/01/03 20:51:03 by jnoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell
RM		=	rm -f
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
SRCS = main.c builtins.c ft_strtrim_all.c exec.c					\
	  fill_node.c get_redirect.c ft_cmdtrim.c env_util.c			\
	  expand.c heredoc.c error.c env.c custom_cmd.c	error_util.c	\
	  prompt.c ft_cmdsubsplit.c signal.c parse_args.c get_cmd.c		\
	  get_redirect_utils.c

COMFILE_FLAGS = -lreadline -L/usr/local/opt/readline/lib
OBJS	=	$(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a libft.a
	$(CC) -L /usr/local/opt/readline/lib -I /usr/local/opt/readline/include -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include $(CFLAGS) $(OBJS) -L. -lft -lreadline -o $(NAME)

all	: $(NAME)

%.o: %.c
	$(CC) -I ~/.brew/opt/readline/include -I /usr/local/opt/readline/include $(CFLAGS) -c $< -o $@

clean :
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean	: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
	$(RM) libft.a

re : fclean all

.PHONY : all clean fclean re