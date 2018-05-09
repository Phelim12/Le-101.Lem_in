# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/08 18:11:02 by clcreuso     #+#   ##    ##    #+#        #
#    Updated: 2017/12/08 18:11:02 by clcreuso    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc

NAME = lem-in
		
C_FLAGS = -Wall -Wextra -Werror

DIR_INC = Includes/

DIR_SRC = Sources/

DIR_LIB = Libft/

NAME_SRC =	best_road_group.c find_ways_dijkstra.c parsing_anthill.c \
			print_solve.c tools_lem_in.c check_anthill.c main_lem_in.c \
			print_error.c realloc_lem_in.c tools_parsing.c alloc_lem_in.c \
			free_lem_in.c recover_value.c

SRC = $(addprefix $(DIR_SRC), $(NAME_SRC))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(DIR_LIB)
	@$(CC) $(C_FLAGS) $(OBJ) -L $(DIR_LIB) -lft -o $(NAME) 
	@echo "\033[0;32m✅️   make lem_in.\033[0m"

./%.o: ./%.c
	@$(CC) $(C_FLAGS) -I $(DIR_INC) -o $@ -c $< 
	@echo "\033[0;32m✅️   $@ created.\033[0m"

clean:
	@make clean -C $(DIR_LIB)
	@rm -f $(OBJ)
	@echo "\033[38;5;202m🗑️   clean lem_in.\033[0m" 

fclean: clean
	@make fclean -C $(DIR_LIB)
	@rm -f $(NAME)
	@echo "\033[38;5;196m🗑️   fclean lem_in.\033[0m" 

re: fclean all
	