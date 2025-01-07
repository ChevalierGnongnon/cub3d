NAME = cub3d
CC = cc
CFLAGS = -I. -Wall -Wextra -Werror -g3
OFLAGS = -I. -Wall -Wextra -Werror -g3

# make re && clear && ./cub3d

FILES = core/display \
	core/free \
	core/main \
	parsing/check_components \
	parsing/error_parsing \
	parsing/file_process \
	parsing/flood_fill \
	parsing/get_map \
	parsing/get_value \
	parsing/images_check \
	parsing/map_check \
	parsing/rgb_parse \
	utils/char \
	utils/file_check \
	utils/map \
	utils/strings \

SOURCES = $(foreach f, $(FILES), sources/$(f).c)
OBJECTS = $(foreach f, $(FILES), objects/$(f).o)
LIBFT = libft/libft.a

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ 

objects/%.o: sources/%.c
	@mkdir -p $(dir $@)
	$(CC) $(OFLAGS) -c $< -o $@

$(LIBFT) :
	$(MAKE) -C libft

clean:
	rm -rf objects
	$(MAKE) -C libft fclean

fclean:
	rm -rf $(NAME) $(LIBFT) objects

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re
