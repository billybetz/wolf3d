/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:20:25 by bbetz             #+#    #+#             */
/*   Updated: 2016/12/02 11:20:26 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static void	draw_circle(t_env *env, double r, double x_center, double y_center)
{
	int x;
	int y;
	int m;

	x = 0;
	y = r;
	m = 5 - 4 * r;
	while (x <= y)
	{
		ft_write_pixel(env, x + x_center, y + y_center);
		ft_write_pixel(env, y + x_center, x + y_center);
		ft_write_pixel(env, -x + x_center, y + y_center);
		ft_write_pixel(env, -y + x_center, x + y_center);
		ft_write_pixel(env, x + x_center, -y + y_center);
		ft_write_pixel(env, y + x_center, -x + y_center);
		ft_write_pixel(env, -x + x_center, -y + y_center);
		ft_write_pixel(env, -y + x_center, -x + y_center);
		if (m > 0)
		{
			y--;
			m = m - 8 * y;
		}
		x++;
		m = m + 8 * x + 4;
	}
}

static void	draw_wall(t_env *env, int x, int y)
{
	t_point	p1;
	t_point	p2;
	int		i;
	int		end;

	end = MINIMAP_SIZE / NB_LINES;
	i = 0;
	p1.y = y * MINIMAP_SIZE / NB_LINES;
	p1.x = x * MINIMAP_SIZE / NB_COLUMNS;
	p2.x = p1.x + MINIMAP_SIZE / NB_COLUMNS;
	p2.y = p1.y;
	while (i <= end)
	{
		ft_drawline(env, p1, p2);
		p1.y++;
		p2.y++;
		i++;
	}
}

static void	draw_void(t_env *env, int x, int y)
{
	t_point p1;
	t_point p2;
	t_point p3;
	t_point p4;

	p1.x = x * MINIMAP_SIZE / NB_COLUMNS;
	p1.y = y * MINIMAP_SIZE / NB_LINES;
	p2.x = p1.x;
	p2.y = p1.y + MINIMAP_SIZE / NB_LINES;
	p3.x = p2.x + MINIMAP_SIZE / NB_COLUMNS;
	p3.y = p2.y;
	p4.x = p3.x;
	p4.y = p1.y;
	ft_drawline(env, p1, p2);
	ft_drawline(env, p2, p3);
	ft_drawline(env, p3, p4);
	ft_drawline(env, p4, p1);
}

static void	draw_character(t_env *env)
{
	draw_circle(env, 3, PERSO_POS.x / W_SIZE * (MINIMAP_SIZE /
		NB_COLUMNS), PERSO_POS.y / W_SIZE * (MINIMAP_SIZE / NB_LINES));
	draw_circle(env, 1, PERSO_POS.x / W_SIZE * (MINIMAP_SIZE /
		NB_COLUMNS), PERSO_POS.y / W_SIZE * (MINIMAP_SIZE / NB_LINES));
}

void		draw_mini_map(t_env *env)
{
	int x;
	int y;

	y = 0;
	while (env->map->cases[y])
	{
		x = -1;
		while (env->map->cases[y][++x])
		{
			if (env->map->cases[y][x]->type == WALL)
				draw_wall(env, x, y);
			else
				draw_void(env, x, y);
		}
		y++;
	}
	draw_character(env);
}
