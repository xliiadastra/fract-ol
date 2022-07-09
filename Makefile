# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 15:18:40 by yichoi            #+#    #+#              #
#    Updated: 2022/07/09 23:12:27 by yichoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol

LIBFT		= ./libft

LIBFT_LIB	= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm
RMFLAGS		= -f

INCLUDES	= ./fract-ol.h

SRCS		=	fract-ol.c

SRCS_BN		=	fract-ol.c

OBJS		= $(SRCS:.c=.o)

OBJS_BONUS	= $(SRCS_BN:.c=.o)

ifdef WITH_BONUS
	A_OBJS = $(OBJS_BONUS)
else
	A_OBJS = $(OBJS)
endif

.PHONY : all
all : $(NAME)

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@ -I./

$(NAME) : $(A_OBJS)
	@make -C $(LIBFT) 
	$(CC) $(CFLAGS) -o $@ $^ -framework OpenGL -framwork AppKit -L $(LIBFT) -lft

.PHONY : clean
clean :
	$(RM) $(RMFLAGS) $(OBJS) $(OBJS_BONUS)
	@make clean -C $(LIBFT)

.PHONY : fclean
fclean : clean
	$(RM) $(RMFLAGS) $(NAME) $(BNS_NAME)
	@make fclean -C $(LIBFT)

.PHONY : re
re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY : bonus
bonus :
	$(MAKE) WITH_BONUS=1 all
