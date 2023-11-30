NAME = libftprintf.a

SOURCES = ft_printf.c \
	  ft_checkcase.c \
	  ft_eval_format.c \
	  ft_itoabase.c \
	  ft_left_cs.c \
	  ft_nbrlen.c \
	  ft_print_char.c \
	  ft_print_hexal.c \
	  ft_print_hexau.c \
	  ft_print_int.c \
	  ft_print_ptr.c \
	  ft_print_str.c \
	  ft_print_uint.c \
	  ft_putnbr.c \
	  ft_right_cs.c \
	  ft_unbrlen.c

OBJETS = ${SOURCES:.c=.o}

LIBFTPATH = ./libft

LIBFTNAME = libft.a

HEADER = ft_printf.h

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

bonus: all

${NAME}: makelibft ${OBJETS}
	ar -rcs ${NAME} ${OBJETS} ${HEADER}

makelibft:
	make -C ${LIBFTPATH}
	cp ${LIBFTPATH}/${LIBFTNAME} ${NAME}

clean:
	rm -f ${OBJETS}
	cd ${LIBFTPATH} && make clean

fclean: clean
	rm -f ${NAME}
	cd ${LIBFTPATH} && make fclean

re: fclean all

.PHONY: all clean fclean re
