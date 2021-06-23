NAME = libftprintf.a

SRCS =  printf/ft_printf.c \
		printf/ft_parse.c \
		descriptors/ft_descriptors.c \
		descriptors/ft_un.c \
		descriptors/ft_int.c \
		descriptors/ft_hex.c \
		descriptors/ft_chr.c \
		descriptors/ft_str.c \
		descriptors/ft_point.c \
		descriptors/ft_perc.c \
		sources/ft_int_to_chr.c \
		sources/ft_len_num_hex.c \
		sources/ft_len_num_point.c \
		sources/ft_len_num_un.c \
		sources/ft_len_num.c \
		sources/ft_putchar_ln.c \
		sources/ft_putnbr_hex.c \
		sources/ft_putnbr.c \
		sources/ft_putpoint_ln.c \
		sources/ft_strlen.c \
		sources/ft_isdigit.c 

SRC_0 = ft_chr.o ft_descriptors.o ft_hex.o \
		ft_int_to_chr.o ft ft_int.o ft_isdigit.o \
		ft_len_num_hex.o ft_len_num_point.o ft_len_num_un.o \
		ft_len_num.o ft_parse.o ft_perc.o ft_point.o ft_printf.o \
		ft_putchar_ln.o ft_putnbr_hex.o ft_putnbr.o \
		ft_putpoint_ln.o ft_str.o ft_strlen.o ft_un.o

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -c $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(OBJS)
	rm -rf $(SRC_0)

fclean : clean
	rm -rf $(NAME)

re : fclean all