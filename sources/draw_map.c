/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 13:52:45 by bbetz             #+#    #+#             */
/*   Updated: 2016/10/24 11:59:48 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		draw_map(t_env *env)
{
	mlx_destroy_image(env->mlx->ptr_mlx, env->img->ptr_img);
	env->img = malloc(sizeof(t_image));
	env->img->ptr_img = mlx_new_image(env->mlx->ptr_mlx, 1300, 1300);
	env->img->bits_img = mlx_get_data_addr(env->img->ptr_img, &(env->img->bpp),
			&(env->img->size_line), &(env->img->end));
	draw_mini_map(env);
	get_inters(env);
	mlx_put_image_to_window(env->mlx->ptr_mlx, env->mlx->ptr_win,
		env->img->ptr_img, 0, 0);
}
