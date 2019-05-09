# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/05/09 15:37:55 by mhouppin     #+#   ##    ##    #+#        #
#    Updated: 2019/05/09 15:37:55 by mhouppin    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME     := libft.a

SOURCES  := \

OBJECTS  := $(SOURCES:%.c=%.o)
OPTIMIZE := -O3 -fno-stack-protector -fno-builtin
ERRORS   := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rc $@ $^

%.o: %.c
	gcc-8 -Wall -Wextra -Wpedantic -Werror -O3 -fno-stack-protector -fno-builtin -c -o $@ $<

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

rebuild: fclean
	./generator.sh

.PHONY: all clean fclean re rebuild
