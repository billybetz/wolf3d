/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 16:33:27 by bbetz             #+#    #+#             */
/*   Updated: 2016/10/26 14:45:50 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	init_env(t_env *env)
{
	env->img = malloc(sizeof(t_image));
	env->mlx = malloc(sizeof(t_mlx));
	env->d = malloc(sizeof(t_drawline));
	env->map = malloc(sizeof(t_map));
	env->map->character = malloc(sizeof(t_character));
	PERSO_FOV = 66;
	PERSO_INC = 0;
	env->rgb = malloc(sizeof(t_color));
	env->rgb->r = 255;
	env->rgb->g = 255;
	env->rgb->b = 255;
}

int			main(int ac, char **av)
{
	t_env	env;
	char	**map;
	char	*msg;

	msg = "wrong number of arguments.\nUsage :\t./wolf3d [map]";
	if (ac != 2)
		return ((int)(ft_failure(msg, 0)));
	init_env(&env);
	if ((map = get_map(av[1])) == NULL)
		ft_exit_error("Incorrect file\n");
	if ((check_map(map, &env)) == 0)
		ft_exit_error("map error\n");
	convert_map_to_data(map, &env);
	env.mlx->ptr_mlx = mlx_init();
	env.mlx->ptr_win = mlx_new_window(env.mlx->ptr_mlx, WIDHT_WIN,
			HEIGHT_WIN, "Wolf3d");
	env.img->ptr_img = mlx_new_image(env.mlx->ptr_mlx, WIDHT_IMG, HEIGHT_IMG);
	env.img->bits_img = mlx_get_data_addr(env.img->ptr_img, &(env.img->bpp),
			&(env.img->size_line), &(env.img->end));
	draw_map(&env);
	mlx_do_key_autorepeaton(env.mlx->ptr_mlx);
	mlx_hook(env.mlx->ptr_win, 2, 0, event, &env);
	mlx_hook(env.mlx->ptr_win, 17, 3, event_close_window, &env);
	mlx_loop(env.mlx->ptr_mlx);
	return (0);
}
