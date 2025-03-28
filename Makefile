# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molamdao <molamdao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/28 15:19:37 by molamdao          #+#    #+#              #
#    Updated: 2025/03/28 15:26:21 by molamdao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo

HEADER = philo.h


SRCS =	 libft.c activity.c parsing.c philo.c routine_philo.c ./ft_printf/printf.c ./ft_printf/printf2.c 

OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -fsanitize=address -g 

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lreadline -o $(NAME)

$(OBJS):
	$(CC) $(CFLAGS)  -c ${@:.o=.c} -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re