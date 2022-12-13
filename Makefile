# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 17:56:18 by msoria-j          #+#    #+#              #
#    Updated: 2022/12/13 19:14:06 by msoria-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Werror -Wextra

NAME = test

SUBDIRS = libft

#SRCS = $(wildcard libft/*.c) $(wildcard *.c)
SRCS = $(wildcard *.c)
$(SUBDIRS):
	$(MAKE) -C $@
OBJS = $(SRCS:.c=.o)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(FLAGS) $(SRCS)

all:			$(NAME)

clean:
				$(RM) $(OBJS) $(SUBDIRS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re $(SUBDIRS)