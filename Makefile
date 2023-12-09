NAME 		= fractale
CC 			= cc
RM			= rm -f
CLONE 		= git clone --depth=1

CFLAGS 		+= 
CLINKS		= -ldl -lglfw -pthread -lm

MLX			= minilibx
LIBMLX 		= $(MLX)/libmlx42.a

FT			= libft
LIBFT		= $(FT)/libft.a

SRC 		= fractol.c\
		ft_mandelbrot.c\
		color.c\

OBJ 		= $(SRC:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBMLX) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBMLX) $(CLINKS)

$(LIBMLX): $(MLX)
	cmake $(MLX) -B $(MLX)	
	$(MAKE) -C $(MLX)

$(LIBFT): $(FT)
	$(MAKE) -C $(FT)

$(MLX):
	$(CLONE) https://github.com/kodokaii/MLX42.git $(MLX)

$(FT):
	$(CLONE) https://github.com/Ectalex/libft.git $(FT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(MLX)
	$(MAKE) clean -C $(FT)

fclean: clean
	$(RM) $(LIBMLX)
	$(RM) $(NAME)
	$(RM) $(LIBFT)

clear: fclean
	$(RM) -rf $(MLX)
	$(RM) -rf $(FT)

re: fclean all

.PHONY:		all bonus clear clean fclean re
