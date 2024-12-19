NAME = cub3d
CC = cc
CFLAGS = -I. -Wall -Wextra -Werror -g3
OFLAGS = -I. -Wall -Wextra -Werror -g3

# make re && clear && ./cub3d

FILES = core/main \
	core/display \
	core/free \
	parsing/check_components \
	parsing/error_parsing \
	parsing/get_map \
	parsing/get_value \
	parsing/file_process \
	parsing/rgb_check \
	utils/char \
	utils/map \
	utils/file_check \
	utils/strings

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
