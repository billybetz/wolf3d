/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:47:40 by bbetz             #+#    #+#             */
/*   Updated: 2016/12/02 15:47:41 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	get_position(t_env *env, int x, int y)
{
	env->map->cases[y][x]->coords[0].x = x * W_SIZE;
	env->map->cases[y][x]->coords[0].y = y * W_SIZE;
	env->map->cases[y][x]->coords[1].x = x * W_SIZE + W_SIZE;
	env->map->cases[y][x]->coords[1].y = y * W_SIZE;
	env->map->cases[y][x]->coords[2].x = x * W_SIZE + W_SIZE;
	env->map->cases[y][x]->coords[2].y = y * W_SIZE + W_SIZE;
	env->map->cases[y][x]->coords[3].x = x * W_SIZE;
	env->map->cases[y][x]->coords[3].y = y * W_SIZE + W_SIZE;
}

static void	get_case_data(t_env *env, int x, int y, char **map)
{
	env->map->cases[y][x] = malloc(sizeof(t_cases));
	if (map[y][x] == '0')
		env->map->cases[y][x]->type = TYPE_VOID;
	else if (map[y][x] == '<' || map[y][x] == '>'
		|| map[y][x] == 'v' || map[y][x] == '^')
	{
		env->map->cases[y][x]->type = TYPE_VOID;
		PERSO_POS.x = x * W_SIZE + (W_SIZE / 2.0);
		PERSO_POS.y = y * W_SIZE + (W_SIZE / 2.0);
		if (map[y][x] == '>')
			PERSO_ANGLE = 0;
		else if (map[y][x] == '^')
			PERSO_ANGLE = 270;
		else if (map[y][x] == '<')
			PERSO_ANGLE = 180;
		else if (map[y][x] == 'v')
			PERSO_ANGLE = 90;
	}
	else if (map[y][x] > '0' && map[y][x] < '4')
		env->map->cases[y][x]->type = WALL;
	get_position(env, x, y);
}

void		convert_map_to_data(char **map, t_env *env)
{
	int x;
	int y;

	y = 0;
	env->map->cases = malloc(sizeof(t_cases**) * NB_LINES + 1);
	while (map[y])
	{
		x = -1;
		env->map->cases[y] = malloc(sizeof(t_cases*) * NB_COLUMNS);
		while (map[y][++x])
			get_case_data(env, x, y, map);
		env->map->cases[y][x] = NULL;
		y++;
	}
	env->map->cases[y] = NULL;
}
