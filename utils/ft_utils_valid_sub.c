/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_valid_sub.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 22:11:21 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/06 22:11:38 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_width(t_game *game)
{
	int	length;
	int	i;

	i = 1;
	length = ft_strlen(game->map->map[0]);
	while (game->map->map[i])
	{
		if (length != ft_strlen(game->map->map[i]))
			ft_error_free(game);
		i++;
	}
}
