# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/05/15 09:40:41 by mhouppin     #+#   ##    ##    #+#        #
#    Updated: 2019/05/15 09:40:41 by mhouppin    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME     := libft.a

SOURCES  := \
	./ft_atoi.c \
	./ft_bzero.c \
	./ft_memccpy.c \
	./ft_memchr.c \
	./ft_memcmp.c \
	./ft_memcpy.c \
	./ft_memmove.c \
	./ft_memset.c \
	./ft_strcat.c \
	./ft_strchr.c \
	./ft_strcmp.c \
	./ft_strcpy.c \
	./ft_strdup.c \
	./ft_strlcat.c \
	./ft_strlen.c \
	./ft_strncat.c \
	./ft_strncmp.c \
	./ft_strncpy.c \
	./ft_strnlen.c \
	./ft_strnstr.c \
	./ft_strrchr.c \
	./ft_strstr.c \

OBJECTS  := $(SOURCES:%.c=%.o)
OPTIMIZE := -O3 -march=native -fno-builtin -fopt-info
ERRORS   := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar -rc $@ $^

%.o: %.c libft.h
	@gcc-8 $(ERRORS) $(OPTIMIZE) -c $<

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

rebuild: fclean
	@./generator.sh

.PHONY: all clean fclean re rebuild
