# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tytang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 12:24:33 by tytang            #+#    #+#              #
#    Updated: 2022/11/21 12:56:27 by tytang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
FLAGES = -Wall -Wextra -Werror -g
RM = rm -f
LINKS = -I./inlcudes -L./libft -lft -L./mlx -lmlx -framework OpenGL \
		-framework Appkit

SRCS_DIR = sources/

FILES = Main \
		Mandlebrot \
		Utils \
		Event \

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	@$(MAKE) re -C ./libft
	@$(MAKE) -C ./mlx
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LINKS)

$(OBJS): %.o : %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)
	@$(MAKE) -C ./libft clean
	@$(MAKE) -C ./mlx clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: re fclean clean
