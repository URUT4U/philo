# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nranna <nranna@student.42.rio>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 12:06:45 by nranna            #+#    #+#              #
#    Updated: 2024/12/12 19:29:35 by nranna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CCFLAGS = -Wall -Wextra -Werror -pthread
NAME = executable
GREEN = \033[1;32m
WHITE = \033[1;37m

# PROGRAM FILES CHANGE SRC LATER
SRC = main.c thread_utils.c mutex_utils.c table_utils.c utils.c time.c
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
