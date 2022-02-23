/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_functions2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 07:23:58 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/22 14:41:52 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	switch_n(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'U')
				map[i][j] = 'N';
			j++;
		}
		i++;
	}
}

void	move(t_info *list, int option)
{
	int	a;
	int	b;

	a = 0;
	while (list->map[a] != NULL)
	{
		b = 0;
		while (list->map[a][b] != '\0')
		{
			if (list->map[a][b] == 'N' && option == 0)
				move_it_up(list, a, b);
			else if (list->map[a][b] == 'N' && option == 1)
				move_it_down(list, a, b);
			b++;
		}
		a++;
	}
	switch_n(list->map);
}

void	move_it_up(t_info *ok, int n, int m)
{
	if (ok->map[n - 1][m] == 'P')
		defeat();
	else if (ok->map[n - 1][m] == '0')
	{
		ok->map[n - 1][m] = 'U';
		put_image(ok, n, m, "img/rred.xpm");
		ok->map[n][m] = '0';
		put_image(ok, n - 1, m, "img/fin.xpm");
	}
}

void	move_it_down(t_info *ok, int n, int m)
{
	if (ok->map[n + 1][m] == 'P')
		defeat();
	else if (ok->map[n + 1][m] == '0')
	{
		ok->map[n + 1][m] = 'U';
		put_image(ok, n, m, "img/rred.xpm");
		ok->map[n][m] = '0';
		put_image(ok, n + 1, m, "img/fin.xpm");
	}
}
