/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_key_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:39:12 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/06 14:37:19 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_key_hook_sub(int key, t_game *game)
{
	ft_putstr_fd("\n", 1);
	ft_move_player(key, game);
	ft_putstr_fd("player movement : ", 1);
	ft_putnbr_fd(game->player->movement, 1);
}

int	ft_key_hook(int key, t_game *game)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		ft_key_hook_sub(key, game);
	else if (key == ESC)
		exit(0);
	mlx_clear_window(game->mlx_ptr, game->mlx_win);
	ft_draw_background(game);
	ft_draw_game(game);
	return (0);
}
