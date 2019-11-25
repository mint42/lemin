# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    config.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 09:39:36 by rreedy            #+#    #+#              #
#    Updated: 2019/10/22 19:31:16 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := lemin

LIBRARY := ft
LIB_DIR := ./libft
LIB_NAME := libft.a
LIB_MAKEFILE := Makefile
LIB_INCLUDE_DIRS := $(LIB_DIR)/includes
LIB_INCLUDE_DIRS += $(LIB_DIR)/includes/ft_printf

SRC_DIRS := ./srcs

INCLUDE_DIRS := ./includes

CC := gcc
CFLAGS := -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += $(foreach include,$(INCLUDE_DIRS),-I$(include)) $(foreach lib_include,$(LIB_INCLUDE_DIRS),-I$(lib_include))
LDFLAGS := -L$(LIB_DIR) -l$(LIBRARY)
