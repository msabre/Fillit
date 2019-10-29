/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:47:29 by msabre            #+#    #+#             */
/*   Updated: 2019/08/13 21:48:04 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int		check_figure(char *s, int count, int i)
{
	while (*s)
	{
		count = 0;
		i = 1;
		while ((*s != '\n' || *(s + 1) != '\n')
			&& (*s != '\n' || *(s + 1) != '\0'))
		{
			if (*s == '#')
			{
				((i + 1 < 21) && *(s + 1) == '#') ? count++ : count;
				((i + 5 < 21) && *(s + 5) == '#') ? count++ : count;
				((i - 1 < 21)
					&& (i - 1 >= 1) && *(s - 1) == '#') ? count++ : count;
				((i - 5 < 21)
					&& (i - 5 >= 1) && *(s - 5) == '#') ? count++ : count;
			}
			s++;
			i++;
		}
		if (count != 6 && count != 8)
			return (-1);
		s++;
	}
	return (1);
}

static int		check_row(char **str)
{
	int			count;
	int			hash;

	count = 0;
	hash = 0;
	while (count < 16 && **str != '\0')
	{
		while (**str != '\n')
		{
			if (**str != '.' && **str != '#' && **str != '\n')
				return (-1);
			if (**str == '#')
				++hash;
			++(*str);
			++count;
		}
		if (count % 4 != 0)
			return (-1);
		(*str)++;
	}
	return (hash);
}

int				check_area(char *str)
{
	int			count;
	int			hash;
	char		*ptr;

	count = 0;
	ptr = str;
	while (*str != '\0')
	{
		hash = check_row(&str);
		if ((hash == -1) || (hash > 4))
			return (-1);
		count++;
		if (count > 26)
			return (-1);
		if (*str == '\n')
			str++;
		else if (*(str - 1) == '\n' && (*(str - 2) == '.'
				|| *(str - 2) == '#') && *str != '\0')
			return (-1);
	}
	if (*(str - 1) != '\n' || (*(str - 2) != '.' && *(str - 2) != '#'))
		return (-1);
	return (check_figure(ptr, 0, 0));
}
