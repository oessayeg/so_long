/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:05:36 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/21 13:59:47 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	move_up(t_info *ok)
{
	int	i;
	int	j;

	find_player(ok->map, &i, &j);
	if (i - 1 == 0 || ok->map[i - 1][j] == '1')
		return ;
	else if (ok->map[i - 1][j] == 'E' && ok->coins_count != 0)
		return ;
	else if (ok->map[i - 1][j] == 'E' && ok->coins_count == 0)
	{
		ft_putstr_fd("Victory !\n", 1);
		exit(EXIT_SUCCESS);
	}
	else if (ok->map[i - 1][j] == 'C')
		upload_coin(ok);
	ok->map[i][j] = '0';
	ok->map[i - 1][j] = 'P';
	put_image(ok, i, j, "img/rred.xpm");
	put_image(ok, i - 1, j, "img/rred.xpm");
	put_image(ok, i - 1, j, "img/player.xpm");
	ok->moves++;
	ft_putstr_fd(ft_itoa(ok->moves), 1);
	ft_putstr_fd("\n", 1);
}

void	move_down(t_info *ok)
{
	int	i;
	int	j;

	find_player(ok->map, &i, &j);
	if (i + 1 == l(ok->map) - 1 || ok->map[i + 1][j] == '1')
		return ;
	else if (ok->map[i + 1][j] == 'E' && ok->coins_count != 0)
		return ;
	else if (ok->map[i + 1][j] == 'E' && ok->coins_count == 0)
	{
		ft_putstr_fd("Victory !\n", 1);
		exit(EXIT_SUCCESS);
	}
	else if (ok->map[i + 1][j] == 'C')
		upload_coin(ok);
	ok->map[i][j] = '0';
	ok->map[i + 1][j] = 'P';
	put_image(ok, i, j, "img/rred.xpm");
	put_image(ok, i + 1, j, "img/rred.xpm");
	put_image(ok, i + 1, j, "img/player.xpm");
	ok->moves++;
	ft_putstr_fd(ft_itoa(ok->moves), 1);
	ft_putstr_fd("\n", 1);
}

void	find_player(char **map, int *i, int *j)
{
	int	a;
	int	b;

	a = 1;
	b = 1;
	while (map[a] != NULL)
	{
		b = 1;
		while (map[a][b + 1] != '\0')
		{
			if (map[a][b] == 'P')
			{
				*i = a;
				*j = b;
				return ;
			}
			b++;
		}
		a++;
	}
}

void	put_image(t_info *ok, int i, int j, char *im)
{
	int	n;
	int	m;

	n = 70;
	m = 70;
	ok->img = mlx_xpm_file_to_image(ok->mlx, im, &n, &m);
	mlx_put_image_to_window(ok->mlx, ok->win,
		ok->img, j * 70, i * 70);
}

int	ex(void)
{
	exit(EXIT_FAILURE);
}
