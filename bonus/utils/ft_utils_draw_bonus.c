/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_draw_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:53:40 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/06 21:53:38 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_draw_background(t_game *game)
{
	void	*img;
	int		img_width;
	int		img_height;
	int		i;
	int		j;

	img = mlx_xpm_file_to_image(game->mlx_win, "./img/white.xpm",
			&img_width, &img_height);
	i = 0;
	while (i < (game->map->height + 1))
	{
		j = 0;
		while (j < game->map->width)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				img, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	ft_draw_game_sub(char c, int i, int j, t_game *game)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img->img_wall, j * 64, i * 64);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img->img_player, j * 64 + 8, i * 64);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img->img_collection, j * 64, i * 64);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img->img_exit, j * 64, i * 64);
	else if (c == 'N')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img->img_enemy, j * 64, i * 64);
}

void	ft_draw_game(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			ft_draw_game_sub(game->map->map[i][j], i, j, game);
			j++;
		}
		i++;
	}
}

void	ft_check_movement(int n, int radix, t_game *game)
{
	if (n > 9)
		ft_check_movement(n / 10, radix + 1, game);
	ft_draw_movement(n % 10, radix, game);
}

void	ft_draw_movement(int n, int radix, t_game *game)
{
	t_number	*number;
	int			width;
	int			height;

	width = game->map->width - radix - 1;
	height = game->map->height;
	number = game->number;
	ft_draw_movement_sec(n, width, height, game);
}
