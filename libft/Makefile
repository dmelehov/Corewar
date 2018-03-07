# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/28 19:16:03 by dmelehov          #+#    #+#              #
#    Updated: 2018/03/06 18:39:35 by dmelehov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==== Editable ====
NAME:= libft.a
# ==================

# ==== Standard ====
CC:= gcc
CFLAGS:= -Wall -Wextra -Werror
SRC_DIR:= ./src/*/src/
OBJ_DIR:= ./obj/
INC_DIR:= ./includes/
COD:= .cache_exists
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
# SRC:= $(wildcard ./src/*/src/*.c)
SRC:=   libft/src/additional/src/ft_to_bin.c \
        libft/src/array/src/ft_array_access.c \
        libft/src/array/src/ft_array_capacity.c \
        libft/src/array/src/ft_array_foreach.c \
        libft/src/array/src/ft_array_init.c \
        libft/src/array/src/ft_array_modifyer.c \
        libft/src/ctype/src/ft_isalnum.c \
        libft/src/ctype/src/ft_isalpha.c \
        libft/src/ctype/src/ft_isascii.c \
        libft/src/ctype/src/ft_isdigit.c \
        libft/src/ctype/src/ft_islower.c \
        libft/src/ctype/src/ft_isprint.c \
        libft/src/ctype/src/ft_isupper.c \
        libft/src/ctype/src/ft_tolower.c \
        libft/src/ctype/src/ft_toupper.c \
        libft/src/error/src/ft_error_mngr.c \
        libft/src/ft_printf/src/ft_conv_cs.c \
        libft/src/ft_printf/src/ft_conv_diu.c \
        libft/src/ft_printf/src/ft_conv_fen.c \
        libft/src/ft_printf/src/ft_conv_ga.c \
        libft/src/ft_printf/src/ft_conv_pox.c \
        libft/src/ft_printf/src/ft_fillstruct.c \
        libft/src/ft_printf/src/ft_flagmanagement.c \
        libft/src/ft_printf/src/ft_formatparsing.c \
        libft/src/ft_printf/src/ft_formatparsing_additional.c \
        libft/src/ft_printf/src/ft_modifyers_management.c \
        libft/src/ft_printf/src/ft_parse_a.c \
        libft/src/ft_printf/src/ft_parse_colors.c \
        libft/src/ft_printf/src/ft_parse_floats.c \
        libft/src/ft_printf/src/ft_parse_floats2.c \
        libft/src/ft_printf/src/ft_printf.c \
        libft/src/ft_printf/src/ft_round_floats.c \
        libft/src/ft_printf/src/ft_sprintf.c \
        libft/src/ft_printf/src/ft_support_functions_1.c \
        libft/src/ft_printf/src/ft_support_functions_2.c \
        libft/src/get_next_line/src/get_next_line.c \
        libft/src/lists/src/ft_lstadd.c \
        libft/src/lists/src/ft_lstdel.c \
        libft/src/lists/src/ft_lstdelone.c \
        libft/src/lists/src/ft_lstiter.c \
        libft/src/lists/src/ft_lstmap.c \
        libft/src/lists/src/ft_lstnew.c \
        libft/src/lists/src/ft_mylist.c \
        libft/src/lists/src/ft_mylist_access.c \
        libft/src/lists/src/ft_mylist_capacity.c \
        libft/src/lists/src/ft_mylist_cell.c \
        libft/src/lists/src/ft_mylist_cell_count.c \
        libft/src/lists/src/ft_mylist_find.c \
        libft/src/lists/src/ft_mylist_insert.c \
        libft/src/lists/src/ft_mylist_interval.c \
        libft/src/lists/src/ft_mylist_modifier.c \
        libft/src/lists/src/ft_mylist_operator.c \
        libft/src/lists/src/ft_mylist_splice.c \
        libft/src/lists/src/ft_mylist_split.c \
        libft/src/memory/src/ft_bzero.c \
        libft/src/memory/src/ft_free_2d_array.c \
        libft/src/memory/src/ft_malloc_s.c \
        libft/src/memory/src/ft_memalloc.c \
        libft/src/memory/src/ft_memccpy.c \
        libft/src/memory/src/ft_memchr.c \
        libft/src/memory/src/ft_memcmp.c \
        libft/src/memory/src/ft_memcpy.c \
        libft/src/memory/src/ft_memdel.c \
        libft/src/memory/src/ft_memmove.c \
        libft/src/memory/src/ft_memset.c \
        libft/src/memory/src/ft_realloc.c \
        libft/src/printing/src/ft_putaddr.c \
        libft/src/printing/src/ft_putchar.c \
        libft/src/printing/src/ft_putchar_fd.c \
        libft/src/printing/src/ft_putendl.c \
        libft/src/printing/src/ft_putendl_fd.c \
        libft/src/printing/src/ft_putnbr.c \
        libft/src/printing/src/ft_putnbr_fd.c \
        libft/src/printing/src/ft_putstr.c \
        libft/src/printing/src/ft_putstr_fd.c \
        libft/src/string/src/ft_atoi.c \
        libft/src/string/src/ft_itoa.c \
        libft/src/string/src/ft_strcat.c \
        libft/src/string/src/ft_strchr.c \
        libft/src/string/src/ft_strclr.c \
        libft/src/string/src/ft_strcmp.c \
        libft/src/string/src/ft_strcpy.c \
        libft/src/string/src/ft_strdel.c \
        libft/src/string/src/ft_strdup.c \
        libft/src/string/src/ft_strequ.c \
        libft/src/string/src/ft_striter.c \
        libft/src/string/src/ft_striteri.c \
        libft/src/string/src/ft_strjoin.c \
        libft/src/string/src/ft_strlcat.c \
        libft/src/string/src/ft_strlen.c \
        libft/src/string/src/ft_strmap.c \
        libft/src/string/src/ft_strmapi.c \
        libft/src/string/src/ft_strncat.c \
        libft/src/string/src/ft_strncmp.c \
        libft/src/string/src/ft_strncpy.c \
        libft/src/string/src/ft_strnequ.c \
        libft/src/string/src/ft_strnew.c \
        libft/src/string/src/ft_strnstr.c \
        libft/src/string/src/ft_strrchr.c \
        libft/src/string/src/ft_strsplit.c \
        libft/src/string/src/ft_strstr.c \
        libft/src/string/src/ft_strsub.c \
        libft/src/string/src/ft_strtrim.c
OBJ:= $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))
# ==================

# ===== Rules ======
all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(GREEN) "\n- $@ is ready to serve, my Lord" $(END)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(COD)
	@echo $(PURPLE)"#\c"$(END)
	@$(CC) $(CFLAGS) -c $< -o $@

$(COD):
	@mkdir -p $(OBJ_DIR)
	@touch $(COD)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(COD)

fclean: clean
	@rm -rf $(NAME)

re: fclean
	@$(MAKE) all

norm:
	@echo $(RED)
	@norminette $(SRC) | grep -v Norme -B1 || true
	@echo $(END)

.PHONY: all clean fclean re test norme
# ==================