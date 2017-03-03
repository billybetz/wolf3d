/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline_cadran2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 12:56:06 by bbetz             #+#    #+#             */
/*   Updated: 2016/10/24 11:10:28 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	cadran3_b(t_drawline *draw, t_env *env)
{
	draw->dy *= 2;
	draw->e = draw->dx;
	draw->dx *= 2;
	while (1)
	{
		ft_write_pixel(env, (int)draw->x1, (int)draw->y1);
		draw->x1--;
		if (draw->x1 <= draw->x2)
			break ;
		draw->e += draw->dy;
		if (draw->e >= 0)
		{
			draw->y1++;
			draw->e += draw->dx;
		}
	}
}

void	cadran3_a(t_drawline *draw, t_env *env)
{
	draw->dx *= 2;
	draw->e = draw->dy;
	draw->dy *= 2;
	while (1)
	{
		ft_write_pixel(env, (int)draw->x1, (int)draw->y1);
		draw->y1++;
		if (draw->y1 >= draw->y2)
			break ;
		draw->e += draw->dx;
		if (draw->e <= 0)
		{
			draw->x1--;
			draw->e += draw->dy;
		}
	}
}

void	cadran4_a(t_drawline *draw, t_env *env)
{
	draw->dy *= 2;
	draw->e = draw->dx;
	draw->dx *= 2;
	while (1)
	{
		ft_write_pixel(env, (int)draw->x1, (int)draw->y1);
		draw->x1--;
		if (draw->x1 <= draw->x2)
			break ;
		draw->e -= draw->dy;
		if (draw->e >= 0)
		{
			draw->y1--;
			draw->e += draw->dx;
		}
	}
}

void	cadran4_b(t_drawline *draw, t_env *env)
{
	draw->dx *= 2;
	draw->e = draw->dy;
	draw->dy *= 2;
	while (1)
	{
		ft_write_pixel(env, (int)draw->x1, (int)draw->y1);
		draw->y1--;
		if (draw->y1 <= draw->y2)
			break ;
		draw->e -= draw->dx;
		if (draw->e >= 0)
		{
			draw->x1--;
			draw->e += draw->dy;
		}
	}
}
