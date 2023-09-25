# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 17:07:04 by seonjo            #+#    #+#              #
#    Updated: 2023/09/25 17:34:40 by seonjo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc
FLAGS = -L. -lmlx -framework OpenGL -framework AppKit -lz
CFLAGS = -Wall -Wextra -Werror
SRCS = fdf_main.c fdf_parsing2.c fdf_bresenham.c fdf_draw_img.c fdf_img_adjust.c fdf_libft.c fdf_parsing.c fdf_rotate.c get_next_line.c get_next_line_utils.c
SRCS2 = fdf_main_bonus.c fdf_hook_bonus.c fdf_parsing2_bonus.c fdf_bresenham_bonus.c fdf_re_draw_img_bonus.c fdf_hook_func_bonus.c fdf_draw_img_bonus.c fdf_img_adjust_bonus.c fdf_libft_bonus.c fdf_parsing_bonus.c fdf_rotate_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS2 = $(SRCS2:.c=.o)
LIBFT = ./libft/libft.a

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(FLAGS) $(OBJS) -L./libft -lft -o $(NAME)
	rm -f $(OBJS2)

bonus : $(OBJS2) $(LIBFT)
	$(CC) $(CFLAGS) $(FLAGS) $(OBJS2) -L./libft -lft -o $(NAME)
	rm -f $(OBJS)
	@touch bonus

$(LIBFT) :
	make -C ./libft

%.o : %.c
	$(CC) $(CFLAGS) -I. -c $<

clean :
	make clean -C ./libft
	rm -f $(OBJS)
	rm -f $(OBJS2)
	rm -f bonus

fclean : clean
	make fclean -C ./libft
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re