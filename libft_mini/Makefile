# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avogt <avogt@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/19 13:49:59 by avogt             #+#    #+#              #
#    Updated: 2021/03/19 14:27:31 by avogt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
SRC = ft_atoi.c \
		ft_putendl_fd.c \
		ft_split.c \
		get_next_line.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_strjoin.c \
		ft_strdup.c \
		ft_strsub.c \
		ft_strchr.c \
		ft_strdel.c \
		ft_strlen.c

OBJ = $(SRC:.c=.o)

NAME = libftmini.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

clean: 
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all re clean fclean