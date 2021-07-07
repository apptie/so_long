/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_set_sub_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:31:06 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/06 21:55:32 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_set_exit_sub(t_game *game, int i, int j)
{
	game->map->exit_x = j;
	game->map->exit_y = i;
}

void	ft_set_player_pos_sub(t_game *game, int i, int j)
{
	game->player->player_x = j;
	game->player->player_y = i;
}

void	ft_set_enemy_sub(t_game *game, int i, int j)
{
	game->map->map[i][j] = 'N';
	game->map->enemy_x = j;
	game->map->enemy_y = i;
}

void	ft_set_enemy(t_game *game)
{
	int	i;
	int	j;
	int	flag;

	if (!game->map)
		return ;
	i = 0;
	flag = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			if (game->map->map[i][j] == '0')
			{
				ft_set_enemy_sub(game, i, j);
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag)
			break ;
		i++;
	}
}
