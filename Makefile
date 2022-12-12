# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 17:56:18 by msoria-j          #+#    #+#              #
#    Updated: 2022/12/12 18:48:29 by msoria-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Werror -Wextra

NAME = test

SRCS = $(wildcard libft/*.c) $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(FLAGS) $(SRCS)