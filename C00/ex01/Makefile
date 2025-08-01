# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/01 15:32:19 by trpham            #+#    #+#              #
#    Updated: 2025/08/01 16:39:06 by trpham           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++20

# Directories
SRC_DIR		= ./srcs
OBJ_DIR		=./objs
 
# Source files
HEADERS		= Contact.hpp PhoneBook.hpp
SOURCES		= $(SRC_DIR)/Contact.cpp \
				$(SRC_DIR)/PhoneBook.cpp

# Executables
NAME		= phonebook

# Object files
OBJECTS		= $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Target
all			: $(NAME)

$(NAME)		: $(OBJECTS)
	@$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "💻 Make succeeded."

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.cpp $(HEADERS)
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