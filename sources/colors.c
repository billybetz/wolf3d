/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:00:55 by bbetz             #+#    #+#             */
/*   Updated: 2016/12/02 15:01:23 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	change_color3(t_env *env, int i)
{
	if (i == COLOR_BLUELIGHT)
	{
		env->rgb->r = 0;
		env->rgb->g = 0;
		env->rgb->b = 30;
	}
	else if (i == COLOR_PURPLE)
	{
		env->rgb->r = 102;
		env->rgb->g = 0;
		env->rgb->b = 204;
	}
	else if (i == COLOR_YELLOW)
	{
		env->rgb->r = 255;
		env->rgb->g = 255;
		env->rgb->b = 102;
	}
}

static void	change_color2(t_env *env, int i)
{
	if (i == COLOR_WHITE)
	{
		env->rgb->r = 255;
		env->rgb->g = 255;
		env->rgb->b = 255;
	}
	else if (i == COLOR_BLACK)
	{
		env->rgb->r = 0;
		env->rgb->g = 0;
		env->rgb->b = 0;
	}
	else if (i == COLOR_GREY)
	{
		env->rgb->r = 125;
		env->rgb->g = 125;
		env->rgb->b = 125;
	}
	change_color3(env, i);
}

void		change_color(t_env *env, int i)
{
	if (i == COLOR_RED)
	{
		env->rgb->r = 255;
		env->rgb->g = 0;
		env->rgb->b = 0;
	}
	else if (i == COLOR_GREEN)
	{
		env->rgb->r = 0;
		env->rgb->g = 255;
		env->rgb->b = 0;
	}
	else if (i == COLOR_BLUE)
	{
		env->rgb->r = 0;
		env->rgb->g = 0;
		env->rgb->b = 255;
	}
	change_color2(env, i);
}
