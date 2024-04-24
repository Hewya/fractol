CC			= cc
CFLAGS		= -Wall -Werror -Wextra -Ofast
NAME		= fractol

LINKS			= -L minilibx-linux/ -lmlx -lXext -lX11
INC_ARCHIVES	= libft/libft.a minilibx-linux/libmlx_Linux.a

SRCS		=	moves		\
				displays		\
				calculs_mandel		\
				calculs_julia	\
				main \
				utils \
				init and exit \

INCS		=	-I libft \
				-I get_next_line \
				-I minilibx-linux \

SRC			= $(addsuffix .c, $(SRCS))
OBJ			= $(addsuffix .o, $(SRCS))

all: $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C libft
	$(MAKE) -C minilibx-linux/
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(INC_ARCHIVES) $(LINKS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS) $(INCS)

clean:
	$(MAKE) -C libft/ clean
	$(MAKE) -C minilibx-linux/ clean
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) -C libft/ fclean
	$(MAKE) -C minilibx-linux/ clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re