/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_set_sub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:31:06 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/06 15:39:38 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
