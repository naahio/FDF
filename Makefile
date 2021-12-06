# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 08:57:50 by mbabela           #+#    #+#              #
#    Updated: 2021/12/06 12:32:23 by mbabela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
CC=gcc
CFLAGS=-Wall -Werror -Wextra
INCLUDES=.
LIBS=-lmlx -framework OpenGL -framework AppKit
SRC= ft_isdigit.c ft_split.c ft_atoi.c ft_atoi_conv.c fdf.c get_next_line.c get_next_line_utils.c isometric.c matrice.c key_handel.c\
	draw.c bresen.c get_color.c

BNS= ft_isdigit.c ft_split.c  ft_atoi_conv.c  ft_atoi.c fdf_bonus.c get_next_line.c get_next_line_utils.c isometric.c matrice.c key_handel_Bonus.c\
	draw.c bresen.c get_color.c

OBJ=$(SRC:.c=.o)
BOBJ=$(BNS:.c=.o)
REM=rm -f
all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(LIBS)  -I$(INCLUDES) $^ $(CFLAGS) -o $(NAME)

bonus : $(BOBJ)
	$(CC)  $(LIBS) -I$(INCLUDES) $^ $(CFLAGS) -o $(NAME)

%.o: %.c
	$(CC) -c  $(CFLAGS) $<

clean:
	$(REM) $(OBJ) $(BOBJ)
		
fclean: clean
	$(REM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus
	