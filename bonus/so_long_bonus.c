/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:11:05 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/06 21:52:53 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc < 2)
		return (0);
	game = ft_init_game();
	ft_set_game(argv[1], game);
	mlx_hook(game->mlx_win, 17, 0, ft_window_exit, game);
	mlx_key_hook(game->mlx_win, ft_key_hook, game);
	mlx_loop_hook(game->mlx_ptr, ft_loop_hook, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
