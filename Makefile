CC			= cc
CFLAGS		= -Wall -Werror -Wextra -Ofast
NAME		= fractol

SRCS		=	moves		\
				displays		\
				calculs_mandel		\
				calculs_julia	\
				fractol	\
				main \
				utils \

INCS		=	-I libft \
				-I get_next_line \

INCS_ARCHIVES 	=	libft/libft.a \


SRC			= $(addsuffix .c, $(SRCS))
OBJ			= $(addsuffix .o, $(SRCS))

all: $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C libft
	$(MAKE) -C minilibx
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(INC_ARCHIVES) $(LINKS)

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