# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 17:07:04 by seonjo            #+#    #+#              #
#    Updated: 2023/09/07 18:25:46 by seonjo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FDF
CC = cc
FLAGS = -L ./minilibx_mms_20210621 -lmlx -framework OpenGL -framework Appkit -lz
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) libft.a -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I . -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re