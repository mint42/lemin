# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/03 06:37:10 by rreedy            #+#    #+#              #
#    Updated: 2019/09/06 12:59:50 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEMIN := lem-in
LIB := libft/libft.a

LEMIN_OBJS := $(patsubst %.c,%.o,$(wildcard ./srcs/*.c))

CC := gcc
INCLUDES := -I./includes -I./libft/includes -I./libft/includes/ft_printf
CFLAGS += -Wall -Wextra -Werror $(INCLUDES)
LFLAGS += -L./libft -lft

.PHONY: all clean fclean re name

all: name

name: $(LEMIN)

$(LEMIN): $(LIB) $(LEMIN_OBJS)
	$(CC) $(CFLAGS) $(LEMIN_OBJS) -o $(LEMIN) $(LFLAGS)

$(LIB):
	@- make -C libft/ all

debug: fclean
	$(CC) $(CFLAGS) -g $(LEMIN_OBJS) -o $(LEMIN) $(LFLAGS)
	@- make -C libft/ debug

clean:
	@- $(RM) $(LEMIN_OBJS)
	@- make -C libft/ clean

fclean: clean
	@- $(RM) $(LEMIN)
	@- make -C libft/ fclean

re: fclean all
