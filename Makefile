# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 17:07:04 by seonjo            #+#    #+#              #
#    Updated: 2023/09/13 17:49:47 by seonjo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FDF
CC = cc
FLAGS = -L. -lmlx -framework OpenGL -framework AppKit -lz
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(FLAGS) -L. -lft -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I. -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re