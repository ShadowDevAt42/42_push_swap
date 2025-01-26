NAME = push_swap

SRC_DIR = srcs
OBJ_DIR = objs

SRCS = main.c \
       utils/ft_atoi.c \
       utils/ft_isdigit.c \
       utils/ft_putstr.c \
       utils/ft_strlen.c \
       utils/error_handler.c \
       utils/parse_args.c \
       utils/is_sorted.c \
       utils/init_utils.c \
       operations/swap.c \
       operations/push.c \
       operations/rotate.c \
       operations/reverse_rotate.c \
       sorting/sort_small.c \
       sorting/sort_utils.c \
       sorting/sort_utils_small.c \
       sorting/radix_sort.c \
       sorting/quicksort.c

OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

CFLAGS = -Wall -Wextra -Werror -Iincludes

all: $(NAME)

FRAMES = "C o o o o o" " co o o o o" "  C o o o o" "  .co o o o" "  . C o o o" "  . .co o o" "  . . C o o" "  . . .co o" "  . . . C o" "  . . . .co" "  . . . . C" "  . . . . 😋"

define run_animation
	@printf "\r🔄 "
	@for frame in $(FRAMES); do \
		printf "\033[K\r🔄 $$frame"; \
		sleep 0.3; \
	done
endef

$(NAME): $(OBJS)
	@printf "🔨 Compilation en cours...\n"
	@$(run_animation)
	@cc $(CFLAGS) $^ -o $@
	@printf "\r✨ Compilation terminée!\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@printf "\033[K\r⚡ Compilation de $<..."
	@cc $(CFLAGS) -c $< -o $@

clean:
	@printf "🧹 Nettoyage en cours...\n"
	@$(run_animation)
	@rm -rf $(OBJ_DIR)
	@printf "\r🗑️  Nettoyage des objets terminé\n"

fclean: clean
	@printf "💫 Nettoyage complet en cours...\n"
	@$(run_animation)
	@rm -f $(NAME)
	@printf "\r✨ Nettoyage complet terminé\n"

re: fclean all

.PHONY: all clean fclean re
