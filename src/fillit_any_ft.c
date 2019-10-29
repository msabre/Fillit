/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_any_ft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:57:21 by msabre            #+#    #+#             */
/*   Updated: 2019/08/13 21:58:44 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void			map_cl(char **map, char c)
{
	int			i;
	int			j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				map[i][j] = '.';
			j++;
		}
		i++;
	}
}

void			map_free(char **map)
{
	int			a;

	a = 0;
	while (map[a])
	{
		free(map[a]);
		a++;
	}
	free(map[a]);
	free(map);
	map = NULL;
}

t_m				*intialization_in(t_lf *list, t_m *in)
{
	t_m			*i;
	t_lf		*ptr;

	if (in)
		free(in);
	in = NULL;
	ptr = list;
	i = (t_m*)malloc(sizeof(t_m));
	i->i = 0;
	i->j = 0;
	i->x = 0;
	i->y = 0;
	i->flag = -1;
	while (list)
	{
		list->i = 0;
		list->j = 0;
		list = list->next;
	}
	list = ptr;
	return (i);
}

void			new_dot(char **map, t_m *in, t_lf **list)
{
	if (map[(*list)->i][(*list)->j + 1] != '\0')
	{
		(*list)->j = (*list)->j + 1;
		(*list)->i = (*list)->i;
	}
	else
	{
		(*list)->j = 0;
		(*list)->i = (*list)->i + 1;
	}
	in->i = (*list)->i;
	in->j = (*list)->j;
	in->i_save = (*list)->i;
	in->j_save = (*list)->j;
}
