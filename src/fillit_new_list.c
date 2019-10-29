/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_new_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:49:15 by msabre            #+#    #+#             */
/*   Updated: 2019/08/13 21:54:06 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static char		**list_filling(char *buffer, int top, int left, t_lf *ptr)
{
	int			j;
	int			a;
	int			i;
	int			side;

	i = 0;
	a = 0;
	j = left;
	side = 1;
	while (ptr->figure[a] != '\0')
	{
		while (ptr->figure[a][i])
		{
			ptr->figure[a][i] = buffer[(top) * 5 + left];
			left++;
			i++;
		}
		a++;
		i = 0;
		left = j + (5 * side);
		side++;
	}
	return (ptr->figure);
}

static t_lf		*list_creator(int top, int bottom, int horizont, char c)
{
	t_lf		*ptr;
	int			j;

	j = 0;
	if (horizont < 0)
		horizont = horizont * (-1);
	ptr = (t_lf*)malloc(sizeof(t_lf));
	ptr->figure = (char**)malloc(sizeof(char*) * (bottom - top + 2));
	ptr->next = NULL;
	while (j != (bottom - top + 1))
	{
		ptr->figure[j] = ft_strnew(horizont);
		ptr->figure[j][horizont] = '\0';
		j++;
	}
	ptr->figure[bottom - top + 1] = NULL;
	ptr->horizont = horizont;
	ptr->vertical = bottom - top + 1;
	ptr->alph = c;
	ptr->i = 0;
	ptr->j = 0;
	return (ptr);
}

t_lf			*find_tetro(char *buffer, int top, int left, char c)
{
	t_lf		*ptr;
	int			right;
	int			bottom;
	int			i;

	i = 0;
	right = 0;
	bottom = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] >= 65 && buffer[i] <= 90)
		{
			(i / 5 < top) ? top = i / 5 : top;
			(i / 5 > bottom) ? bottom = i / 5 : bottom;
			(i % 5 < left) ? left = i % 5 : left;
			(i % 5 > right) ? right = i % 5 : right;
		}
		i++;
	}
	ptr = list_creator(top, bottom, (right - left + 1), c);
	ptr->figure = list_filling(buffer, top, left, ptr);
	free(buffer);
	buffer = NULL;
	return (ptr);
}

char			*get_tetro(char **str, char c)
{
	char		*buffer;
	int			i;

	i = 0;
	while (**str == '\n')
		(*str)++;
	buffer = (char*)malloc(sizeof(char) * 20);
	while ((**str != '\n' || *(*str + 1) != '\n') && (*(*str + 1) != '\0'))
	{
		if (**str == '#')
			buffer[i] = c;
		else
			buffer[i] = **str;
		i++;
		(*str)++;
	}
	buffer[i] = '\0';
	return (buffer);
}
