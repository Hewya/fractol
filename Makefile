CC			= cc
CFLAGS		= -Wall -Werror -Wextra -Ofast
NAME		= fractol
OBJDIR		= obj

LINKS			= -L minilibx-linux/ -lmlx -lXext -lX11
INC_ARCHIVES	= libft/libft.a minilibx-linux/libmlx_Linux.a

SRCS		=	moves		\
				displays		\
				calculs_mandel	\
				calculs_julia	\
				calculs_ship	\
				main \
				utils \
				init_exit \
				colors \

INCS		=	-I libft \
				-I get_next_line \
				-I minilibx-linux \

SRC			= $(addsuffix .c, $(SRCS))
OBJ			= $(addprefix $(OBJDIR)/, $(addsuffix .o, $(SRCS)))

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME) : $(OBJ)
	$(MAKE) -C libft
	$(MAKE) -C minilibx-linux/
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(INC_ARCHIVES) $(LINKS)

$(OBJDIR)/%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS) $(INCS)

clean:
	$(MAKE) -C libft/ clean
	$(MAKE) -C minilibx-linux/ clean
	rm -rf $(OBJ) $(OBJDIR)

fclean: clean
	$(MAKE) -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re