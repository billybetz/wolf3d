/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:25:40 by bbetz             #+#    #+#             */
/*   Updated: 2016/11/02 14:25:43 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

t_point		get_horizontal_inter(t_env *env, double alpha)
{
	t_point p;
	double	ya;
	double	xa;

	p = PERSO_POS;
	if (alpha > 180)
		p.y = (int)(p.y / W_SIZE) * W_SIZE;
	else
		p.y = (int)(p.y / W_SIZE) * W_SIZE + 1;
	p.x = p.x - (PERSO_POS.y - p.y) / tan((alpha / 180.0) * M_PI);
	ya = (alpha > 180) ? -W_SIZE : W_SIZE;
	xa = (alpha > 180) ? W_SIZE / tan((-alpha / 180) * M_PI) :
	-W_SIZE / tan((-alpha / 180) * M_PI);
	while (p.x / W_SIZE >= 0 && p.x / W_SIZE < NB_COLUMNS
			&& p.y / W_SIZE > 0 && p.y / W_SIZE < NB_LINES
			&& env->map->cases[(int)p.y / W_SIZE][(int)p.x / W_SIZE]->type
			!= WALL
			&& env->map->cases[(int)p.y / W_SIZE - 1][(int)p.x / W_SIZE]->type
			!= WALL)
	{
		p.y += ya;
		p.x += xa;
	}
	return (p);
}

t_point		get_vertical_inter(t_env *env, double alpha)
{
	t_point inter;
	double	ya;
	double	xa;

	if (alpha > 270 || alpha < 90)
		inter.x = (int)(PERSO_POS.x / W_SIZE) * W_SIZE + 1;
	else
		inter.x = (int)(PERSO_POS.x / W_SIZE) * W_SIZE;
	inter.y = PERSO_POS.y - (PERSO_POS.x - inter.x) * tan((alpha / 180) * M_PI);
	xa = (alpha > 270 || alpha < 90) ? W_SIZE : -W_SIZE;
	ya = (alpha > 270 || alpha < 90) ? W_SIZE * tan((alpha / 180) * M_PI) :
	W_SIZE * tan((-alpha / 180) * M_PI);
	while (inter.x / W_SIZE > 0 && inter.x / W_SIZE < NB_COLUMNS
		&& inter.y / W_SIZE >= 0 && inter.y / W_SIZE <= NB_LINES
		&& env->map->cases[(int)inter.y / W_SIZE][(int)inter.x / W_SIZE]->type
		!= WALL &&
		env->map->cases[(int)inter.y / W_SIZE]
		[(int)(inter.x / W_SIZE) - 1]->type != WALL)
	{
		inter.y += ya;
		inter.x += xa;
	}
	return (inter);
}

static void	comp_and_draw(t_env *env, t_point inter[2], int x, char orient)
{
	double		dist1;
	double		dist2;

	dist1 = ft_get_distance(PERSO_POS, inter[1]);
	dist2 = ft_get_distance(PERSO_POS, inter[0]);
	if (dist1 > dist2)
	{
		orient = (inter[1].y >= PERSO_POS.y) ? 'n' : 's';
		ft_draw_all(env, inter[0], x, orient);
	}
	else
	{
		orient = (inter[1].x >= PERSO_POS.x) ? 'o' : 'e';
		ft_draw_all(env, inter[1], x, orient);
	}
}

void		get_first_inter(t_env *env, double alpha, int x)
{
	t_point		inter[2];
	char		orient;

	if (alpha == 0 || alpha == 180)
	{
		inter[1] = get_vertical_inter(env, alpha);
		orient = (inter[1].x >= PERSO_POS.x) ? 'o' : 'e';
		ft_draw_all(env, inter[1], x, orient);
		return ;
	}
	else if (alpha == 90 || alpha == 270)
	{
		inter[0] = get_horizontal_inter(env, alpha);
		orient = (inter[1].y >= PERSO_POS.y) ? 'n' : 's';
		ft_draw_all(env, inter[0], x, orient);
		return ;
	}
	orient = 'd';
	inter[0] = get_horizontal_inter(env, alpha);
	inter[1] = get_vertical_inter(env, alpha);
	comp_and_draw(env, inter, x, orient);
}

void		get_inters(t_env *env)
{
	double	alpha;
	int		i;

	i = 0;
	while (i < WIDHT_IMG)
	{
		if (PERSO_ANGLE < 0)
			PERSO_ANGLE = PERSO_ANGLE + 360;
		else if (PERSO_ANGLE >= 360)
			PERSO_ANGLE -= 360;
		alpha = PERSO_ANGLE + (((double)i / WIDHT_IMG) - 0.5) * PERSO_FOV;
		if (alpha < 0)
			alpha = alpha + 360;
		else if (alpha >= 360)
			alpha -= 360;
		get_first_inter(env, alpha, i);
		i++;
	}
}
