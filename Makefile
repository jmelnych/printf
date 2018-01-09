# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/19 13:18:52 by imelnych          #+#    #+#              #
#    Updated: 2018/01/09 14:44:01 by imelnych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = libftprintf.a
EXC = ft_printf
FLAGS = -Wall  -Wextra
OBJ_DIR	= ./obj
SRC_files = ft_printf.c ft_putchar.c ft_strlen.c ft_putnbr.c ft_strnew.c \
			ft_bzero.c ft_isdigit.c save_spec.c ft_atoi.c check_type.c \
			fill_type.c ft_numlen.c print_digits.c print_str.c ft_itoabase.c \
			ft_strdup.c

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
