/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:59:13 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/19 18:20:04 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	check_arg_map(int arg, char **argv)
{
	int	i;

	if (!(arg == 2))
	{
		ft_putstr_fd("Error\nBad arguments\n", 2);
		exit(EXIT_FAILURE);
	}
	i = f_strlen(argv[1]) - 1;
	while (i >= 0 && argv[1][i] != '.')
		i--;
	if (i < 0)
		print_err();
	if (ft_strncmp(&argv[1][i], ".ber", 4) == 0 && argv[1][i + 4] == '\0')
		return ;
	else
		print_err();
}

void	open_and_check(char *file, char ***m_map)
{
	int		fd;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		exit(EXIT_FAILURE);
	}
	map = read_map(fd);
	close(fd);
	check_everything(map);
	if (f_strlen(map[0]) > 36 || l(map) > 18)
		print_error_m();
	(*m_map) = map;
}

void	check_everything(char **map)
{
	check_length(map);
	check_walls(map);
	check_objects(map);
}

void	check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[0][i] != '\0')
	{
		if (map[0][i] != '1')
			print_error_m();
		i++;
	}
	i = 1;
	while (map[i + 1] != NULL)
	{
		if (!(map[i][0] == '1' && map[i][f_strlen(map[0]) - 1] == '1'))
			print_error_m();
		i++;
	}
	j = 0;
	while (map[i][j] != '\0')
	{
		if (map[i][j] != '1')
			print_error_m();
		j++;
	}
}

char	**read_map(int fd)
{
	char	*string;
	char	**fin_re;
	int		i;

	fin_re = malloc(sizeof(char *) * 20);
	i = 0;
	string = get_next_line(fd);
	if (string == NULL)
		print_error_m();
	while (string != NULL && i < 20)
	{
		fin_re[i] = ft_substr(string, 0, f_strlen(string));
		if (string)
			free(string);
		string = get_next_line(fd);
		i++;
	}
	if (i == 1)
	{
		free(fin_re);
		free(fin_re[0]);
		print_error_m();
	}
	fin_re[i] = NULL;
	return (fin_re);
}
