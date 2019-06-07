NAME     := libft.a

SOURCES  := \
	./ft_addbuf.c \
	./ft_addbuf_char.c \
	./ft_apply_width.c \
	./ft_atohex.c \
	./ft_atoi.c \
	./ft_atol.c \
	./ft_atooct.c \
	./ft_bzero.c \
	./ft_clean_format.c \
	./ft_crep.c \
	./ft_crepall.c \
	./ft_crrep.c \
	./ft_dprintf.c \
	./ft_explode.c \
	./ft_flt_add_demi.c \
	./ft_flt_get_dec.c \
	./ft_flt_get_int.c \
	./ft_flt_size.c \
	./ft_fmod.c \
	./ft_get_next_line.c \
	./ft_get_uint.c \
	./ft_inf_nan.c \
	./ft_int_set_precision.c \
	./ft_int_sharp.c \
	./ft_int_zero_padding.c \
	./ft_isalnum.c \
	./ft_isalpha.c \
	./ft_isascii.c \
	./ft_isdigit.c \
	./ft_islower.c \
	./ft_isprint.c \
	./ft_isspace.c \
	./ft_isupper.c \
	./ft_isxdigit.c \
	./ft_itoa.c \
	./ft_lstadd.c \
	./ft_lstdel.c \
	./ft_lstdelone.c \
	./ft_lstiter.c \
	./ft_lstmap.c \
	./ft_lstnew.c \
	./ft_lstpush.c \
	./ft_memalloc.c \
	./ft_memccpy.c \
	./ft_memchr.c \
	./ft_memcmp.c \
	./ft_memcpy.c \
	./ft_memcrep.c \
	./ft_memcrepall.c \
	./ft_memdel.c \
	./ft_memdup.c \
	./ft_memmem.c \
	./ft_memmove.c \
	./ft_mempcpy.c \
	./ft_memset.c \
	./ft_print_bin.c \
	./ft_print_chr.c \
	./ft_print_flt.c \
	./ft_print_hex.c \
	./ft_print_int.c \
	./ft_print_npt.c \
	./ft_print_oct.c \
	./ft_print_sci.c \
	./ft_print_str.c \
	./ft_print_uns.c \
	./ft_printconv.c \
	./ft_printf.c \
	./ft_putchar.c \
	./ft_putchar_fd.c \
	./ft_putendl.c \
	./ft_putendl_fd.c \
	./ft_putnbr.c \
	./ft_putnbr_fd.c \
	./ft_putstr.c \
	./ft_putstr_fd.c \
	./ft_realloc.c \
	./ft_skip.c \
	./ft_stpcpy.c \
	./ft_stpncpy.c \
	./ft_strcat.c \
	./ft_strchr.c \
	./ft_strchrnul.c \
	./ft_strclr.c \
	./ft_strcmp.c \
	./ft_strcpy.c \
	./ft_strcspn.c \
	./ft_strdel.c \
	./ft_strdup.c \
	./ft_strequ.c \
	./ft_striter.c \
	./ft_striteri.c \
	./ft_strjoin.c \
	./ft_strlcat.c \
	./ft_strlen.c \
	./ft_strmap.c \
	./ft_strmapi.c \
	./ft_strncat.c \
	./ft_strncmp.c \
	./ft_strncpy.c \
	./ft_strndup.c \
	./ft_strnequ.c \
	./ft_strnew.c \
	./ft_strnlen.c \
	./ft_strnstr.c \
	./ft_strrchr.c \
	./ft_strsplit.c \
	./ft_strspn.c \
	./ft_strstr.c \
	./ft_strsub.c \
	./ft_strswap.c \
	./ft_strtok.c \
	./ft_strtok_r.c \
	./ft_strtolower.c \
	./ft_strtoupper.c \
	./ft_strtrim.c \
	./ft_tablesize.c \
	./ft_tolower.c \
	./ft_toupper.c \
	./ft_ultoa_buf.c \
	./ft_uppercase.c \
	./ft_vdprintf.c \
	./ft_vprintf.c \
	./ft_wordcount.c \

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
	ranlib $@

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
