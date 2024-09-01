# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/01 02:11:24 by user              #+#    #+#              #
#    Updated: 2024/09/01 17:30:33 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I includes
SRCS = 	src/main.c src/parsing.c src/utils.c src/swap.c src/rotate.c src/push.c \
		src/reverse_rotate.c src/push_swap.c src/small_sort.c src/radix_sort.c
OBJS = $(SRCS:.c=.o)

src/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJS) maker
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a ft_printf/libftprintf.a -o $(NAME)

all: $(NAME)

maker:
	@make -C ft_printf
	@make -C libft bonus

clean:
	@make clean -C ft_printf
	@make clean -C libft
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C ft_printf
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re