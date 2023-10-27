# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 17:19:09 by mpoussie          #+#    #+#              #
#    Updated: 2023/10/27 18:55:48 by mpoussie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g3 -pthread -I ./includes/

SRCS =	src/utils/time.c \
		src/utils/ft_atoi.c \
		src/utils/ft_usleep.c \
		src/utils/ft_isdigit.c \
		src/utils/ft_message.c \
		src/action/p_check_death.c \
		src/action/p_is_dead.c \
		src/action/p_take_fork__eat.c \
		src/action/p_sleep_think.c \
		src/init/init_philo.c \
		src/init/init_data.c \
		src/init/init_thread.c \
		src/init/init_action.c \
		src/main.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re