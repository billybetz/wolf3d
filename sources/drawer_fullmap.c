/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer_fullmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:34:35 by bbetz             #+#    #+#             */
/*   Updated: 2016/12/02 18:35:29 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	draw_sky_wall_ground(t_env *env, int x_y[2], double len, char ori)
{
	while (x_y[1] < HEIGHT_IMG)
	{
		if (x_y[0] > MINIMAP_SIZE || x_y[1] > MINIMAP_SIZE)
		{
			if (x_y[1] > (HEIGHT_IMG / 2 - len / 2 + PERSO_INC) &&
					x_y[1] < (HEIGHT_IMG / 2 + len / 2 + PERSO_INC))
			{
				if (ori == 'n')
					change_color(env, COLOR_YELLOW);
				else if (ori == 's')
					change_color(env, COLOR_GREEN);
				else if (ori == 'e')
					change_color(env, COLOR_RED);
				else if (ori == 'o')
					change_color(env, COLOR_PURPLE);
				ft_write_pixel(env, x_y[0], x_y[1]);
			}
			else if (x_y[1] > HEIGHT_IMG / 2 + len / 2 + PERSO_INC)
				change_color(env, COLOR_GREY);
			else if (x_y[1] < HEIGHT_IMG / 2 - len / 2 + PERSO_INC)
				change_color(env, COLOR_BLUELIGHT);
			ft_write_pixel(env, x_y[0], x_y[1]);
		}
		x_y[1]++;
	}
}

void		ft_draw_all(t_env *env, t_point inter, int x, char orient)
{
	double	dist;
	double	len;
	int		x_y[2];
	t_point perso_pos_minimap;
	t_point inter_pos_minimap;

	x_y[1] = 0;
	x_y[0] = x;
	change_color(env, COLOR_RED);
	perso_pos_minimap.x = PERSO_POS.x / W_SIZE * (MINIMAP_SIZE / NB_COLUMNS);
	perso_pos_minimap.y = PERSO_POS.y / W_SIZE * (MINIMAP_SIZE / NB_LINES);
	inter_pos_minimap.x = inter.x / W_SIZE * (MINIMAP_SIZE / NB_COLUMNS);
	inter_pos_minimap.y = inter.y / W_SIZE * (MINIMAP_SIZE / NB_LINES);
	ft_drawline(env, perso_pos_minimap, inter_pos_minimap);
	change_color(env, COLOR_WHITE);
	dist = ft_get_distance(PERSO_POS, inter);
	len = W_SIZE / dist * 277 * 3;
	draw_sky_wall_ground(env, x_y, len, orient);
	change_color(env, COLOR_WHITE);
}
