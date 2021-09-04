/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 20:14:07 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/30 21:56:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/minilibx-linux/mlx_int.h"
# include "./get_next_line.h"
# include <errno.h>
# include <math.h>

# define MALLOC_FAILED 100
# define MALLOC_FAILED1 101

# define NUMBER_OF_ARGS 400
# define INVALID_ARG1 401

# define DUPLICATE_IDENTIFIER 500
# define WRONG_IDENTIFIER 501
# define MISSING_IDENTIFIER 502

# define INVALID_OPTION_NUMBER 503
# define WRONG_OPTIONS 504
# define MISSING_OPTIONS 505
# define WRONG_VALUE_OPTION 506
# define WRONG_PATH 507

# define FULL_OPTIONS 1
# define NOT_FULL_OPTIONS 0

# define WRONG_MAP_EMPTY 600
# define WRONG_MAP_TAB 601
# define WRONG_MAP_CHAR 602
# define VALIDATE_MAP_FAIL 603

# define MINILIBX_INIT_FAIL 700

# define LINE_MAP 1
# define EMPTY_LINE 1

# define TILE_SIZE 64
# define MINIMAP_RATIO 0.2
# define MINIMAP_GCOLOR 0xFF505050
# define MINIMAP_BCOLOR 0xFF101010
# define PLAYER_COLOR 0xFFFFFF00
# define PLAYER_DIM 3
# define OMEGA		0.05
# define VLINEAR 	4
# define FOV 1.047197551
# define FOVT 0.523598775
# define WALL_STRIP_WIDTH 1

# define ESC_KEY 0x00ff1b
# define W_KEY 0x0077
# define S_KEY 0x0073
# define A_KEY 0x0061
# define D_KEY 0x0064
# define M_KEY 0x6D
# define T_KEY 0x74
# define RIGHT_KEY 0x00ff53
# define LEFT_KEY 0x00ff51
# define UP_KEY 0xFF52
# define DOWN_KEY 0xFF54

# define PI 3.1415926536
# define TPI 6.283185307
# define PIT 1.570796327

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;
typedef struct s_path_text
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
}					t_path_text;
typedef struct s_file
{
	int				fd;	
	t_path_text		t;	
	t_color			f;	
	t_color			c;	
	char			*strmap;	
}					t_file;
typedef struct s_fmap
{
	int				cols;
	int				rows;
	int				p_posx;
	int				p_posy;
	char			p_dir;
	char			**mat;
}					t_fmap;
typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;
typedef struct s_player
{
	float	x;
	float	y;	
	int		t_dir;
	int		w_dir;
	int		w_side;
	float	ang;
	int		speed;
	float	pi_speed;
	float	pp_dist;
	float	offset_mini;
}					t_player;
typedef struct s_coo
{
	float				x;
	float				y;	
}					t_coo;
typedef struct s_ray
{
	float	ang;
	t_coo	w_hit;
	float	dist;
	int		is_hit_v;
	int		face_up;
	int		face_right;
	char	w_hit_text;
}			t_ray;
typedef struct s_texture
{
	char	*path;
	int		width;
	int		height;
	t_data	data;
}	t_text;
typedef struct s_walls
{
	t_text	text_n;
	t_text	text_s;
	t_text	text_e;
	t_text	text_w;	
}	t_walls;		
typedef struct s_cast
{
	int		sum;
	float	xstep;
	float	ystep;	
	t_coo	itc;
	t_coo	h_w_hit;
	t_coo	v_w_hit;
	t_coo	next_h_touch;
	t_coo	next_v_touch;
	t_coo	to_check;
	int		found_h_hit;
	int		found_v_hit;
	float	h_hit_dist;
	float	v_hit_dist;

}	t_cast;
typedef struct s_cub
{
	t_file			*file;
	t_fmap			*fmap;
	void			*mlx;	
	void			*win;
	t_data			data;
	t_player		p;
	int				minimap_opt;
	int				texture_opt;
	t_ray			*ray;
	t_walls			walls;
	t_cast			cast;
}				t_cub;
int		verify_args(int argc, char **argv);
void	init_cub(t_cub *cub);
void	init_cub_file(t_cub *cub);
void	init_fmap(t_cub *cub);
void	init_player(t_cub *cub);
void	file_in_heap(t_cub *cub);
void	fmap_in_heap(t_cub *cub);
void	ray_in_heap(t_cub *cub);
void	init_cast(t_cub *cub);
void	init_textures(t_cub *cub);
void	free_read_line(char **str, int fd);
void	free_file_content(t_cub *cub);
void	free_fmap_content(t_cub *cub);
void	close_and_free_fl(char **line, t_cub *cub);
void	close_and_free_fm(t_cub *cub);
void	error_handling(int error_code);
void	error_sys(int error_code);
void	error_mlx(int error_code);
void	error_args(int error_code);
void	error_ident(int error_code);
void	error_options(int error_code);
void	error_map(int error_code);
void	initialize_cub_file(t_cub *cub);
void	read_file(char *path, t_cub *cub);
void	parse_file(char **line, t_cub *cub);
int		check_full_options(t_cub *cub);
void	read_map(char **line, t_cub *cub);
void	jump_spaces(char *str, int *p);
void	get_textures(char **line_read, t_cub *cub, char k);
void	get_floorceiling(char **line_read, t_cub *cub, char k);
int		strtrim_handled(char **str, char const *set);
char	*ft_strtrim_begin(char const *s1, char const *set);
int		strtrim_begin_handled(char **str, char const *set);
int		strjoin_handled(char **line_read, char **pointed);
int		linemap_insert_star(char **pointed);
char	*str_cutfirsts(char const *s1, int len);
int		str_cutfirsts_handled(char **str, int len);
void	mlx_test(void);
void	normalize_map(t_cub *cub);
void	validate_map(t_cub *cub);
void	check_map(t_cub *cub);
int		wrong_v_limits(t_cub *cub);
int		wrong_h_limits(t_cub *cub);
int		opened_map(t_cub *cub);
int		more_players(t_cub *cub);
void	fill_fmap(t_cub *cub);
void	play(t_cub *cub);
int		key_pressed(int keycode, t_cub *cub);
int		key_released(int keycode, t_cub *cub);
int		close_win(t_cub *cub);
void	game_setup(t_cub *cub);
void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
int		my_mlx_pixel_pick(t_data *data, int x, int y);
int		create_trgb(int t, int r, int g, int b);
int		put_square(t_cub *cub, float x, float y, float dim);
int		put_h_minigrid(t_cub *cub);
int		put_v_minigrid(t_cub *cub);
int		put_minimap_bkg(t_cub *cub);
int		put_squares_on_grid(t_cub *cub);
int		put_player(t_cub *cub);
int		put_player_dick(t_cub *cub);
void	cast_all_rays(t_cub *cub);
void	cast_one(float ray_ang, int strip, t_cub *cub);
void	h_intersection(int strip, t_cub *cub);
void	v_intersection(int strip, t_cub *cub);
void	h_find_a_wall(int strip, t_cub *cub);
void	v_find_a_wall(int strip, t_cub *cub);
void	calculate_hit_distances(t_cub *cub);
void	choising_distance(int strip, t_cub *cub);
float	normalize_angle(float angle);
int		map_collision(t_cub *cub, float next_x, float next_y);
float	distance_of_pts(float x1, float y1, float x2, float y2);
int		draw_mini_ray(t_cub *cub, int strip);
void	render_walls(t_cub *cub);
void	render_minimap(t_cub *cub);
int		render_game(t_cub *cub);
void	reset_frame(t_cub *cub);
int		draw_wall_strip(t_cub *cub, int strip);
int		pic_color_wall(t_cub *cub, int i);
void	get_texture(t_text *text, t_cub *cub);
void	create_textures(t_cub *cub);
void	push_image(t_cub *cub);
void	fill_texture(t_cub *cub, int strip);
void	render_texture(t_cub *cub);
int		draw_wall_strip_t(t_cub *cub, int strip);
#endif
