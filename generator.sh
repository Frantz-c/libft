# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    generator.sh                                     .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/04/25 13:25:48 by mhouppin     #+#   ##    ##    #+#        #
#    Updated: 2019/07/12 16:58:20 by mhouppin    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #
#!/bin/zsh

FILES=$(find -f . \( -type f \) | grep '\.c' | sed 's/\.\///g')

rm Makefile

echo "NAME     := libft.a" >> Makefile
echo >> Makefile
echo "SOURCES  := \\" >> Makefile

for FILE in $FILES; do
	echo "\t$FILE \\" >> Makefile
done

echo "\nCOMPILE  := gcc\n\nifneq (\$(shell which gcc-8),)\n\tCOMPILE  := gcc-8\nendif" >> Makefile
echo "ifneq (\$(shell which gcc-9),)\n\tCOMPILE  := gcc-9\nendif" >> Makefile
echo "\nPREPROCESS := \$(SOURCES:%.c=objects/%.c)" >> Makefile
echo "ASSEMBLY := \$(SOURCES:%.c=objects/%.s)" >> Makefile
echo "OBJECTS  := \$(SOURCES:%.c=objects/%.o)" >> Makefile
echo "OPTIMIZE := -O3 -march=native -fno-builtin -fno-stack-protector -fopt-info-optall" >> Makefile
echo "ERRORS   := -Wall -Wextra -Werror\n\nall: \$(NAME)\n\n\$(NAME): objects \$(PREPROCESS) \$(ASSEMBLY) \$(OBJECTS)" >> Makefile
echo "\tar -rc \$@ \$(OBJECTS)\n\tranlib \$@\n\nobjects:\n\tmkdir -p \$@/vector \$@/bytearray\n" >> Makefile
echo "objects/%.c: %.c libft.h\n\t\$(COMPILE) \$(ERRORS) -E -o \$@ \$<\n" >> Makefile
echo "objects/%.s: objects/%.c\n\t\$(COMPILE) \$(ERRORS) \$(OPTIMIZE) -S -o \$@ \$<\n" >> Makefile
echo "objects/%.o: objects/%.s\n\t\$(COMPILE) -c -o \$@ \$<\n" >> Makefile
echo "clean:\n\trm -rf objects\n\nfclean: clean\n\trm -f \$(NAME)\n\nre: fclean all\n" >> Makefile
echo "rebuild: fclean\n\t@./generator.sh\n\n.PHONY: all clean fclean re rebuild" >> Makefile
#echo ":Stdheader\n:x" | vim Makefile
