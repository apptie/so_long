# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 20:57:48 by jimikim           #+#    #+#              #
#    Updated: 2021/07/06 22:34:08 by jimikim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = ./header
SRCS = ./libft/ft_putnbr_fd.c \
	   ./libft/ft_putstr_fd.c \
	   ./libft/ft_split.c \
	   ./libft/ft_strcmp.c \
	   ./libft/ft_strdup.c \
	   ./libft/ft_strlen.c \
	   ./libft/ft_word_count.c \
	   ./get_next_line/get_next_line.c \
	   ./get_next_line/get_next_line_utils.c \
	   ./utils/ft_utils_check.c \
	   ./utils/ft_utils_draw.c \
	   ./utils/ft_utils_etc.c \
	   ./utils/ft_utils_get.c \
	   ./utils/ft_utils_init.c \
	   ./utils/ft_utils_key_hook.c \
	   ./utils/ft_utils_loop_hook.c \
	   ./utils/ft_utils_player.c \
	   ./utils/ft_utils_set.c \
	   ./utils/ft_utils_set_sub.c \
	   ./utils/ft_utils_valid.c \
	   ./utils/ft_utils_valid_sub.c \
	   ./so_long.c
SRCS_BONUS = ./bonus/libft/ft_putnbr_fd_bonus.c \
	   ./bonus/libft/ft_putstr_fd_bonus.c \
	   ./bonus/libft/ft_split_bonus.c \
	   ./bonus/libft/ft_strcmp_bonus.c \
	   ./bonus/libft/ft_strdup_bonus.c \
	   ./bonus/libft/ft_strlen_bonus.c \
	   ./bonus/libft/ft_word_count_bonus.c \
	   ./bonus/get_next_line/get_next_line_bonus.c \
	   ./bonus/get_next_line/get_next_line_utils_bonus.c \
	   ./bonus/utils/ft_utils_check_bonus.c \
	   ./bonus/utils/ft_utils_draw_bonus.c \
	   ./bonus/utils/ft_utils_draw_sub_bonus.c \
	   ./bonus/utils/ft_utils_etc_bonus.c \
	   ./bonus/utils/ft_utils_get_bonus.c \
	   ./bonus/utils/ft_utils_init_bonus.c \
	   ./bonus/utils/ft_utils_init_sub_bonus.c \
	   ./bonus/utils/ft_utils_key_hook_bonus.c \
	   ./bonus/utils/ft_utils_loop_hook_bonus.c \
	   ./bonus/utils/ft_utils_player_bonus.c \
	   ./bonus/utils/ft_utils_set_bonus.c \
	   ./bonus/utils/ft_utils_set_sub_bonus.c \
	   ./bonus/utils/ft_utils_valid_bonus.c \
	   ./bonus/utils/ft_utils_valid_sub_bonus.c \
	   ./bonus/utils/ft_utils_img_bonus.c \
	   ./bonus/utils/ft_utils_enemy_bonus.c \
	   ./bonus/so_long_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(NAME) : $(OBJS)
	rm -f $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L ./mlx -lmlx -framework OpenGL -framework AppKit

%.o : %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $^ -o $@

all : $(NAME)

bonus : $(OBJS_BONUS)
	rm -f $(OBJS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME) -L ./mlx -lmlx -framework OpenGL -framework AppKit

clean : 
	rm -f $(OBJS) $(OBJS_BONUS)

fclean :
	rm -f $(OBJS) $(OBJS_BONUS) $(NAME)

re :
	make fclean
	make all

.PHONY :
	all
	clean
	fclean
	re
	bonus
