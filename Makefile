# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albriffa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 09:50:37 by albriffa          #+#    #+#              #
#    Updated: 2023/12/05 10:34:22 by albriffa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = fractole
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	

all = $(NAME)

$(NAME) : $(OBJ)
	$(NAME) $(OBJ)

%.o : %c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re :fclean all
