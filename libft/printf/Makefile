# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalkhal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/24 14:08:13 by amalkhal          #+#    #+#              #
#    Updated: 2023/09/24 14:08:18 by amalkhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc

NAME	= libftprintf.a

SRCS	= ft_hex.c ft_num.c ft_pointer.c ft_printf.c ft_str_and_char.c

GFLAGS	= -Wall -Werror -Wextra

RM	= /bin/rm -f

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
