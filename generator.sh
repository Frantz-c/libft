# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    generator.sh                                     .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/04/25 13:25:48 by mhouppin     #+#   ##    ##    #+#        #
#    Updated: 2019/05/09 16:48:25 by mhouppin    ###    #+. /#+    ###.fr      #
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

echo "\nOBJECTS  := \$(SOURCES:%.c=%.o)" >> Makefile
echo "OPTIMIZE := -O3 -fno-stack-protector -fno-builtin" >> Makefile
echo "ERRORS   := -Wall -Wextra -Wpedantic -Werror" >> Makefile
echo >> Makefile
echo "all: \$(NAME)" >> Makefile
echo >> Makefile
echo "\$(NAME): \$(OBJECTS)" >> Makefile
echo "\tar -rc \$@ \$^" >> Makefile
echo >> Makefile
echo "%.o: %.c" >> Makefile
echo "\tgcc-8 \$(ERRORS) \$(OPTIMIZE) -c -o \$@ \$<" >> Makefile
echo >> Makefile
echo "clean:" >> Makefile
echo "\trm -rf \$(OBJECTS)" >> Makefile
echo >> Makefile
echo "fclean: clean" >> Makefile
echo "\trm -f \$(NAME)" >> Makefile
echo >> Makefile
echo "re: fclean all" >> Makefile
echo >> Makefile
echo "rebuild: fclean" >> Makefile
echo "\t./generator.sh" >> Makefile
echo >> Makefile
echo ".PHONY: all clean fclean re rebuild" >> Makefile
echo ":MyStdheader\n:x" | vim Makefile >& /dev/null
