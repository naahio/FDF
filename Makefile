# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 08:57:50 by mbabela           #+#    #+#              #
#    Updated: 2021/12/01 09:01:58 by mbabela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
CC=gcc
CFLAGS=-Wall -Werror -Wextra
INCLUDES=.
LDIR=-L /usr/local/lib/
LIBS=-lmlx -framework OpenGL -framework AppKit
SRCS = brensen.c draw.c fdf.c isometric.c get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) 
	$(CC) -o $(NAME) -I$(INCLUDES) $^ $(CFLAGS) $(LDIR) $(LIBS)

bonus : $(OBJS)
	$(CC) -o $(NAME) -I$(INCLUDES) $^ $(CFLAGS) $(LDIR) $(LIBS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all