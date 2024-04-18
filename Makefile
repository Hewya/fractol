CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g
NAME		= fractol

SRCS		=	moves		\
				displays		\
				calculs_mandel		\
				calculs_julia	\
				fractol	\

INCS		=	-I libft \
				-I get_next_line \

SRC			= $(addsuffix .c, $(SRCS))
OBJ			= $(addsuffix .o, $(SRCS))

all: $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) -o $@ $(OBJ) libft/libft.a

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS) $(INCS)

clean:
	$(MAKE) -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re