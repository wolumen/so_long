#include <mlx.h>
#include <stdio.h>			// printf
#include <unistd.h>
#include <stdlib.h>			// exit
#include <fcntl.h>			// für open

# define KEY_W 		119
# define KEY_S		115
# define KEY_A 		97
# define KEY_D 		100
# define KEY_ESC	65307

# define WALL			'1'
# define BACKGROUND		'0'
# define COLLECTIBLE	'C'
# define PLAYER			'P'
# define EXIT			'E'

# define WINDOW_WIDTH	(max.map.cols * max.world.world_width)			// pixel
# define WINDOW_HEIGHT	(max.map.rows * max.world.world_height)

# define TRUE		1
# define FALSE		0


typedef struct	s_map
{
	char		**map_arr;
	int			rows;
	int			cols;
	int			collectible_count;
	int			exit_x;
	int			exit_y;
}	t_map;


typedef struct	s_player
{
	void		*img_d;
	void		*img_u;
	void		*img_l;
	void		*img_r;
	int			x;
	int			y;
	int			img_width;
	int			img_height;
	int 		steps;
	int			collectible_found;
}	t_player;

typedef struct	s_img
{
	void		*background;
	void		*wall;
	void		*collectible;
	void		*exit;
	int			world_width;
	int			world_height;
}	t_img;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_player	figur;
	t_img		world;
	t_map		map;
}	t_game;



int		deal_key(int key, void *param);
void	init_map(t_game *max, char **argv);
void	init_images(t_game *max);
void	set_map(t_game *max);
int		next_field_wall(int key, t_game *max);


