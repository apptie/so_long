/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:50:59 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/07 14:22:34 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_exit(t_game *game)
{
	t_map	*map;

	map = game->map;
	if (map->collection == game->player->player_collection)
	{
		map->map[game->player->player_y][game->player->player_x] = '0';
		map->map[map->exit_y][map->exit_x] = 'P';
		mlx_clear_window(game->mlx_ptr, game->mlx_win);
		ft_draw_background(game);
		ft_draw_game(game);
		ft_putstr_fd("YOU WIN\n", 1);
		ft_free_all(game);
		exit(0);
	}
}

void	ft_check_game(t_game *game)
{
	if (!game->map || !game->img || !game->player)
		ft_error_free(game);
}

void	ft_check_img(t_game *game)
{
	if (!game->img->img_wall)
		ft_error_free(game);
	if (!game->img->img_player)
		ft_error_free(game);
	if (!game->img->img_exit)
		ft_error_free(game);
	if (!game->img->img_collection)
		ft_error_free(game);
}
