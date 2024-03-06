SRCS = $(wildcard srcs/*.cpp)

NAME = module00

OBJS = $(SRCS:.cpp=.o)

CC = clang++ -Wall -Wextra -Werror -std=c++98

SHELL = zsh
AQUA = \033[0;96m
AQUA_BOLD = \033[1;96m
PURPLE = \033[0;95m
PURPLE_BOLD = \033[1;95m
GREEN = \033[0;92m
GREEN_BOLD = \033[1;92m
GREEN_UNDRLINE = \033[4;32m
RED = \033[0;91m
IRED = \033[0;31m
RED_BOLD = \033[1;91m
SAME_LINE = \033[0G\033[2K
RESET = \033[0m
YELLOW = \033[0;33m

%.o: %.cpp
	@$(CC) -c $< -o $@
	@echo -n "$(SAME_LINE)$(AQUA)Compiling $(AQUA_BOLD)$<$(RESET)"

all:		$(NAME)


$(NAME): $(OBJS)
	@echo
	@echo "$(PURPLE)Linking $(PURPLE)*.o into $(PURPLE_BOLD)$(NAME)$(RESET)"
	@$(CC) $(OBJS) -o $(NAME) 
	@echo "$(GREEN_BOLD)Done compiling $(GREEN_UNDERLINE)$(NAME)$(RESET)"

clean:
	@rm -f $(OBJS)
	@echo "$(YELLOW)$(NAME): $(RED)Removing $(IRED)*.o$(RESET)"

fclean:		clean
	@rm -f $(NAME)
	@echo "$(YELLOW)$(NAME): $(RED)Removing $(IRED)$(NAME)$(RESET)"

re:			fclean all

.PHONY:	all clean fclean re bonus