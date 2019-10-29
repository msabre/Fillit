/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:03:40 by msabre            #+#    #+#             */
/*   Updated: 2019/08/11 18:03:07 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# include "libft/libft.h"

t_lf					*find_tetro(char *buffer, int top, int left, char c);
t_m						*intialization_in(t_lf *list, t_m *in);
char					**run_solution(t_lf *list, t_m **in,
							char **map, int map_size);
char					*get_tetro(char **str, char c);
void					map_cl(char **map, char c);
void					map_free(char **map);
void					new_dot(char **map, t_m *in, t_lf **list);
int						check_area(char *str);

#endif
