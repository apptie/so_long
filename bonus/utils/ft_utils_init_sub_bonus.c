/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_init_sub_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 20:43:36 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/06 22:06:14 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_number_sub(t_game *game, t_number *number)
{
	int	img_width;
	int	img_height;

	number->img_eight = mlx_xpm_file_to_image(game->mlx_win, "./img/8.xpm",
			&img_width, &img_height);
	number->img_nine = mlx_xpm_file_to_image(game->mlx_win, "./img/9.xpm",
			&img_width, &img_height);
}

t_number	*ft_init_number(t_game *game)
{
	t_number	*number;
	int			img_width;
	int			img_height;

	number = malloc(sizeof(t_number));
	if (!number)
		return (0);
	number->img_zero = mlx_xpm_file_to_image(game->mlx_win,
			"./img/0.xpm", &img_width, &img_height);
	number->img_one = mlx_xpm_file_to_image(game->mlx_win,
			"./img/1.xpm", &img_width, &img_height);
	number->img_two = mlx_xpm_file_to_image(game->mlx_win,
			"./img/2.xpm", &img_width, &img_height);
	number->img_three = mlx_xpm_file_to_image(game->mlx_win,
			"./img/3.xpm", &img_width, &img_height);
	number->img_four = mlx_xpm_file_to_image(game->mlx_win,
			"./img/4.xpm", &img_width, &img_height);
	number->img_five = mlx_xpm_file_to_image(game->mlx_win,
			"./img/5.xpm", &img_width, &img_height);
	number->img_six = mlx_xpm_file_to_image(game->mlx_win,
			"./img/6.xpm", &img_width, &img_height);
	number->img_seven = mlx_xpm_file_to_image(game->mlx_win,
			"./img/7.xpm", &img_width, &img_height);
	ft_init_number_sub(game, number);
	return (number);
}
