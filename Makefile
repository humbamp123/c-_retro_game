# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/03 19:10:41 by gguiulfo          #+#    #+#              #
#    Updated: 2017/07/09 12:24:59 by gguiulfo         ###   ########.fr        #
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
CLASSFILES	:= Character.class Player.class Enemy.class Game.class Asteroids.class
FILES				:= $(addprefix classes/, $(CLASSFILES)) $(SRCFILES)
SRC					:= $(addprefix $(SRCDIR)/, $(addsuffix .cpp, $(FILES)))
OBJ					:= $(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(SRC:.cpp=.o))
CLASSHDRS		:= $(addsuffix .hpp, $(CLASSFILES))
# INCHDRS			:=
HDRS				:= $(addprefix src/classes/, $(CLASSHDRS))
LIBS				:=

#
NB			=	$(words $(FILES))
INDEX		=	0
LEN_NAME	=	`printf "%s" $(NAME) |wc -c`
DELTA		=	$$(echo "$$(tput cols)-31-$(LEN_NAME)"|bc)
SHELL		:= /bin/bash

.PHONY = all format clean fclean re
# Rules
all:
	@$(MAKE) -j $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.cpp Makefile | $(OBJDIR)
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval TO_DO=$(shell echo $$((20-$(INDEX)*20/$(NB) - 1))))
	@$(eval COLOR=$(shell list=(160 196 202 208 215 221 226 227 190 154 118 82 46); index=$$(($(PERCENT) * $${#list[@]} / 100)); echo "$${list[$$index]}"))
	@printf "\r\033[38;5;%dm⌛ [%s]: %2d%% `printf '█%.0s' {0..$(DONE)}`%*s❙%*.*s\033[0m\033[K" $(COLOR) $(NAME) $(PERCENT) $(TO_DO) "" $(DELTA) $(DELTA) "$(shell echo "$@" | sed 's/^.*\///')"
	@mkdir -p $(dir $@)
	@$(CXX) -c $(CXXFLAGS) $< -o $@
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

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
