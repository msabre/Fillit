/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 17:10:33 by msabre            #+#    #+#             */
/*   Updated: 2019/08/13 21:47:55 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static void		map_output(char **map)
{
	int			i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
	map_free(map);
}

static int		minimal_size(int count)
{
	int			i;

	i = 2;
	while (i * i < count * 4)
		i++;
	(i * i >= count) ? i : i++;
	return (i);
}

static void		filit_control(char *str, char **map, t_m *in)
{
	t_lf		*list;
	char		al;
	int			count;
	int			map_size;

	al = 'A';
	count = 0;
	list = NULL;
	if (check_area(str) == -1)
	{
		ft_putstr("error\n");
		return ;
	}
	while (*(str + 1) != '\0')
	{
		ft_lstadd(&list, find_tetro(get_tetro(&str, al), 3, 6, al));
		count++;
		al++;
	}
	map_size = minimal_size(count);
	map = run_solution(list, &in, map, map_size);
	free(in);
	in = NULL;
	ft_lstdel(&list);
	map_output(map);
}

int				main(int argc, char **argv)
{
	t_m			*in;
	char		**map;
	int			fd;
	char		str[550];
	int			i;

	in = NULL;
	map = NULL;
	i = 0;
	if (argc != 2)
	{
		ft_putstr("usage: [filename]\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("File not found\n");
		exit(-1);
	}
	i = read(fd, str, 550);
	str[i] = '\0';
	close(fd);
	filit_control(str, map, in);
	return (0);
}
