# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/03 06:37:10 by rreedy            #+#    #+#              #
#    Updated: 2019/09/04 19:31:15 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEMIN := lem-in
LIB := libft/libft.a

LEMIN_OBJS := $(patsubst %.c,%.o,$(wildcard ./srcs/*.c))

CC := gcc
INCLUDES := -I./includes -I./libft/includes -I./libft/includes/ft_printf
CFLAGS += -g -Wall -Wextra -Werror $(INCLUDES)
LFLAGS += -L./libft -lft

.PHONY: all clean fclean re name

all: name

name: $(LEMIN)

$(LEMIN): $(LIB) $(LEMIN_OBJS)
	$(CC) $(CFLAGS) $(LEMIN_OBJS) -o $(LEMIN) $(LFLAGS)

$(LIB):
	@- make -C libft/ all

clean:
	@- $(RM) $(LEMIN_OBJS)
	@- make -C libft/ clean

fclean: clean
	@- $(RM) $(LEMIN)
	@- make -C libft/ fclean

re: fclean all
