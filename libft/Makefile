# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 13:29:58 by dongjlee          #+#    #+#              #
#    Updated: 2023/01/03 20:20:20 by jnoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	libft.a
RM		=	rm -f
LIB		=	ar rcu
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	ft_isalpha.c 		\
			ft_isdigit.c 		\
			ft_isalnum.c 		\
			ft_isascii.c 		\
			ft_isprint.c 		\
			ft_strlen.c			\
			ft_memset.c			\
			ft_bzero.c			\
			ft_toupper.c		\
			ft_tolower.c		\
			ft_strlcat.c		\
			ft_strlcpy.c		\
			ft_atoi.c			\
			ft_calloc.c			\
			ft_strncmp.c		\
			ft_strchr.c			\
			ft_strrchr.c		\
			ft_memcpy.c			\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_strdup.c			\
			ft_strnstr.c		\
			ft_memmove.c		\
			ft_strjoin.c		\
			ft_strtrim.c		\
			ft_substr.c			\
			ft_split.c			\
			ft_itoa.c			\
			ft_strmapi.c		\
			ft_striteri.c		\
			ft_putchar_fd.c		\
			ft_putstr_fd.c		\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c		\
			get_next_line.c			\
			get_next_line_utils.c	\
			ft_free_matrix.c		\
			ft_dup_matrix.c			\
			ft_extend_matrix.c		\
			ft_countchar.c			\
			ft_putmatrix_fd.c		\
			ft_strchars_i.c			\
			ft_isspace.c			\
			ft_strchr_i.c			\
			ft_matrixlen.c			\
			ft_matrix_replace_in.c	\
			ft_lstnew_bonus.c		\
			ft_lstadd_front_bonus.c	\
			ft_lstsize_bonus.c		\
			ft_lstlast_bonus.c		\
			ft_lstadd_back_bonus.c	\
			ft_lstdelone_bonus.c	\
			ft_lstclear_bonus.c		\
			ft_lstiter_bonus.c		\
			ft_lstmap_bonus.c		\
			ft_strcmp.c				\
			ft_is_all_digit.c		\
			ft_str3join.c

OBJS	=	$(SRCS:.c=.o)

all	: $(NAME)

$(NAME) : $(OBJS)
	$(LIB) $(NAME) $(OBJS)

bonus : 
	make WITH_BONUS=1 all

clean :
	$(RM) $(OBJS) $(OBJS_B)

fclean	: clean
	$(RM) $(NAME)

re : fclean all

.PHONY : bonus all clean fclean re