NAME = libftprintf.a

SOURCES = ft_printf.c \

OBJETS = ${SOURCES:.c=.o}

LIBFTPATH = ./libft

LIBFTNAME = libft.a

HEADER = ft_printf.h

CFLAGS = -Wall -Wextra -Werror


all: ${NAME}

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
