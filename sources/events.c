/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 12:29:57 by bbetz             #+#    #+#             */
/*   Updated: 2016/10/24 12:06:10 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		up_down_deplacement(int keycode, t_env *env, t_point p1)
{
	if (keycode == KEY_W)
	{
		p1.x = PERSO_POS.x + SPEED * cos(PERSO_ANGLE / 360 * 2 * M_PI);
		p1.y = PERSO_POS.y + SPEED * sin(PERSO_ANGLE / 360 * 2 * M_PI);
		if (env->map->cases[(int)p1.y / W_SIZE][(int)p1.x / W_SIZE]->type
			!= WALL)
		{
			PERSO_POS.x += SPEED * cos(PERSO_ANGLE / 360 * 2 * M_PI);
			PERSO_POS.y += SPEED * sin(PERSO_ANGLE / 360 * 2 * M_PI);
		}
	}
	else if (keycode == KEY_S)
	{
		p1.x = PERSO_POS.x - SPEED * cos(PERSO_ANGLE / 360 * 2 * M_PI);
		p1.y = PERSO_POS.y - SPEED * sin(PERSO_ANGLE / 360 * 2 * M_PI);
		if (env->map->cases[(int)p1.y / W_SIZE][(int)p1.x / W_SIZE]->type
			!= WALL)
		{
			PERSO_POS.x -= SPEED * cos(PERSO_ANGLE / 360 * 2 * M_PI);
			PERSO_POS.y -= SPEED * sin(PERSO_ANGLE / 360 * 2 * M_PI);
		}
	}
}

void		lateral_deplacement(int keycode, t_env *env, t_point p1)
{
	if (keycode == KEY_A)
	{
		p1.x = PERSO_POS.x + SPEED * cos((PERSO_ANGLE - 90) / 360 * 2 * M_PI);
		p1.y = PERSO_POS.y + SPEED * sin((PERSO_ANGLE - 90) / 360 * 2 * M_PI);
		if (env->map->cases[(int)p1.y / W_SIZE][(int)p1.x / W_SIZE]->type
			!= WALL)
		{
			PERSO_POS.x += SPEED * cos((PERSO_ANGLE - 90) / 360 * 2 * M_PI);
			PERSO_POS.y += SPEED * sin((PERSO_ANGLE - 90) / 360 * 2 * M_PI);
		}
	}
	else if (keycode == KEY_D)
	{
		p1.x = PERSO_POS.x - (SPEED / 2) * cos((PERSO_ANGLE - 90) / 180 * M_PI);
		p1.y = PERSO_POS.y - (SPEED / 2) * sin((PERSO_ANGLE - 90) / 180 * M_PI);
		if (env->map->cases[(int)p1.y / W_SIZE][(int)p1.x / W_SIZE]->type
			!= WALL)
		{
			PERSO_POS.x -= (SPEED / 2) * cos((PERSO_ANGLE - 90) / 180 * M_PI);
			PERSO_POS.y -= (SPEED / 2) * sin((PERSO_ANGLE - 90) / 180 * M_PI);
		}
	}
}

void		deplacement(int keycode, t_env *env)
{
	t_point p1;

	p1.x = 0;
	if (keycode == KEY_W || keycode == KEY_S)
		up_down_deplacement(keycode, env, p1);
	else if (keycode == KEY_A || keycode == KEY_D)
		lateral_deplacement(keycode, env, p1);
	else if (keycode == KEY_RIGHT)
		PERSO_ANGLE += 3;
	else if (keycode == KEY_LEFT)
		PERSO_ANGLE -= 3;
	else if (keycode == KEY_UP && PERSO_INC < 400)
		PERSO_INC += 15;
	else if (keycode == KEY_DOWN && PERSO_INC > -400)
		PERSO_INC -= 15;
	draw_map(env);
}

int			event(int keycode, void *env)
{
	if (keycode == KEY_ESC)
		end_program();
	if (keycode == KEY_A || keycode == KEY_D || keycode == KEY_W ||
		keycode == KEY_S || keycode == KEY_LEFT || keycode == KEY_RIGHT ||
		keycode == KEY_UP || keycode == KEY_DOWN)
		deplacement(keycode, env);
	return (0);
}

int			event_close_window(void *env)
{
	printf("window_closed\n");
	(void)env;
	exit(1);
}
