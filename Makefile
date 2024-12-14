# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nranna <nranna@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 12:06:45 by nranna            #+#    #+#              #
#    Updated: 2024/12/14 16:50:58 by nranna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CCFLAGS = -Wall -Wextra -Werror -pthread -g
NAME = executable
GREEN = \033[1;32m
WHITE = \033[1;37m

# PROGRAM FILES CHANGE SRC LATER
SRC = main.c thread.c mutex_utils.c create_table.c utils.c time.c routines.c waiter.c routines2.c
INCLUDE = h_philo.h

OBJ = $(SRC:.c=.o)

all: $(NAME)
%.o: %.c $(INCLUDE)
	@$(CC) $(CCFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	@echo "$(WHITE)\nCREATING [$(NAME)]..."
	@$(CC) $(CCFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)[$(NAME)] OK :)$(WHITE)\n"
clean:
	@echo "$(WHITE)\nCLEANING OBJECT FILES..."
	@rm -f $(OBJ)
	@echo "$(GREEN)OK. :)$(WHITE)\n"

fclean: clean
	@echo "$(WHITE)\nCLEANING [$(NAME)]..."
	@rm -f $(NAME)
	@echo "$(GREEN)OK. :)$(WHITE)\n"

re: fclean all

.PHONY: all clean fclean re
