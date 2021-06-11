# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seopark <seopark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/19 16:30:39 by seopark           #+#    #+#              #
#    Updated: 2021/06/11 16:04:51 by seopark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rc
RM = rm -f
###################
SRCS = 	ft_printf.c \
		ft_output.c \
		handle_flags.c \
		print_string.c \
		libft.c \
		ft_itoa.c

OBJS = $(SRCS:.c=.o)
OBJECTS = $(OBJS)

$(NAME) : $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean :
	$(RM) $(OBJS) $(OBJS_B)
fclean : clean
	$(RM) $(NAME)
re : fclean all

.PHONY : all clean fclean re bonus
