NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror -g
SRCS = ft_printf.c ft_printhex.c ft_printnum.c ft_printp.c
OBJS = $(SRCS:.c=.o)

%.o: %.c
	cc -c $(FLAGS) -g -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re 
