NAME = Raytracing

LIBX = libmlx.a

SRCS_LIB = $(wildcard LIBFT/libft/*.c)

SRCS_GNL = $(wildcard get_next_line/*.c)

SRCS_ARG = $(wildcard readRT/ft_*.c)

SRCS_CLR = $(wildcard colorRT/*.c)

SRCS_GNI = $(wildcard generateimageRT/*.c)

SRCS_BMP = $(wildcard generateimageRT/bmp/*.c)

SRCS_LD = $(wildcard loadRT/*.c)

SRCS_MATHS = $(wildcard mathRT/*.c)

SRCS_MATRIX = $(wildcard mathRT/matrix/*.c)

SRCS_INTER = $(wildcard intersectionsRT/*.c)

SRCS_OBJ = $(wildcard objects/*.c)

SRCS_LIBX = $(wildcard libxRT/*.c)

SRCS_SHIM = $(wildcard showimageRT/*.c)

SRCS =  $(SRCS_RT) $(SRCS_LIB) $(SRCS_GNL) $(SRCS_ARG) $(SRCS_CLR) $(SRCS_GNI) $(SRCS_BMP) \
		$(SRCS_LD) $(SRCS_MATHS) $(SRCS_MATRIX) $(SRCS_INTER) $(SRCS_OBJ) $(SRCS_LIBX) $(SRCS_SHIM) miniRT.c

COMPILER = gcc

FLAGS = -Wall -Wextra -Werror

FLAGS_LIBX = -lmlx -framework OpenGL -framework AppKit -lz

$(NAME):
		$(COMPILER) $(FLAGS) $(FLAGS_LIBX) $(SRCS) -o $(NAME)

all: $(NAME)

fclean:
		rm -f $(NAME)

re: fclean all