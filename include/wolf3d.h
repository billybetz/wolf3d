/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 16:34:12 by bbetz             #+#    #+#             */
/*   Updated: 2016/10/26 14:53:23 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../minilibx_macos/mlx.h"
# include "../libft/include/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_T 17
# define KEY_Y 16
# define KEY_U 32
# define KEY_I 34
# define KEY_O 31
# define KEY_P 35
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_G 5
# define KEY_H 4
# define KEY_J 38
# define KEY_K 40
# define KEY_L 37
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_N 45
# define KEY_M 46
# define KEY_ESC 53
# define KEY_PAD_0 82
# define KEY_PAD_1 83
# define KEY_PAD_2 84
# define KEY_PAD_3 85
# define KEY_PAD_4 86
# define KEY_PAD_5 87
# define KEY_PAD_6 88
# define KEY_PAD_7 89
# define KEY_PAD_8 91
# define KEY_PAD_9 92
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_DEL 51
# define KEY_RET 36
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define WIDHT_IMG 1300
# define HEIGHT_IMG 1300
# define WIDHT_WIN 1300
# define HEIGHT_WIN 1300
# define COLOR_BLACK 0
# define COLOR_RED 1
# define COLOR_GREEN 2
# define COLOR_BLUE 3
# define COLOR_WHITE 4
# define COLOR_GREY 5
# define COLOR_BLUELIGHT 6
# define COLOR_PURPLE 7
# define COLOR_YELLOW 8
# define W_SIZE 1
# define WALL 1
# define TYPE_VOID 2
# define TYPE_CHARACTER 3
# define SPEED 0.075
# define MINIMAP_SIZE 300
# define SIZELINE env->img->size_line
# define PERSO_INC env->map->character->inclinaison
# define PERSO_ANGLE env->map->character->view_angle
# define PERSO_FOV env->map->character->fov
# define PERSO_POS env->map->character->coord
# define CASE_TYPE env->map->cases[y][x]->type
# define CASE_POS env->map->cases[y][x]->coords
# define NB_COLUMNS env->map->nb_columns
# define NB_LINES env->map->nb_lines

typedef struct	s_character
{
	t_point		coord;
	double		view_angle;
	int			fov;
	int			inclinaison;
}				t_character;

typedef struct	s_cases
{
	int			type;
	t_point		coords[4];
}				t_cases;

typedef	struct	s_map
{
	t_character	*character;
	t_cases		***cases;
	double		nb_columns;
	double		nb_lines;
}				t_map;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_image
{
	void		*ptr_img;
	char		*bits_img;
	int			size_line;
	int			bpp;
	int			end;
}				t_image;

typedef struct	s_mlx
{
	void		*ptr_mlx;
	void		*ptr_win;
}				t_mlx;

typedef struct	s_drawline
{
	double		dx;
	double		dy;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		z1;
	double		z2;
	double		e;
}				t_drawline;

typedef struct	s_env
{
	t_image		*img;
	t_mlx		*mlx;
	t_map		*map;
	t_color		*rgb;
	t_drawline	*d;
}				t_env;

void			get_points(t_env *env, char *av);
void			draw_map(t_env *env);
char			**get_map(char *file_name);
void			convert_map_to_data(char **map, t_env *env);
int				check_map(char **map, t_env *env);

/*
**	==========	**
**	  EVENTS	**
**	==========	**
*/

int				event(int keycode, void *cp_env);
int				event_close_window(void *env);
void			end_program(void);

/*
**	==========	**
**	 DRAWLINE	**
**	==========	**
*/

void			change_color(t_env *env, int i);
void			ft_drawline(t_env *env, t_point p1, t_point p2);
void			ft_write_pixel(t_env *env, int x, int y);
void			cadran1_a(t_drawline *draw, t_env *env);
void			cadran1_b(t_drawline *draw, t_env *env);
void			cadran2_a(t_drawline *draw, t_env *env);
void			cadran2_b(t_drawline *draw, t_env *env);
void			cadran3_a(t_drawline *draw, t_env *env);
void			cadran3_b(t_drawline *draw, t_env *env);
void			cadran4_a(t_drawline *draw, t_env *env);
void			cadran4_b(t_drawline *draw, t_env *env);
void			dx_null_a(t_drawline *draw, t_env *env);
void			dx_null_b(t_drawline *draw, t_env *env);
void			dy_null_a(t_drawline *draw, t_env *env);
void			dy_null_b(t_drawline *draw, t_env *env);

/*
**	==========	**
**	  DEBUG		**
**	==========	**
*/

void			draw_mini_map(t_env *env);
void			do_map(t_env *env);
void			get_inters(t_env *env);
void			print_data(t_env env);
void			print_map(char **map);
void			convert_map_to_data(char **map, t_env *env);
void			ft_draw_all(t_env *env, t_point inter, int x, char orient);
void			get_first_inter(t_env *env, double alpha, int x);
t_point			get_vertical_inter(t_env *env, double alpha);
t_point			get_horizontal_inter(t_env *env, double alpha);
double			get_dist(t_point p1, t_point p2);
int				is_wall(t_env *env, t_point inter);

#endif
