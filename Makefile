# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperras <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 10:37:03 by jperras           #+#    #+#              #
#    Updated: 2022/03/19 15:54:50 by jperras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = so_long

SRCS = so_long.c ft_windows.c ft_image.c ft_hooks.c

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

CC = gcc

CCDB = gcc -g

FLAGS = -Wall -Werror -Wextra 

LIBMLX = -L /usr/local/lib -lmlx 

OTHER = -framework OpenGL -framework AppKit

.c.o:
		${CC} ${FLAGS} -I./includes  -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(LIBMLX) $(OTHER) $(INCLUDES) $(OBJS)

all : $(NAME)


test :
	$(CC) $(FLAGS) -o $(NAME) $(LIBMLX) $(INCLUDES) $(OTHER) $(SRCS)

debug :
	$(CCB) $(FLAGS) -o $(NAME) $(INCLUDES) $(LIBMLX) $(OTHER) $(SRCS)

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
