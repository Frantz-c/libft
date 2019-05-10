# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    generator.sh                                     .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/04/25 13:25:48 by mhouppin     #+#   ##    ##    #+#        #
#    Updated: 2019/05/10 09:54:42 by mhouppin    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #
#!/bin/zsh

FILES=$(find -f . | grep '\.c')

rm Makefile

echo "NAME     := libft.a" >> Makefile
echo >> Makefile
echo "SOURCES  := \\" >> Makefile

for FILE in $FILES; do
	echo "\t$FILE \\" >> Makefile
done

echo "\nOBJECTS  := \$(SOURCES:%.c=%.o)\nOPTIMIZE := -O3 -msse2 -mavx -fno-builtin" >> Makefile
echo "ERRORS   := -Wall -Wextra -Werror\n\nall: \$(NAME)\n\n\$(NAME): \$(OBJECTS)" >> Makefile
echo "\tar -rc \$@ \$^\n\n%.o: %.c libft.h\n\tgcc \$(ERRORS) \$(OPTIMIZE) -c \$<\n" >> Makefile
echo "clean:\n\trm -f \$(OBJECTS)\n\nfclean: clean\n\trm -f \$(NAME)\n\nre: fclean all\n" >> Makefile
echo "rebuild: fclean\n\t./generator.sh\n\n.PHONY: all clean fclean re rebuild" >> Makefile
