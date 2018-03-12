NAME = corewar
ASM_NAME = asm

# ===== Libft ======
LIBFT_DIR:= ./libft/
LIBFT:= $(LIBFT_DIR)libft.a
LIBFT_INC:= $(LIBFT_DIR)includes/
LIBFT_FLAGS:= -lft -L $(LIBFT_DIR)
# ==================

# ==== Standard ====
CC:= gcc
CFLAGS:= -Wall -Wextra -Werror
SRC_DIR:= ./src/
ASM_DIR:= ./asm_dir/
OBJ_DIR:= ./obj/
ASM_OBJ_DIR:= ./asm-obj/
INC_DIR:= ./includes/
COD:= .cache_exists
HEADER_FLAGS:= -I $(INC_DIR) -I $(LIBFT_INC)
# ==================



# ===== Colors =====
END:="\033[0;0m"
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
# ==================

# ===== Auto =======
SRC:= ./src/usage.c \
		./src/main.c \
		./src/parse_flags.c \
		./src/is_flag.c \
		./src/parse_player_data.c \
		./src/game_cycle.c \
		./src/game_process_revision.c \
		./src/initializations.c \
		./src/op_aff.c \
		./src/op_st.c \
		./src/service.c \
		./src/op_ld.c \
		./src/op_live.c \
		./src/op_fork.c \
		./src/op_sub.c \
		./src/op_add.c \
		./src/op_zjmp.c \
		./src/op_sti.c \
		./src/op_ldi.c \
		./src/op_lldi.c \
		./src/op_and.c \
		./src/arguments_manager.c \
		./src/op_or.c \
		./src/op_xor.c \
		./src/op_lld.c \
		./src/op_lfork.c \
		./src/check_a_d_flags.c \
		./src/prints.c \
		./src/vis/visualize.c \
		./src/vis/update_win.c \
		./src/vis/load_map.c \
		./src/vis/init_scr.c \
		./src/vis/proc_mngr.c \
		./src/vis/load_subwin.c
OBJ:= $(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))
# ==================

# ===== Asm =======
ASM_SRC:= ./asm_dir/main.c \
		./asm_dir/split.c \
		./asm_dir/helper.c \
		./asm_dir/errors.c \
		./asm_dir/read.c \
		./asm_dir/get_pos.c \
		./asm_dir/get_type.c \
		./asm_dir/remove_lable.c \
		./asm_dir/clear_file.c \
 		./asm_dir/validate.c \
		./asm_dir/bytecode.c \
		./asm_dir/header.c \
		./asm_dir/to_file.c \
		./asm_dir/helper2.c \
		./asm_dir/helper3.c \
		./asm_dir/bytecode_help.c \
		./asm_dir/helper4.c \
		./asm_dir/helper5.c \
		./asm_dir/helper6.c \
		./asm_dir/op.c
ASM_OBJ:= $(subst $(ASM_DIR), $(ASM_OBJ_DIR), $(ASM_SRC:.c=.o))
# ==================

# ===== Rules ======
all: $(NAME) $(ASM_NAME)
	@echo $(RED) "\n- $@ is ready! Have fun :)" $(END)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) -g $(OBJ) $(LIBFT_FLAGS) -o $(NAME) -lncurses
	@echo $(CYAN) "\n- $@ is ready :)" $(END)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/vis
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADER_FLAGS)

$(ASM_NAME): $(ASM_OBJ)
	@$(CC) $^ $(LIBFT_FLAGS) -o $@
	@echo $(PURPLE) "\n- $@ is ready :)" $(END)

$(ASM_OBJ_DIR)%.o: $(ASM_DIR)%.c
	@mkdir -p $(ASM_OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADER_FLAGS)

$(LIBFT):
	@make -C $(LIBFT_DIR)	

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(ASM_OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(ASM_NAME)
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIBFT_DIR)

re: fclean all
# ==================
