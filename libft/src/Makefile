# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seopark <seopark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/19 16:30:39 by seopark           #+#    #+#              #
#    Updated: 2021/05/19 16:30:41 by seopark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rc
RM = rm -f

SRCS = ft_memset.c  ft_bzero.c  ft_memcpy.c \
	   ft_memccpy.c ft_memmove.c  ft_memchr.c \
	   ft_memcmp.c  ft_strlen.c  ft_strlcpy.c \
	   ft_strlcat.c ft_strchr.c  ft_strrchr.c \
	   ft_strnstr.c ft_strncmp.c ft_isalpha.c \
	   ft_isdigit.c ft_isalnum.c ft_isascii.c \
	   ft_isprint.c ft_toupper.c ft_tolower.c \
	   ft_atoi.c ft_calloc.c ft_strdup.c \
	   ft_substr.c ft_strjoin.c ft_strtrim.c \
	   ft_split.c ft_itoa.c ft_strmapi.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	   ft_putnbr_fd.c

SRCS_B = ft_lstnew.c \
		 ft_lstadd_front.c \
		 ft_lstsize.c \
		 ft_lstlast.c \
		 ft_lstadd_back.c \
		 ft_lstdelone.c \
		 ft_lstclear.c \
		 ft_lstiter.c \
		 ft_lstmap.c

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
OBJECTS = $(OBJS)

ifdef IS_BONUS
	OBJECTS = $(OBJS_B)	
endif

$(NAME) : $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $<

bonus :
	$(MAKE) IS_BONUS=1 $(NAME)

clean :
	$(RM) $(OBJS) $(OBJS_B)
fclean : clean
	$(RM) $(NAME)
re : fclean all

.PHONY : all clean fclean re bonus
