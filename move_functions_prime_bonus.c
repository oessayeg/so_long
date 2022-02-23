/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions_prime_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:56:00 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/21 17:14:52 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

int	key_hook(int key, t_info *k)
{
	if (key == 53)
		exit(EXIT_FAILURE);
	else if (key == 13 || key == 126)
		move_up(k);
	else if (key == 1 || key == 125)
		move_down(k);
	else if (key == 2 || key == 124)
		move_right(k);
	else if (key == 0 || key == 123)
		move_left(k);
	return (0);
}

void	move_right(t_info *ok)
{
	int	i;
	int	j;

	find_player(ok->map, &i, &j);
	if (j + 1 == f_strlen(ok->map[0]) - 1 || ok->map[i][j + 1] == '1')
		return ;
	if (ok->map[i][j + 1] == 'E' && ok->coins_count != 0)
		return ;
	else if (ok->map[i][j + 1] == 'E' && ok->coins_count == 0)
	{
		ft_putstr_fd("Victory !\n", 1);
		exit(EXIT_SUCCESS);
	}
	else if (ok->map[i][j + 1] == 'C')
		upload_coin(ok);
	else if (ok->map[i][j + 1] == 'N')
		defeat();
	ok->map[i][j] = '0';
	ok->map[i][j + 1] = 'P';
	put_image(ok, i, j, "img/rred.xpm");
	put_image(ok, i, j + 1, "img/rred.xpm");
	put_image(ok, i, j + 1, "img/ren.xpm");
	ok->moves++;
	put_image(ok, 0, 0, "img/ti.xpm");
	mlx_string_put(ok->mlx, ok->win, 0, 0, 0x00FF0000, ft_itoa(ok->moves));
}

void	move_left(t_info *ok)
{
	int	i;
	int	j;

	find_player(ok->map, &i, &j);
	if (j - 1 == 0 || ok->map[i][j - 1] == '1')
		return ;
	if (ok->map[i][j - 1] == 'E' && ok->coins_count != 0)
		return ;
	else if (ok->map[i][j - 1] == 'E' && ok->coins_count == 0)
	{
		ft_putstr_fd("Victory !\n", 1);
		exit(EXIT_SUCCESS);
	}
	else if (ok->map[i][j - 1] == 'C')
		upload_coin(ok);
	else if (ok->map[i][j - 1] == 'N')
		defeat();
	ok->map[i][j] = '0';
	ok->map[i][j - 1] = 'P';
	put_image(ok, i, j, "img/rred.xpm");
	put_image(ok, i, j - 1, "img/rred.xpm");
	put_image(ok, i, j - 1, "img/ren.xpm");
	ok->moves++;
	put_image(ok, 0, 0, "img/ti.xpm");
	mlx_string_put(ok->mlx, ok->win, 0, 0, 0x00FF0000, ft_itoa(ok->moves));
}

void	count_coins(char **map, int *o)
{
	int	i;
	int	j;

	*o = 0;
	i = 1;
	while (map[i] != NULL)
	{
		j = 1;
		while (map[i][j + 1] != '\0')
		{
			if (map[i][j] == 'C')
				*o += 1;
			j++;
		}
		i++;
	}
}

void	print_err(void)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Map doesn't end with '.ber' extension\n", 2);
	exit(EXIT_FAILURE);
}
