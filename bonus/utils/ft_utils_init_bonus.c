/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_init_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:30:25 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/06 21:54:38 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_player	*ft_init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (0);
	player->movement = 0;
	player->player_x = 0;
	player->player_y = 0;
	player->player_collection = 0;
	return (player);
}

t_img	*ft_init_img(t_game *game)
{
	t_img	*img;
	int		img_width;
	int		img_height;

	img = malloc(sizeof(t_img));
	if (!img)
		return (0);
	img->img_enemy = 0;
	img->img_wall = mlx_xpm_file_to_image(game->mlx_win,
			"./img/wall.xpm", &img_width, &img_height);
	img->img_player = mlx_xpm_file_to_image(game->mlx_win,
			"./img/mario.xpm", &img_width, &img_height);
	img->img_enemy_l = mlx_xpm_file_to_image(game->mlx_win,
			"./img/goomba_l.xpm", &img_width, &img_height);
	img->img_enemy_r = mlx_xpm_file_to_image(game->mlx_win,
			"./img/goomba_r.xpm", &img_width, &img_height);
	img->img_collection_l = mlx_xpm_file_to_image(game->mlx_win,
			"./img/coin_l.xpm", &img_width, &img_height);
	img->img_collection_r = mlx_xpm_file_to_image(game->mlx_win,
			"./img/coin_r.xpm", &img_width, &img_height);
	img->img_exit = mlx_xpm_file_to_image(game->mlx_win,
			"./img/flag.xpm", &img_width, &img_height);
	img->img_collection = img->img_collection_l;
	img->img_enemy = img->img_enemy_l;
	return (img);
}

t_map	*ft_init_map(char *map_file)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	map->height = ft_get_height(map_file);
	map->width = ft_get_width(map_file);
	map->collection = 0;
	map->exit_x = 0;
	map->exit_y = 0;
	map->enemy_x = 0;
	map->enemy_y = 0;
	map->map = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
		return (0);
	return (map);
}

t_game	*ft_init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	game->mlx_ptr = 0;
	game->mlx_win = 0;
	game->img_width = 0;
	game->img_height = 0;
	game->enemy_timer = 0;
	game->map = 0;
	game->img = 0;
	game->player = 0;
	game->number = 0;
	return (game);
}
