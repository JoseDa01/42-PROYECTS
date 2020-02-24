NAME = libftprintf.a

SRCS = $(wildcard *.c)

GCC = gcc -Wextra -Werror -Wall

LIBFT = $(wildcard libft/*.c)

LIBFTOBJ = $(LIBFT:.c=.o)

$(NAME): $(SRCS) libftprintf.h
		 $(GCC) -c $(SRCS) $(LIBFT)
		 ar rc $(NAME) *.o
		 ranlib $(NAME)

all: $(NAME)

clean:
		rm -f *.o

fclean: clean
		rm -f $(NAME)

re: fclean all
