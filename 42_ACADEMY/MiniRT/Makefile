NAME = Raytracing

LIBX = libmlx.a

SRCS_LIB = $(wildcard libft/*.c)

SRCS_GNL = $(wildcard get_next_line/*.c)

SRCS_ARG = $(wildcard argumentsRT/*.c)

SRCS_CLR = $(wildcard colorRT/*.c)

SRCS_GNI = $(wildcard generateImageRT/*.c)

SRCS_BMP = $(wildcard generateImageRT/bmp/*.c)

SRCS_LD = $(wildcard loadRT/*.c)

SRCS_MATHS = $(wildcard mathsRT/*.c)

SRCS_MATRIX = $(wildcard mathsRT/matrixs/*.c)

SRCS_VECTOR = $(wildcard mathsRT/vectors/*.c)

SRCS_OBJ = $(wildcard objectsRT/*.c)

SRCS_LIBX = $(wildcard libxRT/*.c)

SRCS_INP = $(wildcard input_loopRT/*.c)

SRCS =  $(SRCS_RT) $(SRCS_LIB) $(SRCS_GNL) $(SRCS_ARG) $(SRCS_CLR) $(SRCS_GNI) $(SRCS_BMP) \
		$(SRCS_LD) $(SRCS_MATHS) $(SRCS_MATRIX) $(SRCS_VECTOR) $(SRCS_OBJ) $(SRCS_LIBX) $(SRCS_INP) main.c

COMPILER = gcc

FLAGS = -Wall -Wextra -Werror

FLAGS_LIBX = -lmlx -framework OpenGL -framework AppKit -lz

$(NAME):
		$(COMPILER) $(FLAGS) $(FLAGS_LIBX) $(SRCS) -o $(NAME)

all: $(NAME)

fclean:
		rm -f $(NAME)

re: fclean all
