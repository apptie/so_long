/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_enemy_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:47:47 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/06 21:53:56 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_move_enemy_sub(int flag, t_game *game)
{
	t_map	*map;

	map = game->map;
	if (flag == 2)
	{
		if (ft_check_empty(map->map[map->enemy_y][map->enemy_x - 1], game) == 1)
		{
			map->map[map->enemy_y][map->enemy_x] = '0';
			map->map[map->enemy_y][map->enemy_x - 1] = 'N';
			map->enemy_x -= 1;
		}
	}
	else if (flag == 3)
	{
		if (ft_check_empty(map->map[map->enemy_y][map->enemy_x + 1], game) == 1)
		{
			map->map[map->enemy_y][map->enemy_x] = '0';
			map->map[map->enemy_y][map->enemy_x + 1] = 'N';
			map->enemy_x += 1;
		}
	}
}

void	ft_move_enemy(int flag, t_game *game)
{
	t_map	*map;

	map = game->map;
	if (flag == 0)
	{
		if (ft_check_empty(map->map[map->enemy_y - 1][map->enemy_x], game) == 1)
		{
			map->map[map->enemy_y][map->enemy_x] = '0';
			map->map[map->enemy_y - 1][map->enemy_x] = 'N';
			map->enemy_y -= 1;
		}
	}
	else if (flag == 1)
	{
		if (ft_check_empty(map->map[map->enemy_y + 1][map->enemy_x], game) == 1)
		{
			map->map[map->enemy_y][map->enemy_x] = '0';
			map->map[map->enemy_y + 1][map->enemy_x] = 'N';
			map->enemy_y += 1;
		}
	}
	else
		ft_move_enemy_sub(flag, game);
}
