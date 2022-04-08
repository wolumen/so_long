/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:27:47 by jpreissn          #+#    #+#             */
/*   Updated: 2022/04/06 11:27:47 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>			// printf
# include <unistd.h>
# include <stdlib.h>		// exit
# include <fcntl.h>			// für open

# define KEY_W			119
# define KEY_S			115
# define KEY_A			97
# define KEY_D			100
# define KEY_ESC		65307

# define WALL			'1'
# define BACKGROUND		'0'
# define COLLECTIBLE	'C'
# define PLAYER			'P'
# define EXIT			'E'

# define SIGNS			"10CPE"

# define TRUE			1
# define FALSE			0

# define WHITE			"\033[0m"
# define RED			"\033[31m"
# define YEL			"\x1B[33m"

typedef struct s_map
{
	char		**map_arr;
	int			rows;
	int			cols;
	int			collectible_count;
	int			exit_x;
	int			exit_y;
}	t_map;

typedef struct s_map_error
{
	int			borders;
	int			rectangle;
	int			p_count;
	int			e_count;
	int			c_count;
	int			wrong_sign;
	int			shut_down;
}	t_error;

typedef struct s_player
{
	void		*img_d;
	void		*img_u;
	void		*img_l;
	void		*img_r;
	int			x;
	int			y;
	int			img_width;
	int			img_height;
	int			steps;
	int			collectible_found;
}	t_player;

typedef struct s_img
{
	void		*background;
	void		*wall;
	void		*collectible;
	void		*exit;
	int			world_width;
	int			world_height;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	t_player	figur;
	t_img		world;
	t_map		map;
	t_error		err;
}	t_game;

// initalize
void	init(t_game *max, char **argv);
void	init_player(t_game *max);
void	init_exit(t_game *max, int i, int j);
void	init_window(t_game *max);
void	init_map(t_game *max, char **argv);
void	init_images(t_game *max);
void	init_errors(t_game *max);

// map
int		open_file(t_game *max, char **argv);
void	get_rows_n_cols(t_game *max, int file);
void	allocate_array(t_game *max);
void	fill_array(t_game *max, int file);
void	set_map(t_game *max);

// errors
void	check_errors(t_game *max);
void	parse_signs(t_game *max);
void	print_error(char *str, t_game *max);
void	parse_borders(t_game *max);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
void	ft_putstr_fd(char const *s, int fd);
void	check_args(t_game *max, int argc, char **argv);
int		ft_strrncmp(const char *s1, const char *s2, size_t n);

// moves
void	direction(int key, t_game *max);
void	move(int key, t_game *max);
char	next_field(int key, t_game *max);
char	current_field(t_game *max);
int		next_field_wall(int key, t_game *max);
void	collect_collectible(t_game *max);
void	display_steps(t_game *max);
void	ft_putnbr_fd(int n, int fd);
void	win(t_game *max);

// hooks
int		deal_key(int key, void *param);
int		deal_mouse(int button,int x,int y,void *param);

// clean up
int		ft_exit(t_game *max);
void	free_map_array(t_game *max);
void	free_images(t_game *max);

#endif