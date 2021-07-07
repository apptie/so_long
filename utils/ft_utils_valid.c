/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:35:14 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/06 22:12:19 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_wall_sub(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->height)
	{
		if (game->map->map[i++][0] != '1')
			ft_error_free(game);
	}
	i = 0;
	while (i < game->map->height)
	{
		if (game->map->map[i++][game->map->width - 1] != '1')
			ft_error_free(game);
	}
}

void	ft_check_wall(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->map[0][i])
	{
		if (game->map->map[0][i++] != '1')
			ft_error_free(game);
	}
	i = 0;
	while (game->map->map[game->map->height - 1][i])
	{
		if (game->map->map[game->map->height - 1][i++] != '1')
			ft_error_free(game);
	}
	ft_check_wall_sub(game);
}

void	ft_check_content_sub(char c, int *exit, int *collection, int *player)
{
	if (c == 'C')
		*collection += 1;
	else if (c == 'E')
		*exit += 1;
	else if (c == 'P')
	{
		if (*player == 1)
			ft_error_msg("Error\n");
		*player = 1;
	}
}

void	ft_check_content(t_game *game)
{
	int	i;
	int	j;
	int	exit;
	int	collection;
	int	player;

	i = 0;
	exit = 0;
	collection = 0;
	player = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			ft_check_content_sub(game->map->map[i][j],
				&exit, &collection, &player);
			j++;
		}
		i++;
	}
	if (exit == 0 || collection == 0 || player == 0)
		ft_error_msg("Error\n");
}

void	ft_check_map(t_game *game)
{
	if (!game->map)
		ft_error_free(game);
	ft_check_content(game);
	ft_check_wall(game);
	ft_check_width(game);
}
