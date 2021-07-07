/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_etc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:53:46 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/06 20:03:34 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
