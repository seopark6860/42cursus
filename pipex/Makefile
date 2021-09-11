NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = pipex.c \
		exec_error.c \
		libft_utils.c \
		libft_split.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean :
	$(RM) $(OBJS)
fclean : clean
	$(RM) $(NAME)
re : fclean all