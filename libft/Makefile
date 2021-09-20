NAME		= libft.a

CC =		gcc

SRC_DIR = 	$(shell find srcs -type d)
INC_DIR = 	$(shell find includes -type d)
LIB_DIR =	$(shell find libs -type d)
OBJ_DIR = 	objs

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

# List de toute les library a linker au projet (le nom - le lib et - le .a)
LIB =

#SRC = $(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))
SRC =		ft_f_abs.c ft_f_floor.c ft_f_roof.c ft_i_abs.c ft_i_roof.c \
			ft_itoa_base.c ft_itoa.c ft_atoi.c ft_itoa_hexa.c ft_itoa_octa.c \
			ft_itoa_unsigned_deci.c ft_f_round.c \
			\
			ft_strdup.c ft_strndup.c ft_strdup_c.c ft_strlen.c ft_strnlen.c \
			ft_strlen_arg.c ft_strnew.c \
			ft_strcpy.c ft_strsub.c ft_strstr.c ft_str_count_c.c ft_rm_charset.c\
			ft_strjoin.c ft_strappend.c ft_strprepend.c ft_strjoinfre.c ft_split.c\
			ft_str_add_prefixe.c ft_str_add_suffix.c ft_str_count_c.c ft_strnstr.c\
			ft_swap.c \
			\
			ft_str_is_only_digit.c ft_is_digit.c ft_strcmp.c ft_strcmp_c.c \
			ft_is_alpha.c ft_is_lower.c ft_is_upper.c ft_is_alpha_num.c \
			ft_is_whitespaces.c ft_file_exist.c ft_strncmp.c \
			ft_str_is_only_whitespaces.c \
			\
			ft_putchar.c ft_putchar_fd.c ft_putchar_fp.c \
			ft_putstr.c ft_putstr_fd.c ft_putstr_fp.c \
			ft_putnbr.c ft_putnbr_fd.c ft_putnbr_fp.c \
			get_next_line.c get_next_line_utils.c ft_get_file.c \
			ft_print_str_tab.c ft_print_str_tab_fd.c ft_print_str_tab_fp.c \
			ft_print_int_tab_fd.c ft_print_int_tab.c ft_count_charset.c \
			ft_memset.c ft_nbrlen.c \
			\
			ft_free_tab.c ft_tab_cpy.c ft_tab_new.c ft_tab_len.c \
			ft_add_to_tab.c \
			\
			ft_lst_add_back.c ft_lst_clear.c ft_lst_rm_data.c ft_lst_map.c \
			ft_lst_size.c ft_lst_add_front.c ft_lst_create_node.c \
			ft_lst_iter.c ft_lst_rm_node.c char_list_creators.c \
			char_list_destructors.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

#Compilation flag

CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

#Include flag
IFLAGS = $(foreach dir, $(INC_DIR), -I$(dir))

#Library flag
LFLAGS = $(foreach lib_dir, $(LIB_DIR), -L $(lib_dir)) $(foreach lib, $(LIB), -l $(lib))

# Colors
_GREY=$'\033[30m
_RED=$'\033[31m
_GREEN=$'\033[32m
_YELLOW=$'\033[33m
_BLUE=$'\033[34m
_PURPLE=$'\033[35m
_CYAN=$'\033[36m
_WHITE=$'\033[37m

all:
				@echo "\n$(_BLUE)___$(NAME) Setting___\n$(_WHITE)"
				@make $(NAME)

$(NAME):		$(OBJ) Makefile
				@echo "-----\nCompiling $(_YELLOW)$@$(_WHITE) ... \c"
				@ar rc $(NAME) $(OBJ)
				@ranlib $(NAME)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

show:
				@echo "$(_BLUE)\nSRC :\n$(_YELLOW)$(SRC)\n$(_WHITE)"
				@echo "$(_BLUE)OBJ :\n$(_YELLOW)$(OBJ)\n$(_WHITE)"
				@echo "$(_BLUE)CFLAGS :\n$(_YELLOW)$(CFLAGS)\n$(_WHITE)"
				@echo "$(_BLUE)IFLAGS :\n$(_YELLOW)(IFLAGS)\n$(_WHITE)"
				@echo "$(_BLUE)LFLAGS :\n$(_YELLOW)$(LFLAGS)\n$(_WHITE)"
				@echo "$(_BLUE)LIB_DIR :\n$(_YELLOW)$(LIB_DIR)\n$(_WHITE)"

$(OBJ_DIR)/%.o : %.c
				@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
				@echo "$(_GREEN)DONE$(_WHITE)"

re:				fclean all

clean:
	@echo "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
	@rm -rf $(OBJ_DIR)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:			clean
	@echo "Deleting library File $(_YELLOW)$(NAME)$(_WHITE) ... \c"
	@rm -f $(NAME)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

.PHONY:			all debug show re clean fclean install re-install
