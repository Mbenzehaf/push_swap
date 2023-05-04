# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mben-zeh <mben-zeh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 23:06:01 by mben-zeh          #+#    #+#              #
#    Updated: 2023/02/05 21:03:34 by mben-zeh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

NAME_BONUS = checker

CC=gcc

CFLAGS= -Wall -Werror -Wextra

SRC =  push_swap.c ft_split.c libft_utils.c utils.c check.c sort.c

SRC_bonus = bonus/ft_split_bonus.c bonus/libft_utils_bonus.c bonus/utils_bonus.c bonus/check_bonus.c bonus/checker_bonus.c  bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c

OBJ=${SRC:.c=.o}

OBJ_bonus=${SRC_bonus:.c=.o}

all:${NAME}
	
${NAME}:${OBJ}
	@$(CC) $(OBJ) -o ${NAME} 

bonus : $(NAME_BONUS)

${NAME_BONUS}:$(OBJ_bonus)
	@$(CC) $(SRC_bonus) -o ${NAME_BONUS} 
	
clean :
	rm -f ${OBJ} ${OBJ_bonus}

fclean : clean
	rm -f ${NAME} ${NAME_BONUS}

re : fclean all

.PHONY: all clean fclean re