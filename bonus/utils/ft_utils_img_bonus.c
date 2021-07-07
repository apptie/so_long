/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_img_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 21:33:55 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/06 21:54:22 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_img(t_game *game)
{
	if (!game->img->img_wall)
		ft_error_free(game);
	if (!game->img->img_player)
		ft_error_free(game);
	if (!game->img->img_exit)
		ft_error_free(game);
	if (!game->img->img_enemy)
		ft_error_free(game);
	if (!game->img->img_enemy_r)
		ft_error_free(game);
	if (!game->img->img_enemy_l)
		ft_error_free(game);
	if (!game->img->img_collection)
		ft_error_free(game);
	if (!game->img->img_collection_r)
		ft_error_free(game);
	if (!game->img->img_collection_l)
		ft_error_free(game);
}

void	ft_check_number(t_game *game)
{
	if (!game->number->img_zero)
		ft_error_free(game);
	if (!game->number->img_one)
		ft_error_free(game);
	if (!game->number->img_three)
		ft_error_free(game);
	if (!game->number->img_four)
		ft_error_free(game);
	if (!game->number->img_five)
		ft_error_free(game);
	if (!game->number->img_six)
		ft_error_free(game);
	if (!game->number->img_seven)
		ft_error_free(game);
	if (!game->number->img_eight)
		ft_error_free(game);
	if (!game->number->img_nine)
		ft_error_free(game);
	if (!game->number->img_two)
		ft_error_free(game);
}
