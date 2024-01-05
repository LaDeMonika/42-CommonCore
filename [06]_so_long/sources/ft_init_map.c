/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:52:27 by msimic            #+#    #+#             */
/*   Updated: 2024/01/04 18:22:03 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
This function checks the command line arguments to ensure they
match the expected format.
argc: Number of command line arguments.
argv: Array of command line arguments.
game: Pointer to a structure (t_game) holding game-related information.
It sets game->map_alloc to false initially.
Checks if there are more than two arguments or fewer than two arguments and
raises an error if not.
Checks if the file extension of the map (second argument)
is ".ber" and raises an error if not.
*/
void	ft_check_command_line_arguments(int argc, char **argv, t_game *game)
{
	int	map_parameter_len;

	game->map_alloc = false;
	if (argc > 2)
		ft_error_msg("Too many arguments (It should be only two).", game);
	if (argc < 2)
		ft_error_msg("The Map file is missing.", game);
	map_parameter_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][map_parameter_len - 4], ".ber", 4))
		ft_error_msg("Map file extention is wrong (It should be .ber).", game);
}

/*
This function initializes the game map based on the content of a specified file.
game: Pointer to a structure (t_game) holding game-related information.
argv: Name of the file containing the map.
map_fd: File descriptor for the map file.
Reads the map file line by line using get_next_line.
Appends each line to map_temp (a string containing the entire map).
Counts the number of rows in the map.
Closes the map file, checks for empty lines in the map, and then splits the map
into rows using ft_split.
*/
void	ft_init_map(t_game *game, char *argv)
{
	char	*map_temp;
	char	*line_temp;
	int		map_fd;

	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		ft_error_msg("The Map couldn't be opened. Does the Map exist?", game);
	map_temp = ft_strdup("");
	game->map.rows = 0;
	while (true)
	{
		line_temp = get_next_line(map_fd);
		if (line_temp == NULL)
			break ;
		map_temp = ft_strappend(&map_temp, line_temp);
		free(line_temp);
		game->map.rows++;
	}
	close(map_fd);
	ft_check_for_empty_line(map_temp, game);
	game->map.full = ft_split(map_temp, '\n');
	game->map_alloc = true;
	free(map_temp);
}

/*
This function checks for the presence of empty lines in the map.
map: Pointer to a string containing the entire map.
game: Pointer to a structure (t_game) holding game-related information.
Checks if the map starts or ends with an empty line and raises an error if so.
Checks for empty lines in the middle of the map and raises an error if found.
*/
void	ft_check_for_empty_line(char *map, t_game *game)
{
	int	i;

	i = 0;
	if (map[0] == '\n')
	{
		free(map);
		ft_error_msg("Invalid map.\
The map have an empty line right at the beginning.", game);
	}
	else if (map[ft_strlen(map) - 1] == '\n')
	{
		free (map);
		ft_error_msg("Invalid map. \
The map have an empty line at the end.", game);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_error_msg("Invalid map. \
The map have an empty line at the middle.", game);
		}
		i++;
	}
}
