# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/05/09 16:48:29 by mhouppin     #+#   ##    ##    #+#        #
#    Updated: 2019/05/09 16:48:29 by mhouppin    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME     := libft.a

SOURCES  := \
	./ft_bzero.c \
	./ft_memset.c \

OBJECTS  := $(SOURCES:%.c=%.o)
OPTIMIZE := -O3 -fno-stack-protector -fno-builtin
ERRORS   := -Wall -Wextra -Wpedantic -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rc $@ $^

%.o: %.c
	gcc-8 $(ERRORS) $(OPTIMIZE) -c -o $@ $<

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

rebuild: fclean
	./generator.sh

.PHONY: all clean fclean re rebuild
