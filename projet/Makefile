# COLOR MAKEFILE
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;36m
COLOUR_YELLOW = \033[0;93m
COLOUR_MAGENTA = \033[0;95m
END_COLOR=\033[0m

# VAR
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./include/

# RULES
all: libft server client

libft:
	@make -C ./include/libft

server: libft
	@$(CC) $(CFLAGS) -c server.c
	@$(CC) -I ./include server.o ./include/libft/libft.a $(CFLAGS) -o server
	@echo "$(COLOUR_GREEN)[SUCCESS]$(END_COLOR) server ready"

client: libft
	@$(CC) $(CFLAGS) -c client.c
	@$(CC) -I ./include client.o ./include/libft/libft.a $(CFLAGS) -o client
	@echo "$(COLOUR_GREEN)[SUCCESS]$(END_COLOR) client ready"

bonus: libft server_bonus client_bonus

server_bonus: libft
	@$(CC) $(CFLAGS) -c server_bonus.c
	@$(CC) -I ./include server_bonus.o ./include/libft/libft.a $(CFLAGS) -o server_bonus
	@echo "$(COLOUR_GREEN)[SUCCESS]$(END_COLOR) server bonus ready"

client_bonus: libft
	@$(CC) $(CFLAGS) -c client_bonus.c
	@$(CC) -I ./include client_bonus.o ./include/libft/libft.a $(CFLAGS) -o client_bonus
	@echo "$(COLOUR_GREEN)[SUCCESS]$(END_COLOR) client bonus ready"


clean:
	@cd ./include/libft; make clean
	@rm -rf server.o client.o server_bonus.o client_bonus.o
	@echo "$(COLOUR_BLUE) clean 🐟$(END_COLOR)"

fclean : clean
	@cd ./include/libft && make fclean
	@rm -rf server client server_bonus client_bonus
	@echo "$(COLOUR_BLUE) fclean 🐳$(END_COLOR)"

re:fclean all
	@echo "$(COLOUR_MAGENTA)make re OK 🌸$(END_COLOR)"

.PHONY: all clean fclean re libft server client
