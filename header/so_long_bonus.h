/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:11:33 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/06 22:10:00 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include "get_next_line_bonus.h"

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53

typedef struct s_map	t_map;
typedef struct s_game	t_game;
typedef struct s_img	t_img;
typedef struct s_player	t_player;
typedef struct s_number	t_number;

struct s_game
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			img_width;
	int			img_height;
	int			enemy_timer;
	t_map		*map;
	t_img		*img;
	t_player	*player;
	t_number	*number;
};

struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		collection;
	int		exit_x;
	int		exit_y;
	int		enemy_x;
	int		enemy_y;
};

struct s_img
{
	void	*img_wall;
	void	*img_player;
	void	*img_exit;
	void	*img_enemy;
	void	*img_enemy_r;
	void	*img_enemy_l;
	void	*img_collection;
	void	*img_collection_r;
	void	*img_collection_l;
};

struct s_player
{
	int	movement;
	int	player_x;
	int	player_y;
	int	player_collection;
};

struct s_number
{
	void	*img_zero;
	void	*img_one;
	void	*img_two;
	void	*img_three;
	void	*img_four;
	void	*img_five;
	void	*img_six;
	void	*img_seven;
	void	*img_eight;
	void	*img_nine;
};

int			ft_get_height(char *map_file);
int			ft_get_width(char *map_file);

t_map		*ft_init_map(char *map_file);
t_game		*ft_init_game(void);
t_img		*ft_init_img(t_game *game);
t_player	*ft_init_player(void);
t_number	*ft_init_number(t_game *game);

void		ft_set_map(char *map_file, t_map *map);
void		ft_set_game(char *map_file, t_game *game);
void		ft_set_plyaer_pos(t_game *game);
void		ft_set_collection(t_map *map);
void		ft_set_enemy(t_game *game);
void		ft_set_exit_sub(t_game *game, int i, int j);
void		ft_set_player_pos_sub(t_game *game, int i, int j);

void		ft_check_map(t_game *game);

void		ft_draw_game(t_game *game);
void		ft_draw_background(t_game *game);
void		ft_draw_movement_sec(int n, int width, int height, t_game *game);

int			ft_loop_hook(t_game *game);
int			ft_window_exit(t_game *game);

int			ft_key_hook(int key, t_game *game);

void		ft_move_player(int key, t_game *game);

void		ft_check_exit(t_game *game);
int			ft_check_empty(char c, t_game *game);
void		ft_check_game(t_game *game);
void		ft_check_width(t_game *game);

void		ft_move_enemy(int flag, t_game *game);

void		ft_check_movement(int n, int radix, t_game *game);
void		ft_draw_movement(int n, int radix, t_game *game);

void		ft_error_msg(char *msg);
void		ft_error_free(t_game *game);
void		ft_free_all(t_game *game);
void		ft_player_sub(t_game *game);

void		ft_check_img(t_game *game);
void		ft_check_number(t_game *game);

#endif
