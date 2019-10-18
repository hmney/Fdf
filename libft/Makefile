# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmney <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/10 12:01:41 by hmney             #+#    #+#              #
#    Updated: 2018/11/05 20:06:38 by hmney            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = *c

OBJS = *.o

all: $(NAME)

$(NAME):
	@gcc -Wall -Werror -Wextra -I includes/ -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
