# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acampo-p <acampo-p@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 10:22:25 by acampo-p          #+#    #+#              #
#    Updated: 2022/12/19 09:59:13 by acampo-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC	= gcc

CFLAGS	= -Wall -Werror -Wextra -g

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Sources
SRCS	= 	ft_isdigit.c	ft_memset.c	ft_strdup.c	ft_strncmp.c \
ft_atoi.c	ft_isprint.c	ft_putchar_fd.c	ft_striteri.c	ft_strnstr.c \
ft_bzero.c	ft_itoa.c	ft_putendl_fd.c	ft_strjoin.c	ft_strrchr.c \
ft_calloc.c	ft_memchr.c	ft_putnbr_fd.c	ft_strlcat.c	ft_strtrim.c \
ft_isalnum.c	ft_memcmp.c	ft_putstr_fd.c	ft_strlcpy.c	ft_substr.c \
ft_isalpha.c	ft_memcpy.c	ft_split.c	ft_strlen.c	ft_tolower.c \
ft_isascii.c	ft_memmove.c	ft_strchr.c	ft_strmapi.c	ft_toupper.c \
ft_atoh.c       ft_gnl.c        ft_abs.c        ft_free2parray.c \
ft_xtoi.c		ft_min.c		ft_max.c

OBJ		= $(SRCS:.c=.o)

RM		= rm -f

all:	$(NAME)
	@echo "libft compiled"

$(NAME):		$(OBJ)
				ar rcs $(NAME) $(OBJ)

clean:
				$(RM) $(OBJ)

fclean:
				$(RM) $(OBJ) $(NAME)

re:				fclean all

.PHONY: all clean fclean re
