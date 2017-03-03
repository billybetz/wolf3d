/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline_cadran.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 12:55:55 by bbetz             #+#    #+#             */
/*   Updated: 2016/10/24 11:10:15 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	cadran1_a(t_drawline *draw, t_env *env)
{
	double tmp;

	tmp = draw->x1;
	draw->x1 = draw->x2;
	draw->x2 = tmp;
	tmp = draw->y1;
	draw->y1 = draw->y2;
	draw->y2 = tmp;
	draw->dx *= -1;
	draw->dy *= -1;
	cadran3_a(draw, env);
}

void	cadran1_b(t_drawline *draw, t_env *env)
{
	double tmp;

	tmp = draw->x1;
	draw->x1 = draw->x2;
	draw->x2 = tmp;
	tmp = draw->y1;
	draw->y1 = draw->y2;
	draw->y2 = tmp;
	draw->dx *= -1;
	draw->dy *= -1;
	cadran3_b(draw, env);
}

void	cadran2_a(t_drawline *draw, t_env *env)
{
	double tmp;

	tmp = draw->x1;
	draw->x1 = draw->x2;
	draw->x2 = tmp;
	tmp = draw->y1;
	draw->y1 = draw->y2;
	draw->y2 = tmp;
	draw->dx *= -1;
	draw->dy *= -1;
	cadran4_a(draw, env);
}

void	cadran2_b(t_drawline *draw, t_env *env)
{
	double tmp;

	tmp = draw->x1;
	draw->x1 = draw->x2;
	draw->x2 = tmp;
	tmp = draw->y1;
	draw->y1 = draw->y2;
	draw->y2 = tmp;
	draw->dx *= -1;
	draw->dy *= -1;
	cadran4_b(draw, env);
}
