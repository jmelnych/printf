# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/19 13:18:52 by imelnych          #+#    #+#              #
#    Updated: 2018/01/04 12:26:04 by imelnych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = libftprintf.a
EXC = ft_printf
FLAGS = -Wall -Werror -Wextra
OBJ_DIR	= ./obj
SRC_files = ft_printf.c find_spcfctr.c align.c ft_putchar.c ft_strlen.c ft_putnbr.c
OBJ_files = $(addprefix $(OBJ_DIR)/, $(SRC_files:.c=.o))
LIB_AR 	= ar rc $(TARGET) $(OBJ_files) $(OBJ_utils_files)
INC_U = printflib.h

all: run

$(OBJ_DIR)/%.o: %.c
	gcc $(FLAGS) -I $(INC_U) -o $@ -c $<	



run:
	@mkdir -p $(OBJ_DIR)
	@$(MAKE) $(OBJ_files)
	@$(LIB_AR)
	ranlib $(TARGET)
	gcc $(FLAGS) -o $(EXC) $(SRC_files) $(TARGET)

clean:
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	/bin/rm -rf $(TARGET)
	/bin/rm -rf $(EXC)

re: fclean all