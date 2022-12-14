# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msoria-j <msoria-j@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 17:56:18 by msoria-j          #+#    #+#              #
#    Updated: 2022/12/14 11:58:54 by msoria-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = #-Wall -Werror -Wextra

NAME = ft_printf.a

EXE = test

SUBDIRS = libft
SUBOBJS = $(wildcard /libft/*.o)
SRCS = $(wildcard libft/*.c) $(wildcard *.c)
#SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)


$(NAME):	$(OBJS)
			make -C libft
#			ar rcs $(NAME) $(OBJS)
#			$(CC) -o $(EXE) $(SUBOBJS) $(OBJS)
	$(CC) -o $(NAME) $(FLAGS) $(SRCS)


all:			$(NAME)

.SILENT:		clean fclean

clean:
				@echo Cleaning .o files
				make -C libft clean
				$(RM) $(OBJS)

fclean:			clean
				@echo Cleaning .a files
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re libft
