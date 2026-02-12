# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/26 16:32:12 by fgarnier          #+#    #+#              #
#    Updated: 2026/02/12 00:23:47 by fgarnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Moar_brainz!

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ_DIR = obj

SRC = Zombie.cpp zombieHorde.cpp main.cpp
      
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# 2. Linkage final
$(NAME): $(OBJ)
	@echo "Compilation de $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re