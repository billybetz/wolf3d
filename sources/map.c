/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 12:07:17 by bbetz             #+#    #+#             */
/*   Updated: 2016/10/26 14:53:26 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static int	check_map_border(char **map)
{
	int x;
	int y;
	int len;

	y = 0;
	len = ft_strlen(map[0]);
	while (map[y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (y == 0 && (map[y][x] < '1' || map[y][x] > '3'))
				return (0);
			if (x == 0 && (map[y][x] < '1' || map[y][x] > '3'))
				return (0);
			if (x == (len - 1) && (map[y][x] < '1' || map[y][x] > '3'))
				return (0);
			if (!map[y + 1] && (map[y][x] < '1' || map[y][x] > '3'))
				return (0);
		}
		if (len != x)
			return (0);
		y++;
	}
	return (1);
}

/*
**============================================================*
** norme[0] = x |*| norme[1] = y |*| norme[2] = nb_character  *
**============================================================*
**============================================================*
**    norme[3] = nb_void_case |*| norme[4] = nb_wall_case	  *
**============================================================*
*/

static int	check_case(int norme[5], char **map)
{
	if ((map[norme[1]][norme[0]] < '0' || map[norme[1]][norme[0]] > '3') &&
		map[norme[1]][norme[0]] != '>' && map[norme[1]][norme[0]] != '<'
		&& map[norme[1]][norme[0]] != '^' && map[norme[1]][norme[0]] != 'v')
		return (0);
	if (map[norme[1]][norme[0]] == '0')
		norme[3]++;
	if (map[norme[1]][norme[0]] > '0' && map[norme[1]][norme[0]] < '4')
		norme[4]++;
	else if (map[norme[1]][norme[0]] == '>' || map[norme[1]][norme[0]] == '<'
		|| map[norme[1]][norme[0]] == '^' || map[norme[1]][norme[0]] == 'v')
	{
		norme[3]++;
		norme[2]++;
	}
	return (1);
}

/*
**============================================================*
** norme[0] = x |*| norme[1] = y |*| norme[2] = nb_character  *
**============================================================*
**============================================================*
**    norme[3] = nb_void_case |*| norme[4] = nb_wall_case	  *
**============================================================*
*/

int			check_map(char **map, t_env *env)
{
	int		norme[5];

	norme[1] = 0;
	norme[2] = 0;
	norme[3] = 0;
	norme[4] = 0;
	while (map[norme[1]])
	{
		norme[0] = -1;
		while (map[norme[1]][++norme[0]])
		{
			if (check_case(norme, map) == 0)
				return (0);
		}
		norme[1]++;
	}
	if (check_map_border(map) == 0)
		return (0);
	if (norme[2] != 1 || norme[3] == 0)
		return (0);
	NB_COLUMNS = ft_strlen(map[0]);
	NB_LINES = norme[1];
	return (1);
}

char		**get_map(char *file_name)
{
	char **map;

	if (ft_get_file(file_name, &map) == 0)
		return (NULL);
	else
		return (map);
}
