NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJS = ft_strchr.o ft_strrchr.o ft_strlen.o
SRCS = $(OBJS:.o=.c)

all : $(NAME)
$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm $(NAME)

re : fclean all

ft_strrchr.o : libft.h ft_strrchr.c
	gcc -c ft_strrchr.c
ft_strchr.o : libft.h ft_strchr.c
	gcc -c ft_strchr.c
ft_strlen.o : libft.h ft_strlen.c
	gcc -c ft_strlen.c
