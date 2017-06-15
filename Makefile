# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/09 19:07:03 by pluu              #+#    #+#              #
#    Updated: 2017/06/15 15:10:57 by pluu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1          = checker
NAME2          = push_swap

LIBFT_DIR      = ./libft
LIBFT_INCS_DIR = ./libft/incs
OBJS_DIR       = ./objs
INCS_DIR       = ./incs

CC             = gcc
FLAGS          = -Wall -Wextra -Werror
FLAGS          += -g

SRCS	       = srcs/stack_funcs1.c \
		 srcs/stack_funcs2.c \
		 srcs/stack_funcs3.c \
		 srcs/vector.c \
		 srcs/operations_swap.c \
		 srcs/operations_push.c \
		 srcs/operations_rotate.c \
		 srcs/operations_rev_rotate.c \
		 srcs/get_check_stack1.c \
		 srcs/get_check_stack2.c \
		 srcs/get_check_ops.c \
		 srcs/helper_funcs.c \
		 srcs/get_elem.c \
		 srcs/ps_funcs.c \
		 srcs/merge.c \
		 srcs/sort_funcs1.c \
		 srcs/sort_funcs2.c \
		 srcs/handle_funcs1.c \
		 srcs/handle_funcs2.c \
		 srcs/update_pos.c \
		 srcs/stacks.c \
		 srcs/vecs.c \
		 srcs/vec_funcs1.c \
		 srcs/vec_funcs2.c \
		 srcs/vec_funcs3.c \
		 srcs/display.c \
		 srcs/display_c.c \
		 srcs/display_v.c

SRCS_CK         = srcs/checker.c
SRCS_PS		= srcs/push_swap.c

O	       = $(SRCS:.c=.o)

OBJS	       = $(addprefix $(OBJS_DIR)/, $(notdir $(O)))

LIBFT_INCS     = -I$(LIBFT_INCS_DIR)
INCS           = -I$(INCS_DIR)

LIBFT_LINK     = -L$(LIBFT_DIR) -lft

all: objs $(NAME1) $(NAME2)

objs:
	@make -C $(LIBFT_DIR)
	@echo "-> Created libft..."
	@$(CC) $(FLAGS) -c $(SRCS) $(INCS) $(LIBFT_INCS)
	@echo "-> Compiled $(SRCS) into object files..."
	@mkdir -p $(OBJS_DIR)
	@mv *.o $(OBJS_DIR)
	@echo "-> Moved $(SRCS:.c=.o) into $(OBJS_DIR)..."

$(NAME1):
	@$(CC) $(FLAGS) $(SRCS_CK) $(OBJS) $(LIBFT_INCS) $(INCS) $(LIBFT_LINK) -o $(NAME1)
	@echo "-> Created executable $(NAME1)..."

$(NAME2):
	@$(CC) $(FLAGS) $(SRCS_PS) $(OBJS) $(LIBFT_INCS) $(INCS) $(LIBFT_LINK) -o $(NAME2)
	@echo "-> Created executable $(NAME2)..."

clean:
	@make -C $(LIBFT_DIR) clean
	@echo "-> Deleted $(LIBFT_DIR) $(OBJS_DIR)..."
	@rm -rf $(OBJS_DIR)
	@echo "-> Deleted $(OBJS_DIR)..."
	@rm -rf *.dSYM

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@echo "-> Deleted $(LIBFT_DIR) libft.a"
	@rm -rf $(NAME1)
	@echo "-> Deleted $(NAME1)..."
	@rm -rf $(NAME2)
	@echo "-> Deleted $(NAME2)..."

re: fclean all

norme:
	@norminette ./srcs/
	@norminette ./incs/

.PHONY: all clean fclean re norme
