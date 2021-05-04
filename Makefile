# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avogt <avogt@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/18 15:12:40 by avogt             #+#    #+#              #
#    Updated: 2021/05/03 16:57:23 by avogt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER_NAME = checker
PUSH_SWAP_NAME = push_swap

COMMON_FILES = error.c \
				free.c \
				check.c \
				stack.c \
				swap.c \
				push.c \
				rotate.c \
				reverse_rotate.c \
				stack_len.c \
				operation.c
				
CHECKER_FILES = checker_main.c \
				parse_operations.c \
				check_duplicates_ck.c
				
PUSH_SWAP_FILES = push_swap_main.c \
				helper.c \
				refresh_helper.c \
				sort_stack.c \
				sort.c \
				sort_many.c \
				check_duplicates_ps.c

FOLDER_CHECKER = checker_program
FOLDER_PUSH_SWAP = push_swap_program
FOLDER_COMMON = ps_common
FOLDER_SOURCES = srcs

SOURCES_CHECKER = $(addprefix $(FOLDER_CHECKER)/,$(addprefix $(FOLDER_SOURCES)/,$(CHECKER_FILES)))
SOURCES_COMMON = $(addprefix $(FOLDER_COMMON)/,$(addprefix $(FOLDER_SOURCES)/,$(COMMON_FILES)))
SOURCES_PUSH_SWAP = $(addprefix $(FOLDER_PUSH_SWAP)/,$(addprefix $(FOLDER_SOURCES)/,$(PUSH_SWAP_FILES)))

OBJS_PUSH_SWAP = $(SOURCES_PUSH_SWAP:.c=.o)
OBJS_CHECKER = $(SOURCES_CHECKER:.c=.o)
OBJS_COMMON = $(SOURCES_COMMON:.c=.o)

CC = gcc $(CFLAGS)
CFLAGS = -Wall -Werror -Wextra
MLFT = libft_mini
LIBMLFT = $(addprefix $(MLFT)/,libftmini.a)

all : $(CHECKER_NAME) $(PUSH_SWAP_NAME)

$(PUSH_SWAP_NAME) : $(OBJS_COMMON) $(OBJS_PUSH_SWAP)
	@make -s -C $(MLFT)
	@$(CC) $(SOURCES_PUSH_SWAP) $(SOURCES_COMMON) $(LIBMLFT) -o $(PUSH_SWAP_NAME)

$(CHECKER_NAME): $(OBJS_COMMON) $(OBJS_CHECKER)
	@make -s -C $(MLFT)
	@$(CC) $(SOURCES_CHECKER) $(SOURCES_COMMON) $(LIBMLFT) -o $(CHECKER_NAME)

%.o: %.c
	@$(CC) -o $@ -c $<

clean:
	@make -s -C $(MLFT) clean
	@rm -f $(OBJS_CHECKER)
	@rm -f $(OBJS_PUSH_SWAP)
	@rm -f $(OBJS_COMMON)

fclean: clean
	@make -s -C $(MLFT) fclean
	@rm -f $(CHECKER_NAME)
	@rm -f $(PUSH_SWAP_NAME)

re: fclean all

.PHONY: all clean fclean re