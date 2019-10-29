/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:53:08 by msabre            #+#    #+#             */
/*   Updated: 2019/08/13 21:46:11 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static char		**map_creator(int i, char **map)
{
	char		**area;
	int			ptr;

	if (map)
		map_free(map);
	ptr = 0;
	area = (char**)malloc(sizeof(char*) * (i + 1));
	while (ptr < i)
	{
		area[ptr] = ft_strnew(i);
		area[ptr][i] = '\0';
		ptr++;
	}
	area[ptr] = NULL;
	return (area);
}

static void		find_dots(char **map, t_m *i, t_lf *l)
{
	int			dots_count;
	int			y;

	dots_count = 0;
	y = 0;
	while (map[i->i][i->j] != '.' && map[i->i + 1])
	{
		if (map[i->i][i->j] == '\0')
		{
			i->i++;
			i->j = 0;
		}
		else
			i->j++;
	}
	while (l && l->figure[0][y] == '.')
	{
		dots_count++;
		y++;
	}
	while (i->j - dots_count < 0)
		dots_count--;
	i->j = i->j - dots_count;
	i->i_save = i->i;
	i->j_save = i->j;
}

static int		check_free_place(char **map, t_lf *l, t_m *i)
{
	i->x = 0;
	while (l->figure[i->x] && map[i->i])
	{
		i->y = 0;
		while (map[i->i][i->j] && l->figure[i->x][i->y])
		{
			if (map[i->i][i->j] != '.' && l->figure[i->x][i->y] != '.')
				return (-1);
			if (map[i->i][i->j] == '.' && l->figure[i->x][i->y] != '.')
				map[i->i][i->j] = l->figure[i->x][i->y];
			i->j++;
			i->y++;
		}
		if (l->figure[i->x][i->y])
			return (-1);
		i->j = i->j - l->horizont;
		i->i++;
		i->x++;
	}
	l->i = i->i - l->vertical;
	l->j = i->j;
	i->i = 0;
	i->j = 0;
	return (1);
}

static int		filit_solution(char **map, t_lf **list, t_m *in, int map_size)
{
	if (*list == NULL)
		return (1);
	while (((*list)->vertical) + in->i <= map_size)
	{
		while (((*list)->horizont) + in->j <= map_size)
		{
			if (check_free_place(map, *list, in) == 1)
			{
				*list = (*list)->next;
				find_dots(map, in, *list);
				return (filit_solution(map, list, in, map_size));
			}
			else
			{
				map_cl(map, (*list)->alph);
				in->i = in->i_save;
				in->j = in->j_save++;
			}
		}
		in->i_save++;
		in->i = in->i_save;
		in->j_save = 0;
		in->j = 0;
	}
	return (-1);
}

char			**run_solution(t_lf *list, t_m **in, char **map, int map_size)
{
	t_lf		*ptr;

	ptr = list;
	while (map_size != 10000)
	{
		*in = intialization_in(list, *in);
		map = map_creator(map_size, map);
		while (list)
		{
			if (filit_solution(map, &list, *in, map_size) == 1)
			{
				map_size = 9999;
				break ;
			}
			list = list->prev;
			if (list != NULL)
			{
				map_cl(map, list->alph);
				new_dot(map, *in, &list);
			}
		}
		map_size++;
		list = ptr;
	}
	return (map);
}
