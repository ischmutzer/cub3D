# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalkhal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 19:15:57 by amalkhal          #+#    #+#              #
#    Updated: 2023/09/15 19:16:03 by amalkhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIE -g

RM = /bin/rm -f

NAME = libft.a

HEADER = libft.h

SRCS =  ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
        ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
        ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c \
        ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
        ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_split.c gnl/get_next_line.c \
        ft_strcmp.c gnl/get_next_line_utils.c

#Build object files from .c files
OBJS = $(SRCS:.c=.o)

PRINTF_DIR = ./printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

#Execute when run make
all: $(NAME) $(PRINTF_LIB)

$(NAME): $(OBJS) $(HEADER)
	ar -rcs $(NAME) $(OBJS)

$(PRINTF_LIB):
	@echo "Making printf library..."
	$(MAKE) -C $(PRINTF_DIR)

#Remove object files
clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean

#Remove object files and static library
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

#Rebuild program
re: fclean all

#These targets are always executed
.PHONY: all clean fclean re
