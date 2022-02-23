/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:02:20 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/22 14:42:29 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	defeat(void)
{
	ft_putstr_fd("Defeat !\n", 1);
	exit(EXIT_FAILURE);
}

int	frame(t_info *ok)
{
	ok->frame++;
	put(ok);
	ok->e_frame++;
	if (ok->e_frame == 4000)
		move(ok, 0);
	else if (ok->e_frame == 8000)
	{
		move(ok, 1);
		ok->e_frame = 0;
	}
	return (1);
}

void	put(t_info *ok)
{
	if (ok->frame == 500)
		search_c(ok, "coins/gold1.xpm");
	if (ok->frame == 1000)
		search_c(ok, "coins/gold2.xpm");
	if (ok->frame == 1500)
		search_c(ok, "coins/gold3.xpm");
	if (ok->frame == 2000)
		search_c(ok, "coins/gold4.xpm");
	if (ok->frame == 2500)
		search_c(ok, "coins/gold6.xpm");
	if (ok->frame == 3000)
		search_c(ok, "coins/gold7.xpm");
	if (ok->frame == 3500)
		search_c(ok, "coins/gold8.xpm");
	if (ok->frame == 4000)
		search_c(ok, "coins/gold9.xpm");
	if (ok->frame == 4500)
	{
		search_c(ok, "coins/gold10.xpm");
		ok->frame = 0;
	}
}

void	search_c(t_info *ok, char *img)
{
	int	i;
	int	j;

	i = 1;
	while (ok->map[i + 1] != NULL)
	{
		j = 1;
		while (ok->map[i][j + 1] != '\0')
		{
			if (ok->map[i][j] == 'C')
			{
				put_image(ok, i, j, "img/rred.xpm");
				put_image(ok, i, j, img);
			}
			j++;
		}
		i++;
	}
}
