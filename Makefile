NAME = cub3d
CC = cc
CFLAGS = -I. -Wall -Wextra -Werror -g3
OFLAGS = -I. -Wall -Wextra -Werror -g3

FILES = core/free \
	core/main \
	parsing/error_parsing \
	parsing/file_process \
	parsing/flood_fill \
	parsing/get_map \
	parsing/get_value \
	parsing/images_check \
	parsing/map_check \
	parsing/map_copy \
	parsing/rgb_parse \
	utils/char \
	utils/file_check \
	utils/map \
	utils/rgb \
	utils/strings \

SOURCES = $(foreach f, $(FILES), sources/$(f).c)
OBJECTS = $(foreach f, $(FILES), objects/$(f).o)
LIBFT = libft/libft.a

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm

objects/%.o: sources/%.c
	@mkdir -p $(dir $@)
	$(CC) $(OFLAGS) -c $< -o $@

$(LIBFT) :
	$(MAKE) -C libft

clean:
	rm -rf $(OBJECTS)
	$(MAKE) -C libft clean

fclean:
	rm -rf $(NAME) $(LIBFT) objects
	$(MAKE) -C libft fclean

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re
