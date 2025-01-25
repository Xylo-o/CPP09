NAME := btc
CC := c++
CCFLAGS := -Werror -Wextra -Wall -std=c++17

SRC := main.cpp \
	BitcoinExchange.cpp

OBJ := $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp compile_message
	@$(CC) $(CCFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CCFLAGS) $^ -o $@
	@echo "$(GREEN)Compiled successfully$(NC)"

clean:
	@echo "$(YELLOW)Cleaning the object files$(NC)"
	@rm -rf $(OBJ)

fclean:
	@echo "$(RED)Cleaning the whole program$(NC)"
	@rm -rf $(OBJ) $(NAME)

re: fclean all

compile_message:
	@echo "$(YELLOW)C$(GREEN)o$(RED)m$(YELLOW)p$(GREEN)i$(RED)l$(YELLOW)i$(GREEN)n$(RED)g$(YELLOW).$(GREEN).$(RED).$(NC)"

RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
NC := \033[0m

.PHONY: all clean fclean re