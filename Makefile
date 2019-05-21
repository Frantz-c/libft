NAME     := libft.a

SOURCES  := \
	./ft_atoi.c \
	./ft_bzero.c \
	./ft_isalnum.c \
	./ft_isalpha.c \
	./ft_isascii.c \
	./ft_isdigit.c \
	./ft_isprint.c \
	./ft_memalloc.c \
	./ft_memccpy.c \
	./ft_memchr.c \
	./ft_memcmp.c \
	./ft_memcpy.c \
	./ft_memdel.c \
	./ft_memmove.c \
	./ft_memset.c \
	./ft_strcat.c \
	./ft_strchr.c \
	./ft_strclr.c \
	./ft_strcmp.c \
	./ft_strcpy.c \
	./ft_strdel.c \
	./ft_strdup.c \
	./ft_striter.c \
	./ft_striteri.c \
	./ft_strlcat.c \
	./ft_strlen.c \
	./ft_strncat.c \
	./ft_strncmp.c \
	./ft_strncpy.c \
	./ft_strnew.c \
	./ft_strnlen.c \
	./ft_strnstr.c \
	./ft_strrchr.c \
	./ft_strstr.c \
	./ft_tolower.c \
	./ft_toupper.c \

COMPILE  := gcc

ifneq ($(shell which gcc-8),)
	COMPILE  := gcc-8
endif
ifneq ($(shell which gcc-9),)
	COMPILE  := gcc-9
endif

OBJECTS  := $(SOURCES:%.c=%.o)
OPTIMIZE := -O3 -march=native -fno-builtin
ERRORS   := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rc $@ $^

%.o: %.c libft.h
	$(COMPILE) $(ERRORS) $(OPTIMIZE) -c $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

rebuild: fclean
	@./generator.sh

.PHONY: all clean fclean re rebuild
