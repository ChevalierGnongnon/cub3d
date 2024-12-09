FILES = ft_atoi \
		ft_bzero \
		ft_calloc \
		ft_isalnum \
		ft_isalpha \
		ft_isascii \
		ft_isdigit \
		ft_isprint \
		ft_itoa \
		ft_memchr \
		ft_memcmp \
		ft_memcpy \
		ft_memmove \
		ft_memset \
		ft_strchr \
		ft_strdup \
		ft_strjoin \
		ft_strlcat \
		ft_strlcpy \
		ft_strlen \
		ft_strncmp \
		ft_strnstr \
		ft_strrchr \
		ft_strtrim \
		ft_substr \
		ft_tolower \
		ft_toupper \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_split \
		ft_striteri \
		ft_strmapi \
		ft_lstnew \
		ft_lstadd_front \
		ft_lstsize \
		ft_lstlast \
		ft_lstadd_back \
		ft_lstdelone \
		ft_lstclear \
		get_next_line_utils \
		get_next_line \
		ft_unsigned \
		ft_char \
		ft_decimal \
		ft_getsize \
		ft_hexa \
		ft_pointer \
		ft_printf \
		ft_string \
		ft_unsigned 
		
SRCS = $(foreach f, $(FILES),  sources/$(f).c)

OBJS = $(foreach f, $(FILES), objects/$(f).o)

CC = cc

CFLAGS = -Werror -Wextra -Wall -g3

NAME = libft.a

all : $(NAME)

objects/%.o: sources/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean : 
	$(RM) $(OBJS) 

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re