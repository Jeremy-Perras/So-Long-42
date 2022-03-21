# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperras <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 10:37:03 by jperras           #+#    #+#              #
#    Updated: 2022/03/21 09:33:38 by jperras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = so_long

SRCS = so_long.c ft_windows.c ft_image.c ft_hooks.c get_next_line.c get_next_line_utils.c

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

CC = gcc

CCDB = gcc -g

FLAGS = -Wall -Werror -Wextra 

LIBMLX = -L /usr/local/lib -lmlx 

LIBFT = -L libft -lft

LIBPF = -L printf -lftprintf

OTHER = -framework OpenGL -framework AppKit

.c.o:
		${CC} ${FLAGS} -I./includes  -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	make -C libft
	make -C printf
	$(CC) $(FLAGS) -o $(NAME) $(LIBMLX) $(LIBPF) $(LIBFT) $(OTHER) $(INCLUDES) $(OBJS)

all : $(NAME)


test :
	$(CC) $(FLAGS) -o $(NAME) $(LIBMLX) $(INCLUDES) $(OTHER) $(SRCS)

debug :
	$(CCB) $(FLAGS) -o $(NAME) $(INCLUDES) $(LIBMLX) $(OTHER) $(SRCS)

clean :
	make clean -C libft
	make clean -C printf
	rm -rf $(OBJS)

fclean : clean
	make fclean -C libft
	make fclean -C printf
	rm -rf $(NAME)

re : fclean all
	make re -C libft
	make re -C printf
