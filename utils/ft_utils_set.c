/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:33:09 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/06 21:26:37 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_exit(t_game *game)
{
	int		i;
	int		j;
	int		flag;

	if (!game->map)
		return ;
	i = 0;
	flag = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			if (game->map->map[i][j] == 'E')
			{
				ft_set_exit_sub(game, i, j);
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

void	ft_set_player_pos(t_game *game)
{
	int		i;
	int		j;
	int		flag;

	if (!game->player)
		return ;
	i = 0;
	flag = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			if (game->map->map[i][j] == 'P')
			{
				ft_set_player_pos_sub(game, i, j);
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

void	ft_set_collection(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
				map->collection += 1;
			j++;
		}
		i++;
	}
}

void	ft_set_map(char *map_file, t_map *map)
{
	char	*line;
	int		fd;
	int		i;

	if (!map)
		return ;
	i = 0;
	line = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_error_msg("Error\n");
	while (get_next_line(fd, &line) == 1)
	{
		map->map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	if (line)
		free(line);
	map->map[i] = 0;
}

void	ft_set_game(char *map_file, t_game *game)
{
	int	height;
	int	width;

	game->map = ft_init_map(map_file);
	game->player = ft_init_player();
	height = (game->map->height + 1) * 64;
	width = game->map->width * 64;
	ft_set_map(map_file, game->map);
	ft_check_map(game);
	ft_set_player_pos(game);
	ft_set_collection(game->map);
	ft_set_exit(game);
	game->mlx_ptr = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx_ptr, width,
			height, "so_long");
	game->img = ft_init_img(game);
	ft_check_game(game);
	ft_check_img(game);
}
