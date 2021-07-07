/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_player_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:43:44 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/06 21:55:12 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_move_player_up(t_game *game)
{
	int		player_y;
	int		player_x;

	player_y = game->player->player_y;
	player_x = game->player->player_x;
	if (game->map->map[player_y - 1][player_x] != '1')
	{
		if (game->map->map[player_y - 1][player_x] == 'E')
		{
			ft_check_exit(game);
			return ;
		}
		if (game->map->map[player_y - 1][player_x] == 'C')
			game->player->player_collection += 1;
		if (game->map->map[player_y - 1][player_x] == 'N')
			ft_player_sub(game);
		game->map->map[player_y][player_x] = '0';
		game->map->map[player_y - 1][player_x] = 'P';
		game->player->player_y -= 1;
		game->player->movement += 1;
	}
}

void	ft_move_player_down(t_game *game)
{
	int		player_y;
	int		player_x;

	player_y = game->player->player_y;
	player_x = game->player->player_x;
	if (game->map->map[player_y + 1][player_x] != '1')
	{
		if (game->map->map[player_y + 1][player_x] == 'E')
		{
			ft_check_exit(game);
			return ;
		}
		if (game->map->map[player_y + 1][player_x] == 'N')
			ft_player_sub(game);
		if (game->map->map[player_y + 1][player_x] == 'C')
			game->player->player_collection += 1;
		game->map->map[player_y][player_x] = '0';
		game->map->map[player_y + 1][player_x] = 'P';
		game->player->player_y += 1;
		game->player->movement += 1;
	}
}

void	ft_move_player_right(t_game *game)
{
	int		player_y;
	int		player_x;

	player_y = game->player->player_y;
	player_x = game->player->player_x;
	if (game->map->map[player_y][player_x + 1] != '1')
	{
		if (game->map->map[player_y][player_x + 1] == 'E')
		{
			ft_check_exit(game);
			return ;
		}
		if (game->map->map[player_y][player_x + 1] == 'N')
			ft_player_sub(game);
		if (game->map->map[player_y][player_x + 1] == 'C')
			game->player->player_collection += 1;
		game->map->map[player_y][player_x] = '0';
		game->map->map[player_y][player_x + 1] = 'P';
		game->player->player_x += 1;
		game->player->movement += 1;
	}
}

void	ft_move_player_left(t_game *game)
{
	int		player_y;
	int		player_x;

	player_y = game->player->player_y;
	player_x = game->player->player_x;
	if (game->map->map[player_y][player_x - 1] != '1')
	{
		if (game->map->map[player_y][player_x - 1] == 'E')
		{
			ft_check_exit(game);
			return ;
		}
		if (game->map->map[player_y][player_x - 1] == 'N')
			ft_player_sub(game);
		if (game->map->map[player_y][player_x - 1] == 'C')
			game->player->player_collection += 1;
		game->map->map[player_y][player_x] = '0';
		game->map->map[player_y][player_x - 1] = 'P';
		game->player->player_x -= 1;
		game->player->movement += 1;
	}
}

void	ft_move_player(int key, t_game *game)
{
	t_map	*map;

	map = game->map;
	if (key == UP)
		ft_move_player_up(game);
	else if (key == DOWN)
		ft_move_player_down(game);
	else if (key == RIGHT)
		ft_move_player_right(game);
	else if (key == LEFT)
		ft_move_player_left(game);
}
