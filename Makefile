SRCS = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

SRC_PATH = ./

SRC_NAME =	ft_display.c ft_is_specifier.c ft_lst.c \
			ft_flag.c ft_lst.c ft_del.c \
			ft_utils.c ft_new.c ft_int.c\
			ft_str.c ft_hexa.c ft_int.c\
			ft_per.c ft_utils_bis.c printf.c\

OBJS_LIBFT =	ft_memset.o ft_bzero.o ft_memcpy.o \
			ft_memccpy.o ft_memmove.o ft_memchr.o \
			ft_memcmp.o ft_strlen.o ft_isalpha.o \
			ft_isdigit.o ft_isalnum.o ft_isascii.o \
			ft_isprint.o ft_toupper.o ft_tolower.o \
			ft_strchr.o ft_strrchr.o ft_strncmp.o \
			ft_strlcpy.o ft_strlcat.o ft_strnstr.o \
			ft_atoi.o ft_calloc.o ft_strdup.o \
			ft_substr.o ft_strjoin.o ft_strtrim.o \
			ft_split.o ft_itoa.o ft_strmapi.o\
			ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o \
			ft_putnbr_fd.o ft_u_itoa.o ft_lstmap.o \
			ft_lstnew.o ft_lstadd_front.o ft_lstsize.o \
			ft_lstlast.o ft_lstadd_back.o ft_lstdelone.o \
			ft_lstclear.o ft_lstiter.o ft_int_hexa.o \
			ft_pointer_hexa.o ft_free.o\

OBJS = ${SRCS:.c=.o}

LIBFT_DIR = libft

NAME = libftprintf.a

HEADER = printf.h

CC = clang

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -fPIE

.c.o: 
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			@(cd $(LIBFT_DIR) && $(MAKE))
			ar rc ${NAME} ${OBJS} $(addprefix $(LIBFT_DIR)/, $(OBJS_LIBFT))

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY =	all clean fclean re
