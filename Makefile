SRCS =	creat_window.c \
		deal_key.c \
		draw_line_utils.c \
		draw_line.c \
		draw.c \
		fdf.c \
		ft_utils.c \
		ft_split.c \
		get_data.c \
		./get_next_line/get_next_line_utils.c \
		./get_next_line/get_next_line.c \
		my_mlx_put_pixel.c
	
CC =cc 
CFLAGS=-Wall -Werror -Wextra -Ofast
MLXLIB =-lmlx -framework OpenGL -framework AppKit
OBJS = $(SRCS:.c=.o)

NAME = fdf

all : $(NAME) 

$(NAME) : $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(MLXLIB) -o $(NAME)
	
%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	rm -rf *.o
	cd get_next_line && rm -rf *.o

fclean : clean
	rm -f $(NAME)

re : fclean all
