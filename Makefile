CC = cc
CFLAGS = -Wall -Wextra -Werror -g 
LDFLAGS = -lm

MLXFLAGS = -lmlx -lXext -lX11 

NAME = cub3D

SRC_DIR = source/
PARSE = source/parser/

SRCS =	${PARSE}check_map_borders_player.c\
		${PARSE}config_file_utils.c\
		${PARSE}freeing_functions.c\
		${PARSE}freeing_utils.c\
		${PARSE}map_validation_utils.c\
		${PARSE}parsing.c\
		${PARSE}store_map.c\
		${PARSE}validate_CF.c\
		${PARSE}validate_colors.c\
		${PARSE}validate_file_textures.c\
		${PARSE}validate_map.c\
		${PARSE}validate_NSEW.c\
		${PARSE}validate_up_down_right_left.c\
\
		${SRC_DIR}draw_map.c\
		${SRC_DIR}drawing.c\
		${SRC_DIR}freeing_utils.c\
		${SRC_DIR}freeing.c\
		${SRC_DIR}handelkey.c\
		${SRC_DIR}handelkey1.c\
		${SRC_DIR}init_utils.c\
		${SRC_DIR}init.c\
		${SRC_DIR}key_utils.c\
		${SRC_DIR}main.c\
		${SRC_DIR}raycast_utils.c\
		${SRC_DIR}raycast.c\

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_LIB = $(LIBFT_DIR)/printf/libftprintf.a

INCLUDES = -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(PRINTF_LIB) $(MLXFLAGS) $(LDFLAGS) $(INCLUDES)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
