# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imendonc <imendonc@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 00:34:41 by imendonc          #+#    #+#              #
#    Updated: 2022/11/10 15:52:26 by imendonc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#DIR_SRCS	= sources

SRCS		= ft_strlen.c ft_strnstr.c ft_split.c 

#conversao de ficheiros c em objectos
OBJS		= $(SRCS:.c=.o)

#definir qual o compiler
CC				= gcc
RM 				= /bin/rm -f
CFLAGS 		= -Wall -Wextra -Werror

NAME		= libft.a

#adiciona os .o a libft.a e cria caso nao exista
ARCHIVE			= ar -rc

#definir os comandos para não entraram em conflito com outros
all:		$(NAME)

$(NAME):	$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:			
			$(RM) $(OBJS)

fclean: 	clean
				$(RM) $(NAME)

re:				fclean all $(NAME)

.PHONY:		all clean fclean re


