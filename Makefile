NAME = libftprintf.a
HEADER = ft_printf.h

SRCS = 	ft_printf.c \
		ft_printf_parser.c \
		ft_printf_utils.c

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
RM = rm -f
AR = ar rc

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $^

%.o: %.c $(HEADER) 
	$(CC) $(CFLAGS) $<

clean: 
	$(RM) $(OBJS) $(AR)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re