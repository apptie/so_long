/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_get_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:22:01 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/06 21:54:14 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_get_height(char *map_file)
{
	char	*line;
	int		fd;
	int		height;

	line = 0;
	height = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_error_msg("Error\n");
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	if (line)
		free(line);
	close(fd);
	return (height);
}

int	ft_get_width(char *map_file)
{
	char	*line;
	int		fd;
	int		width;

	line = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_error_msg("Error\n");
	get_next_line(fd, &line);
	width = ft_strlen(line);
	free(line);
	return (width);
}
