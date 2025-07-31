# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/31 11:32:17 by trpham            #+#    #+#              #
#    Updated: 2025/07/31 11:59:26 by trpham           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# Directories
SRC_DIR		= ./srcs
OBJ_DIR		=./objs
 
# Source files
HEADERS		= Megaphone.hpp

SOURCES		= $(SRC_DIR)/Megaphone.cpp

# Executables
NAME		= megaphone

# Object files
OBJECTS		= $(patsubst($(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o), $(SOURCES))

# Target
all			: $(NAME)

$(NAME)		: $(OBJECTS)
	@$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@
	@echo "💻 Make succeeded."

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean		:
	@if [ -d $(OBJ_DIR) ]; then \
		rm -rf $(OBJ_DIR); \
		echo "🧹 Cleaned object files."; \
	else \
		echo "🧼 Nothing to clean in object files."; \
	fi

fclean		: clean
	@if [ -f $(NAME) ]; then \
		rm -f  $(NAME); \
		echo "🧹🔥 Removed executable."; \
	else \
		echo "🧼 No executable to remove."; \
	fi

re			: fclean all

.PHONY		: all clean fclean re