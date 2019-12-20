# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amolin-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 22:29:22 by amolin-m          #+#    #+#              #
#    Updated: 2019/09/22 23:32:47 by jtello-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE 	= main.c read.c program.c aux.c aux1.c 
OBJS	= $(FILE)
RM		= rm -f
NAME	= rush-02
CFLAGS	= -Wall -Wextra -Werror


a.out: $(OBJS)
	gcc $(CFLAGS) $(OBJS) -o $(NAME)

fclean :
	$(RM) $(NAME)

