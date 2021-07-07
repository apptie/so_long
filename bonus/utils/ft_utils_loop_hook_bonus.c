/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_loop_hook_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:52:49 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/06 21:55:05 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_process_timer(int *enemy, int *collection, t_game *game)
{
	*enemy += 1;
	*collection += 1;
	game->enemy_timer += 1;
	if (game->enemy_timer == 5000)
		game->enemy_timer = 0;
	if (*collection == 50)
		game->img->img_collection = game->img->img_collection_r;
	else if (*collection == 100)
	{
		game->img->img_collection = game->img->img_collection_l;
		*collection = 0;
	}
	if (*enemy == 20)
		game->img->img_enemy = game->img->img_enemy_r;
	else if (*enemy == 40)
	{
		game->img->img_enemy = game->img->img_enemy_l;
		*enemy = 0;
	}
}

int	ft_loop_hook(t_game *game)
{
	static int	collection_timer;
	static int	enemy_timer;

	ft_process_timer(&enemy_timer, &collection_timer, game);
	mlx_clear_window(game->mlx_ptr, game->mlx_win);
	ft_draw_background(game);
	ft_draw_game(game);
	ft_check_movement(game->player->movement, 0, game);
	return (0);
}

int	ft_window_exit(t_game *game)
{
	ft_free_all(game);
	exit(0);
}
