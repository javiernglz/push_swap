NAME = push_swap

OBJ_DIR = obj
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = $(wildcard src/*.c)
OBJ = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -I$(LIBFT_DIR)

$(OBJ_DIR)/%.o: src/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all
