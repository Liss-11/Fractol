# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 22:56:47 by afrolova          #+#    #+#              #
#    Updated: 2022/10/15 01:53:23 by afrolova         ###   ########.fr        #
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

#FOLDERS

DIR_OBJ = OBJ
DIR_SRCS = SRCS
SRCS = ft_printf.c ft_write.c ft_numbers.c ft_hexadecimales.c 

EXEC_NAME = printf
NAME = libftprintf.a
CC = gcc
RM = rm -rf
AR += -rcs
CFLAGS += -Wall -Werror -Wextra

HEADER = INC/ft_printf.h
HEADER_LIBFT = Libft/INC/libft.h

LIBFT = Libft/libft.a

OBJS = $(addprefix $(DIR_OBJ)/,$(SRCS:.c=.o))


all: 				
					@$(MAKE) -C Libft
					@$(MAKE) $(NAME)

$(NAME)::			OBJ/ $(OBJS) $(LIBFT)
					@-cp $(LIBFT) $(NAME)
					@$(AR) $@ $(OBJS)
					@echo "$(BLUE)Compiling libftprintf.a...$(END_COLOR)"

$(NAME)::			
					@echo "$(GREEN)\t\t\t\t\tLibftprintf.a is Compiled!$(END_COLOR)"

$(DIR_OBJ)/%.o: 	$(DIR_SRCS)/%.c $(HEADER) $(HEADER_LIBFT)
					@$(CC) $(CFLAGS) -IINC -ILibft  -c $< -o $@
					@echo "$(YELLOW)Compiling $< $(END_COLOR)"

OBJ/:
			@-mkdir OBJ

exec:		$(OBJS) $(LIBFT) 
			@$(CC) $(OBJS) $(LIBFT) -o $(EXEC_NAME)
			@echo "${MAGENTA}NOW, you can execute your programm whit "./printf"${END_COLOR}"

clean:
			@$(RM) $(OBJS):w
			@${MAKE} clean -C Libft
			@$(RM) OBJ/
			@echo "$(CYAN)LibftPrintf object files cleaned!${END_COLOR}"

fclean:		
			@$(MAKE) clean
			@$(RM) $(NAME)
			@${MAKE} fclean -C Libft
			@$(RM) $(EXEC_NAME)
			@echo "$(CYAN)ALL CLEANED !$(END-COLOR)"
			
re:			
			@$(MAKE) fclean
			@$(MAKE)
			@echo "$(CYAN)Cleaned und rebuilt everything for LibftPrintf$(END_COLOR)"

dev: CFLAGS = -Wall -Wextra -Wpedantic -fsanitize=address,undefined
dev: re

.PHONY: all clean fclean re dev exec 
