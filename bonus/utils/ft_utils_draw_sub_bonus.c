/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_draw_sub_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 21:47:48 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/06 21:53:46 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_draw_movement_thr(int n, int width, int height, t_game *game)
{
	t_number	*number;

	number = game->number;
	if (n == 6)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			number->img_six, width * 64, height * 64);
	else if (n == 7)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			number->img_seven, width * 64, height * 64);
	else if (n == 8)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			number->img_eight, width * 64, height * 64);
	else if (n == 9)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			number->img_nine, width * 64, height * 64);
}

void	ft_draw_movement_sec(int n, int width, int height, t_game *game)
{
	t_number	*number;

	number = game->number;
	if (n == 0)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			number->img_zero, width * 64, height * 64);
	else if (n == 1)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			number->img_one, width * 64, height * 64);
	else if (n == 2)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			number->img_two, width * 64, height * 64);
	else if (n == 3)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			number->img_three, width * 64, height * 64);
	else if (n == 4)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			number->img_four, width * 64, height * 64);
	else if (n == 5)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			number->img_five, width * 64, height * 64);
	else
		ft_draw_movement_thr(n, width, height, game);
}
