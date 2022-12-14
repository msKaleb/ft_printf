# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 17:56:18 by msoria-j          #+#    #+#              #
#    Updated: 2022/12/14 19:26:23 by msoria-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = 			gcc

FLAGS = 		-Wall -Werror -Wextra

NAME =			libftprintf.a

SUBDIRS = 		libft

SRCS = 			ft_printf.c \
				change_base.c \
				print_var.c \
				ft_itoa_u.c

OBJS = 			$(SRCS:.c=.o)


$(NAME):		$(OBJS)
				@make -C $(SUBDIRS)
				cp $(SUBDIRS)/libft.a .
				mv libft.a $(NAME)
				ar rcs $(NAME) $(OBJS)

all:			$(NAME)

clean:
				@echo Cleaning .o files
				make clean -C $(SUBDIRS)
				@$(RM) $(OBJS)

fclean:			clean
				@echo Cleaning .a files
				@$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re $(SUBDIRS)
