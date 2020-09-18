SRCS = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

SRC_PATH = ./

SRC_NAME =	ft_display.c ft_is_specifier.c ft_lst.c \
			ft_flag.c ft_lst.c ft_del.c \
			ft_utils.c ft_new.c \

OBJS = ${SRCS:.c=.o}

NAME = printf.a

HEADER = printf.h

CC = clang

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -fPIE

.c.o: 
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY =	all clean fclean re
