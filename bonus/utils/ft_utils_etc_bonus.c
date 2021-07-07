/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_etc_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:53:46 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/06 21:54:04 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
		free(map->map[i++]);
	free(map->map);
	free(map);
}

void	ft_free_all(t_game *game)
{
	if (!game)
		return ;
	if (game->img)
		free(game->img);
	if (game->player)
		free(game->player);
	if (game->number)
		free(game->number);
	if (game->map)
		ft_free_map(game->map);
	free(game);
}

void	ft_error_free(t_game *game)
{
	ft_putstr_fd("Error\n", 2);
	ft_free_all(game);
	exit(0);
}

void	ft_error_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(0);
}

void	ft_player_sub(t_game *game)
{
	ft_putstr_fd("GAME OVER\n", 1);
	ft_free_all(game);
	exit(0);
}
