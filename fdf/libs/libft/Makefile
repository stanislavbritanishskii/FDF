# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbritani <sbritani@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 22:47:41 by sbritani          #+#    #+#              #
#    Updated: 2022/11/09 01:43:18 by sbritani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror

SRCS=ft_bzero.c      ft_isascii.c    ft_memchr.c     ft_memmove.c    ft_strlcat.c    ft_strncmp.c    ft_tolower.c\
ft_isalnum.c    ft_isdigit.c    ft_memcmp.c     ft_memset.c     ft_strlcpy.c    ft_strnstr.c    ft_toupper.c\
ft_isalpha.c    ft_isprint.c    ft_memcpy.c     ft_strchr.c     ft_strlen.c     ft_strrchr.c	ft_atoi.c\
ft_calloc.c		ft_strdup.c		ft_substr.c		ft_strjoin.c	ft_strtrim.c	ft_split.c		ft_itoa.c\
ft_strmapi.c	ft_striteri.c	ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c

BONUSSRCS=ft_lstnew.c	ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c\
ft_lstclear.c	ft_lstiter.c	ft_lstmap.c

BONUSOBJS = $(BONUSSRCS:.c=.o)

OBJS = $(SRCS:.c=.o)

all: $(NAME) bonus

$(NAME): $(SRCS) $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(BONUSSRCS) $(BONUSOBJS)
	ar rcs $(NAME) $(BONUSOBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS) $(BONUSOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
