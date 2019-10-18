# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmney <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/20 14:09:05 by hmney             #+#    #+#              #
#    Updated: 2019/01/20 18:19:14 by hmney            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = Sources/events.c Sources/main.c Sources/storage.c Sources/trace_map.c Sources/transformations.c Sources/color.c

MLX_FLAGS =  -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

COMPILATION_FLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a

OBJS = Sources/*.o

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc -o $(NAME) $(SRCS) $(COMPILATION_FLAGS) $(MLX_FLAGS) $(LIBFT)

clean:
	@/bin/rm -f $(OBJS)
	@make clean -C libft/

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft/


re: fclean all

