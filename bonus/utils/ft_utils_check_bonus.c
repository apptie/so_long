/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_check_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:50:59 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/06 21:53:26 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

int	ft_check_empty(char c, t_game *game)
{
	if (c == 'P')
	{
		ft_putstr_fd("GAME OVER\n", 1);
		ft_free_all(game);
		exit(0);
	}
	else if (c == '0')
		return (1);
	else
		return (0);
}

void	ft_check_game(t_game *game)
{
	if (!game->map || !game->img || !game->player || !game->number)
		ft_error_free(game);
}
