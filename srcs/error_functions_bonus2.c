/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions_bonus2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:55:27 by oessayeg          #+#    #+#             */
/*   Updated: 2022/03/11 11:58:05 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long_bonus.h"

void	print_error_m(void)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Unvalid map\n", 2);
	exit(EXIT_FAILURE);
}

void	check_length(char **map)
{
	int	i;
	int	len;

	i = -1;
	while (map[++i] != NULL)
		map[i][f_strlen(map[i]) - 1] = '\0';
	len = f_strlen(map[0]);
	i = 0;
	while (map[++i] != NULL)
	{
		if (f_strlen(map[i]) != len)
			print_error_m();
	}
}

void	check_objects(char **map)
{
	int			i;
	int			j;
	t_objects	obj;

	init_struct(&obj);
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			fill_struct(&obj, map[i][j]);
			j++;
		}
		i++;
	}
	if (!(obj.exit > 0 && obj.collectible > 0
			&& obj.start_pos == 1 && obj.not_obj == 0
			&& obj.ennemy > 0))
		print_error_m();
}

void	init_struct(t_objects *stru)
{
	stru->space = 0;
	stru->exit = 0;
	stru->collectible = 0;
	stru->start_pos = 0;
	stru->not_obj = 0;
	stru->ennemy = 0;
}

void	fill_struct(t_objects *stru, char c)
{
	if (c == '0')
		stru->space++;
	else if (c == 'E')
		stru->exit++;
	else if (c == 'C')
		stru->collectible++;
	else if (c == 'P')
		stru->start_pos++;
	else if (c == 'N')
		stru->ennemy++;
	else if (c != '1')
		stru->not_obj++;
}
