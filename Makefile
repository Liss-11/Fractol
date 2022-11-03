# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 22:51:55 by afrolova          #+#    #+#              #
#    Updated: 2022/10/17 15:36:27 by afrolova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS

END_COLOR = \033[0;0m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#LIBRARIES (LibftPrintf and MiniLibX)

DIR_LIBPRINT = LIB/LIBFT_PRINTF/
LIBPRINT_INC = $(DIR_LIBPRINT)/INC
LIBPRINT = LIB/LIBFT_PRINTF/libftprintf.a
PRINT_H = LIB/LIBFT_PRINTF/INC/ft_printf.h
LIB_H = LIB/LIBFT_PRINTF/Libft/INC/libft.h

DIR_MINILIBX = LIB/minilibx/
MINILIBX = LIB/minilibx/libmlx.a
MINILIBX_H = LIB/minilibx/mlx.h

MAKEFILE = Makefile

#FOLDERS

FRACTOL_H = INC/fractol.h
DIR_SRCS = SRCS
DIR_OBJS = OBJS

#FILES

SRCS = main.c mandelbrot.c key.c drawer.c init.c mouse.c julia.c errors.c logs.c

#VARIABLES

CC = gcc
NAME = fractol
RM = rm -rf
FLAGS = -Wall -Werror -Wextra
XFLAGS = -fsanitize=adress -g3
OPENGL = -framework OpenGL -framework AppKit

OBJS = $(addprefix $(DIR_OBJS)/,$(SRCS:.c=.o))


all:				
					@$(MAKE) -C $(DIR_MINILIBX)
					@$(MAKE) -C $(DIR_LIBPRINT)
					@$(MAKE) $(NAME)

$(NAME)::			$(DIR_OBJS)	$(OBJS)
					@$(CC) $(OPENGL) $(OBJS) $(LIBPRINT) $(MINILIBX) -o $(NAME)
					@echo "$(BLUE)Compiling Fractol...$(END_COLOR)"

$(NAME)::
					@echo "$(GREEN)\t\t\t\t\t   Fractol is Compiled!$(END_COLOR)"

$(DIR_OBJS)/%.o:	$(DIR_SRCS)/%.c $(FRACTOL_H) $(LIBPRINT) $(MINILIBX) $(MAKEFILE)
					@$(CC) $(FLAGS) -IINC -I $(LIBPRINT_INC) -I $(DIR_MINILIBX) -c $< -o $@
					@echo "$(YELLOW)Compiling $< $(END_COLOR)"

$(DIR_OBJS):		
					@-mkdir  $(DIR_OBJS)

clean:				
					@$(RM) $(OBJS)
					@make clean -C $(DIR_LIBPRINT)
					@make clean -C $(DIR_MINILIBX)
					@$(RM) $(DIR_OBJS)
					@echo "$(CYAN)ALL object files are cleaned!$(END_COLOR)"

fclean:				
					@$(MAKE) clean
					@$(RM) $(NAME)
					@make fclean -C $(DIR_LIBPRINT)
					@make clean -C $(DIR_MINILIBX)
					@echo "$(CYAN)ALL cleaned!$(END_COLOR)"

re:					
					@$(MAKE) fclean
					@$(MAKE)
					@echo "$(CYAN)ALL cleaned and Rebuild!$(END_COLOR)"

.PHONY: all clean fclean re
