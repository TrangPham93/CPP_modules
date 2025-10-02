# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/10 21:18:16 by trpham            #+#    #+#              #
#    Updated: 2025/10/02 21:30:43 by trpham           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++20

# Directories
OBJ_DIR		=./objs
 
# Source files
HEADERS		= Array.hpp Array.tpp
SOURCES		= main.cpp

# Executables
NAME		= array

# Object files
OBJECTS		= $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Target
all			: $(NAME)

$(NAME)		: $(OBJECTS) 
	@$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "💻 Make succeeded."
	@echo "Usage: ./array"

$(OBJ_DIR)/%.o:	%.cpp $(HEADERS)
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

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