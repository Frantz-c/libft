# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    generator.sh                                     .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/04/25 13:25:48 by mhouppin     #+#   ##    ##    #+#        #
#    Updated: 2019/06/12 09:24:39 by mhouppin    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #
#!/bin/zsh

FILES=$(find -f . \( -type f \) | grep '\.c')

rm Makefile

echo "NAME     := libft.a" >> Makefile
echo >> Makefile
echo "SOURCES  := \\" >> Makefile

for FILE in $FILES; do
	echo "\t$FILE \\" >> Makefile
done

echo "\nCOMPILE  := gcc\n\nifneq (\$(shell which gcc-8),)\n\tCOMPILE  := gcc-8\nendif" >> Makefile
echo "ifneq (\$(shell which gcc-9),)\n\tCOMPILE  := gcc-9\nendif" >> Makefile
echo "\nOBJECTS  := \$(SOURCES:%.c=%.o)\nOPTIMIZE := -O3 -march=native -fno-builtin" >> Makefile
echo "ERRORS   := -Wall -Wextra -Werror\n\nall: \$(NAME)\n\n\$(NAME): \$(OBJECTS)" >> Makefile
echo "\tar -rc \$@ \$^\n\tranlib \$@\n\n%.o: %.c libft.h\n\t\$(COMPILE) \$(ERRORS) \$(OPTIMIZE) -c -o \$@ \$<\n" >> Makefile
echo "clean:\n\trm -f \$(OBJECTS)\n\nfclean: clean\n\trm -f \$(NAME)\n\nre: fclean all\n" >> Makefile
echo "rebuild: fclean\n\t@./generator.sh\n\n.PHONY: all clean fclean re rebuild" >> Makefile
#echo ":Stdheader\n:x" | vim Makefile
