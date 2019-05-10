NAME     := libft.a

SOURCES  := \
	./ft_bzero.c \
	./ft_memccpy.c \
	./ft_memchr.c \
	./ft_memcmp.c \
	./ft_memcpy.c \
	./ft_memmove.c \
	./ft_memset.c \
	./ft_strcpy.c \
	./ft_strdup.c \
	./ft_strlen.c \

OBJECTS  := $(SOURCES:%.c=%.o)
OPTIMIZE := -O3 -msse2 -mavx -fno-builtin
ERRORS   := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rc $@ $^

%.o: %.c libft.h
	gcc-8 $(ERRORS) $(OPTIMIZE) -c $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

rebuild: fclean
	./generator.sh

.PHONY: all clean fclean re rebuild
