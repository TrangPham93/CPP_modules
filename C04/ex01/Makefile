# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/10 21:18:16 by trpham            #+#    #+#              #
#    Updated: 2025/09/11 14:18:12 by trpham           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++20

# Directories
OBJ_DIR		=./objs
 
# Source files
SOURCES		= main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
HEADERS		= Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp

# Executables
NAME		= animal

# Object files
OBJECTS		= $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Target
all			: $(NAME)

$(NAME)		: $(OBJECTS) 
	@$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "💻 Make succeeded."
	@echo "Usage: ./animal"

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