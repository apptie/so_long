/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_loop_hook.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:52:49 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/06 14:41:39 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_loop_hook(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->mlx_win);
	ft_draw_background(game);
	ft_draw_game(game);
	return (0);
}

int	ft_window_exit(t_game *game)
{
	ft_free_all(game);
	exit(0);
}
