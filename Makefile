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

include config.mk

SRCS := $(foreach src_dir, $(SRC_DIRS), $(wildcard $(src_dir)/*.c))
OBJS := $(patsubst %.c,%.o,$(SRCS))

LIB := $(LIB_DIR)/$(LIB_NAME)
MAKE_LIB := make -C $(LIB_DIR) -f $(LIB_MAKEFILE) --no-print-directory

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

$(LIB):
	@- $(MAKE_LIB) all

clean:
	@- $(RM) $(OBJS)
	@- $(MAKE_LIB) clean

fclean: clean
	@- $(RM) $(NAME)
	@- $(MAKE_LIB) fclean

re: fclean all
