# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hguillau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 14:35:37 by hguillau          #+#    #+#              #
#    Updated: 2024/05/16 14:36:12 by hguillau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    	=	src/main.c							\
				src/signaux/signaux.c				\
				src/errors/error.c					\
				src/errors/printf_error.c			\
				src/builtins/cd.c					\
				src/builtins/pwd.c					\
				src/builtins/echo.c					\
				src/builtins/exit.c					\
				src/builtins/env.c					\
				src/builtins/unset.c				\
				src/builtins/export_init.c			\
				src/builtins/export.c				\
				src/builtins/export_utils.c			\
				src/execution/utils_exec.c			\
				src/execution/redir_exec_builtins.c	\
				src/execution/utils.c				\
				src/execution/set_for_exec.c		\
				src/execution/exec.c				\
				src/lexer_parser/init.c				\
				src/lexer_parser/utils.c			\
				src/lexer_parser/lexer.c			\
				src/lexer_parser/redir.c			\
				src/lexer_parser/lexer_pipe.c		\
				src/lexer_parser/dollar.c			\
				src/lexer_parser/parsing.c			\
				src/lexer_parser/free_lexer.c		\
				src/lexer_parser/heredoc.c			\
				src/utils/free.c					\
				src/utils/ft_count_list.c			\
				src/utils/ft_strndup.c				\
				src/utils/tab_len.c					\
				src/utils/ft_cpytab.c				\
				src/utils/cmd_utils.c				\
				src/utils/get_in_env.c				\
				src/lexer_parser/lexer_str.c		\
#				src/lexer_parser/lexer_alpha.c		\
#				src/lexer_parser/quotes.c			\
#				src/expender/expender.c				\#

OBJS    	=	${SRCS:.c=.o}

NAME    	=	minishell

LIBS		=	./src/libft/

#ifeq ($(USER), tpaufert)
#RL			=	-L/Users/$(USER)/.brew/Cellar/readline/8.2.1/lib -lreadline
#else
#RL			=	-L/opt/homebrew/opt/readline/lib -lreadline
#endif

CC      	=	gcc

RM      	=	rm -f

CFLAGS  	=	-Wall -Wextra -Werror -g -fsanitize=address

all:		${NAME}

${NAME}:	${OBJS}
			make all -C ${LIBS}
			${CC} ${CFLAGS} ${OBJS} -L ${LIBS} -lft -lreadline -o ${NAME}

clean:
			make clean -C ${LIBS}
			${RM} ${OBJS}

fclean:		clean
			make fclean -C ${LIBS}
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
