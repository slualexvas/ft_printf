CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
LFLAGS = 
NAME = libftprintf.a
SOURCES = ft_atoi.c \
		  ft_bzero.c \
		  ft_isalnum.c \
		  ft_isalpha.c \
		  ft_isupper.c \
		  ft_islower.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_isprint.c \
		  ft_itoa.c \
		  ft_lstadd.c \
		  ft_lstdel.c \
		  ft_lstdelone.c \
		  ft_lstiter.c \
		  ft_lstmap.c \
		  ft_lstnew.c \
		  ft_lstprint.c \
		  ft_memalloc.c \
		  ft_memccpy.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_memcpy.c \
		  ft_memdel.c \
		  ft_memmove.c \
		  ft_memset.c \
		  ft_putchar.c \
		  ft_putchar_fd.c \
		  ft_putendl.c \
		  ft_putendl_fd.c \
		  ft_putnbr.c \
		  ft_putnbr_fd.c \
		  ft_putstr.c \
		  ft_putstr_fd.c \
		  ft_strcat.c \
		  ft_strchr.c \
		  ft_strclr.c \
		  ft_strcmp.c \
		  ft_strcpy.c \
		  ft_strdel.c \
		  ft_strdup.c \
		  ft_strequ.c \
		  ft_striter.c \
		  ft_striteri.c \
		  ft_strjoin.c \
		  ft_strlcat.c \
		  ft_strlen.c \
		  ft_strmap.c \
		  ft_strmapi.c \
		  ft_strncat.c \
		  ft_strncmp.c \
		  ft_strncpy.c \
		  ft_strnequ.c \
		  ft_strnew.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strsplit.c \
		  ft_strstr.c \
		  ft_strsub.c \
		  ft_strtrim.c \
		  ft_tolower.c \
		  ft_toupper.c \
		  get_next_line.c \
		  rgb.c \
		  solve_quadratic_equation.c \
		  vec.c \
		  vec_linear_ops.c \
		  vec_mult_scal.c \
		  vec_len.c \
		  vec_cos_angle.c \
		  split_res_free.c \
		  ft_is_int.c \
		  ft_intmax_to_str_base.c \
		  ft_join_n_symbols.c \
		  ft_longdouble_to_str_base.c \
		  ft_i_pow_n.c \
		  ft_printf.c \
		  ft_printf/parse_arg.c \
		  ft_printf/init_pav.c \
		  ft_printf/ft_printf_add_str_to_pav.c \
		  ft_printf/ft_printf_add_str_using_width.c \
		  ft_printf/ft_printf_c.c \
		  ft_printf/ft_printf_s.c \
		  ft_printf/ft_printf_di.c \
		  ft_printf/ft_printf_boux.c \
		  ft_printf/ft_printf_p.c \
		  ft_printf/ft_printf_uppercase_doucs.c \
		  ft_printf/ft_printf_f.c \
		  ft_printf/ft_printf_percent.c \
		  ft_printf/ft_printf_default.c \
		  ft_printf/ft_printf_v.c \

OBJECTS=$(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $@ $(OBJECTS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)

fclean:
	make clean
	rm -f $(NAME)

re:
	make fclean
	make
