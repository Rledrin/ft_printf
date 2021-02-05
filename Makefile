# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lacruype <lacruype@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 12:37:07 by lacruype          #+#    #+#              #
#    Updated: 2019/11/12 17:27:32 by lacruype         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ft_printf.h

SRCS =	ft_addrconv.c	ft_converse.c	ft_hexaconv.c	ft_nbr.c	ft_parsing.c	ft_string.c		ft_utils.c		ft_printf.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

RM = /bin/rm -f

.c.o:
	gcc $(FLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean