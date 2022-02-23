/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:56:23 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/22 14:41:30 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_info	st;

	check_arg_map(argc, argv);
	open_and_check(argv[1], &st.map);
	st.mlx = mlx_init();
	if (st.mlx == NULL)
		return (0);
	st.win = mlx_new_window(st.mlx, f_strlen(st.map[0]) * 70,
			l(st.map) * 70, "so_long");
	if (st.win == NULL)
		return (0);
	st.moves = 0;
	st.frame = 0;
	st.e_frame = 0;
	count_coins(st.map, &st.coins_count);
	put_everything(&st);
	mlx_hook(st.win, 2, 1L << 0, key_hook, &st);
	mlx_hook(st.win, 17, 0, ex, NULL);
	mlx_loop_hook(st.mlx, frame, &st);
	mlx_loop(st.mlx);
}

void	put_everything(t_info *ok)
{
	int	i;
	int	j;

	i = 0;
	while (ok->map[i] != NULL)
	{
		j = 0;
		while (ok->map[i][j] != '\0')
		{
			put_all_images(ok, ok->map[i][j], i, j);
			j++;
		}
		i++;
	}
}

void	put_all_images(t_info *ok, char c, int i, int j)
{
	int	a;
	int	b;

	if (c == '1')
	{
		if (i == 0 || i == l(ok->map) - 1 || j == 0
			|| j == f_strlen(ok->map[0]) - 1)
			ok->img = mlx_xpm_file_to_image(ok->mlx, "img/ti.xpm", &a, &b);
		else
			ok->img = mlx_xpm_file_to_image(ok->mlx, "img/box2.xpm", &a, &b);
	}
	else if (c == '0')
		ok->img = mlx_xpm_file_to_image(ok->mlx, "img/rred.xpm", &a, &b);
	else if (c == 'E')
		ok->img = mlx_xpm_file_to_image(ok->mlx, "img/dr1.xpm", &a, &b);
	else if (c == 'C')
		return ;
	else if (c == 'P')
		ok->img = mlx_xpm_file_to_image(ok->mlx, "img/ren.xpm", &a, &b);
	else if (c == 'N')
		ok->img = mlx_xpm_file_to_image(ok->mlx, "img/fin.xpm", &a, &b);
	mlx_put_image_to_window(ok->mlx, ok->win, ok->img, j * 70, i * 70);
}

int	l(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

void	upload_coin(t_info *ok)
{
	int	i;
	int	j;

	i = 1;
	ok->coins_count -= 1;
	if (ok->coins_count == 0)
	{
		while (ok->map[i] != NULL)
		{
			j = 1;
			while (ok->map[i][j] != '\0')
			{
				if (ok->map[i][j] == 'E')
				{
					put_image(ok, i, j, "img/rred.xpm");
					put_image(ok, i, j, "img/dr2.xpm");
				}
				j++;
			}
			i++;
		}
	}
}
