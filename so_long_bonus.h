/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:07:58 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/22 13:11:37 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <strings.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <mlx.h>

typedef struct img_info
{
	int		coins_count;
	int		x;
	int		y;
	int		moves;
	int		frame;
	int		e_frame;
	void	*mlx;
	void	*win;
	void	*img;
	char	**map;
}t_info;
typedef struct obj_list
{
	int	space;
	int	exit;
	int	collectible;
	int	start_pos;
	int	not_obj;
	int	ennemy;
}t_objects;
void	check_arg_map(int arg, char **argv);
void	open_and_check(char *file, char ***m_map);
void	check_everything(char **map);
void	check_walls(char **map);
char	**read_map(int fd);
void	print_error_m(void);
void	check_length(char **map);
void	check_objects(char **map);
void	init_struct(t_objects *struc);
void	fill_struct(t_objects *stru, char c);
void	put_everything(t_info *ok);
void	put_all_images(t_info *ok, char c, int i, int j);
void	move_up(t_info *ok);
void	move_down(t_info *ok);
void	move_right(t_info *ok);
void	move_left(t_info *ok);
void	find_player(char **map, int *i, int *j);
void	upload_coin(t_info *ok);
void	put_image(t_info *ok, int i, int j, char *im);
void	count_coins(char **map, int *o);
void	print_err(void);
void	defeat(void);
void	put(t_info *ok);
void	search_c(t_info *ok, char *img);
void	switch_n(char **map);
int		l(char **map);
int		key_hook(int key, t_info *k);
int		ex(void);
int		frame(t_info *ok);

int		ennemy(t_info *ok);
void	move(t_info *list, int option);
void	move_it_up(t_info *ok, int n, int m);
void	move_it_down(t_info *ok, int n, int m);
#endif
