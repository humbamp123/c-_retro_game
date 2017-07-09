# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apineda <apineda@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/03 19:10:41 by gguiulfo          #+#    #+#              #
#    Updated: 2017/07/08 18:37:10 by apineda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Name
NAME			:= ft_retro

# Compiler Info
CXX				:= clang++
CXXFLAGS 	+= -std=c++98
CXXFLAGS	+= -Wall -Wextra -Werror
LDFLAGS 	+= -Wall -Wextra -Werror -lncurses

# Files
SRCDIR			:= src/
OBJDIR			:= obj/
SRCFILES		:= main
CLASSFILES	:= Character.class Player.class Enemy.class Game.class
FILES				:= $(addprefix classes/, $(CLASSFILES)) $(SRCFILES)
SRC					:= $(addprefix $(SRCDIR)/, $(addsuffix .cpp, $(FILES)))
OBJ					:= $(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(SRC:.cpp=.o))
CLASSHDRS		:= $(addsuffix .hpp, $(CLASSFILES))
# INCHDRS			:=
HDRS				:= $(addprefix src/classes/, $(CLASSHDRS))
LIBS				:=

.PHONY = all format clean fclean re
# Rules
all:
	@$(MAKE) -j $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.cpp Makefile | $(OBJDIR)
	@mkdir -p $(dir $@)
	@$(CXX) -c $(CXXFLAGS) $< -o $@

$(NAME): $(OBJ) $(HDRS)
	@$(CXX) $(LDFLAGS) $(OBJ) $(LIBS) -o $@
	@printf "\r\033[38;5;340m✓ Compiled $(NAME)\033[0m\033[K\n";

format: $(SRC) $(HDRS)
	@clang-format -style=Google -i $^

clean:
	@if [ -e $(OBJDIR) ]; \
	then \
		rm -rf $(OBJDIR); \
		printf "\r\033[38;5;190m✗ clean -> $(NAME).\033[0m\033[K\n"; \
	fi;

fclean: clean
	@if [ -e $(NAME) ]; \
	then \
		rm -rf $(NAME); \
		printf "\r\033[38;5;196m✗ Removed $(NAME)\033[0m\033[K\n"; \
	fi;

re: fclean all
