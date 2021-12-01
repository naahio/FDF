# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 08:57:50 by mbabela           #+#    #+#              #
#    Updated: 2021/12/01 18:22:53 by mbabela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
SRC=	bresen.c get_color.c draw.c fdf.c get_next_line.c get_next_line_utils.c isometric.c matrice.c

BNS=	$(SRC) key_handel_Bonus

OBJ=$(SRC:.c=.o)
BOBJ=$(BNS:.c=.o)
CC=gcc -c
CFLAGS=-Wall -Wextra -Werror
REM=rm -f

all: $(NAME)

$(NAME): $(OBJ)
	# use gcc -c to get objects
	# link the objects b gcc nit
	
bonus: $(BOBJ)
	$(AR) $(NAME) $(BOBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $<

clean:
	$(REM) $(OBJ) $(BOBJ)
		
fclean: clean
	$(REM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus
	