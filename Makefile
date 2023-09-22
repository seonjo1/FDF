# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 17:07:04 by seonjo            #+#    #+#              #
#    Updated: 2023/09/22 17:02:08 by seonjo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FDF
CC = cc
FLAGS = -L. -lmlx -framework OpenGL -framework AppKit -lz
CFLAGS = -Wall -Wextra -Werror
SRCS = fdf_main.c fdf_hook.c fdf_bresenham.c fdf_re_draw_img.c fdf_keyhook.c fdf_draw_img.c fdf_img_adjust.c fdf_libft.c fdf_parsing.c fdf_rotate.c get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(FLAGS) -L./libft -lft -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I. -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re