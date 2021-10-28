NAME		=	minishell

CC			=	gcc

SRC_DIR		=	$(shell find srcs -type d)
INC_DIR		=	$(shell find includes -type d) \
					$(shell find libft/includes -type d)
LIB_DIR		=	libft
OBJ_DIR		=	obj
LIB			=	ft

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

SRC			= 	main.c minishell_cmd_gestion.c minishell_cmd_handler.c \
				minishell_output_is_case.c minishell_pipe_is_case.c \
				minishell_input_is_case.c minishell_exec_is_case.c \
				minishell_exec_double_lower_io_case.c \
				minishell_cmd_input_gestion.c minishell_exec_lower_io_case.c \
				minishell_exec_here_doc_utils.c minishell_exec_here_doc.c \
				minishell_here_doc_dollar_transformation.c \
				minishell_exec_double_greater_io_case.c \
				minishell_exec_greater_io_case.c minishell_cmd_output_gestion.c \
				minishell_exec_case.c minishell_signals.c \
				minishell_args_token.c minishell_lower_token.c \
				minishell_white_space_token.c minishell_tokenizer.c \
				minishell_greater_token.c minishell_pipe_token.c \
				minishell_cmd_error.c minishell_here_doc_warning.c \
				minishell_lexer_error.c minishell_quit.c \
				minishell_mix_quote_transformation.c minishell_parser.c \
				minishell_dollar_transformation.c \
				minishell_simple_quote_transformation.c \
				minishell_dollar_quote_transformation.c \
				minishell_cmd_number_setter.c minishell_fork_setter.c \
				minishell_double_quote_transformation.c \
				minishell_double_lower_error_handler.c \
				minishell_syntax_checker.c minishell_args_error_handler.c \
				minishell_lower_error_handler.c \
				minishell_double_greater_error_handler.c \
				minishell_greater_error_handler.c minishell_pipe_error_handler.c \
				minishell_greater_checker.c minishell_pipe_checker.c \
				minishell_null_checker.c minishell_double_lower_checker.c \
				minishell_lower_checker.c minishell_double_greater_checker.c \
				builtin_cd.c builtin_echo.c builtin_unset.c builtin_exit.c \
				builtin_env.c builtin_pwd.c builtin_export.c utils.c \
				minishell_cmd_builder.c minishell_run_multiple_cmd.c \
				minishell_cmd_out_fork_executer.c minishell_cmd_executer.c \
				minishell_cmd_builtin_executer.c minishell_cmd_execution.c \
				minishell_run_single_cmd.c minishell_builtin_is_case.c \
				minishell_t_lexer_manipulation.c minishell_t_lexer.c \
				minishell_t_cmd_setter.c minishell_t_cmd_destructor.c \
				minishell_t_cmd_constructor.c minishell_prompt.c \
				minishell_env_allocation.c

OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

# Compilation flags

CFLAGS		=	-Wall -Wextra -Werror -g3 #-fsanitize=address

IFLAGS		=	$(foreach dir, $(INC_DIR), -I $(dir))

LFLAGS		=	$(foreach dir, $(LIB_DIR), -L $(dir)) \
				$(foreach lib, $(LIB), -l $(lib))

# Colors

_GREY=	$'\033[30m
_RED=	$'\033[31m
_GREEN=	$'\033[32m
_YELLOW=$'\033[33m
_BLUE=	$'\033[34m
_PURPLE=$'\033[35m
_CYAN=	$'\033[36m
_WHITE=	$'\033[37m

# MAIN part --------------------------------------------------------

all:		$(NAME)

show:
	@echo "$(_BLUE)SRC :\n$(_YELLOW)$(SRC)$(_WHITE)"
	@echo "$(_BLUE)OBJ :\n$(_YELLOW)$(OBJ)$(_WHITE)"
	@echo "$(_BLUE)CFLAGS :\n$(_YELLOW)$(CFLAGS)$(_WHITE)"
	@echo "$(_BLUE)IFLAGS :\n$(_YELLOW)$(IFLAGS)$(_WHITE)"
	@echo "$(_BLUE)LFLAGS :\n$(_YELLOW)$(LFLAGS)$(_WHITE)"
	@echo "$(_BLUE)LIB_DIR :\n$(_YELLOW)$(LIB_DIR)$(_WHITE)"
	@echo "\n-----\n"
	@echo "$(_BLUE)Compiling : \n$(_YELLOW)$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lreadline$(_WHITE)"

libft/libft.a:
	@$(foreach dir, $(LIB_DIR), make --no-print-directory -C $(dir); )

re-install:
	@$(foreach dir, $(LIB_DIR), make --no-print-directory -C $(dir) re; )

fclean-install:
	@$(foreach dir, $(LIB_DIR), make --no-print-directory -C $(dir) fclean; )

$(NAME): libft/libft.a $(OBJ)
	@echo "-----\nCreating Binary File $(_YELLOW)$@$(_WHITE) ... \c"
	@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME) -lreadline
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

$(OBJ_DIR)/%.o : %.c
	@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
	@echo "$(_GREEN)DONE$(_WHITE)"

re:	fclean all

clean:
	@echo "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
	@$(foreach file, $(OBJ), rm -rf $(file))
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:	clean
	@echo "Deleting Binary File $(_YELLOW)$(NAME)$(_WHITE) ... \c"
	@rm -f $(NAME)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

.PHONY: all show re-install fclean-install re clean flcean