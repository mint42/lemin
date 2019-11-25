# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/03 06:37:10 by rreedy            #+#    #+#              #
#    Updated: 2019/10/16 12:00:01 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

<<<<<<< HEAD
include config.mk

SRCS := $(foreach src_dir, $(SRC_DIRS), $(wildcard $(src_dir)/*.c))
OBJS := $(patsubst %.c,%.o,$(SRCS))
=======
NAME := lem-in
LIB := libft/libft.a

OBJS := $(patsubst %.c,%.o,$(wildcard ./srcs/*.c))
>>>>>>> 50abeb15d509693e6ea14d82f7db77008614b059

LIB := $(LIB_DIR)/$(LIB_NAME)
MAKE_LIB := make -C $(LIB_DIR) -f $(LIB_MAKEFILE) --no-print-directory

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
<<<<<<< HEAD
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

$(LIB):
	@- $(MAKE_LIB) all

clean:
	@- $(RM) $(OBJS)
	@- $(MAKE_LIB) clean

fclean: clean
	@- $(RM) $(NAME)
	@- $(MAKE_LIB) fclean
=======
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LFLAGS)

$(LIB):
	@- make -C libft/ all

debug: fclean
	$(CC) $(CFLAGS) -g $(OBJS) -o $(NAME) $(LFLAGS)
	@- make -C libft/ debug

clean:
	@- $(RM) $(OBJS)
	@- make -C libft/ clean

fclean: clean
	@- $(RM) $(NAME)
	@- make -C libft/ fclean
>>>>>>> 50abeb15d509693e6ea14d82f7db77008614b059

re: fclean all
