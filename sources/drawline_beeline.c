/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline_beeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 11:59:10 by bbetz             #+#    #+#             */
/*   Updated: 2016/10/24 11:09:55 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	dx_null_a(t_drawline *draw, t_env *env)
{
	while (draw->y1++ < draw->y2)
		ft_write_pixel(env, (int)draw->x1, (int)draw->y1);
}

void	dx_null_b(t_drawline *draw, t_env *env)
{
	while (draw->y1-- > draw->y2)
		ft_write_pixel(env, (int)draw->x1, (int)draw->y1);
}

void	dy_null_a(t_drawline *draw, t_env *env)
{
	while (draw->x1++ < draw->x2)
		ft_write_pixel(env, (int)draw->x1, (int)draw->y1);
}

void	dy_null_b(t_drawline *draw, t_env *env)
{
	while (draw->x1-- > draw->x2)
		ft_write_pixel(env, (int)draw->x1, (int)draw->y1);
}
