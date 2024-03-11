/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:46:58 by msimic            #+#    #+#             */
/*   Updated: 2024/01/04 18:19:50 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
This function is responsible for checking various aspects of the game map.
game: Pointer to a structure (t_game) holding game-related information.
Calls four sub-functions to check rows, columns, count map parameters,
and verify map parameters.
*/
void	ft_check_map(t_game *game)
{
	ft_check_rows(game);
	ft_check_columns(game);
	ft_count_map_parameters(game);
	ft_verify_map_parameters(game);
}

/*
Checks if there is a wall at the beginning and end of each row.
Raises an error if a wall is missing, indicating an invalid map structure.
game: Pointer to a structure (t_game) holding game-related information.
*/
void	ft_check_rows(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.full[i][0] != WALL)
			ft_error_msg("Invalid Map. \
There's a Wall missing from the first row.\n\
The Map must be surrounded by walls!.", game);
		else if (game->map.full[i][game->map.columns - 1] != WALL)
			ft_error_msg("Invalid Map. \
There's a Wall missing from the last row.\n\
The Map must be surrounded by walls!.", game);
		i++;
	}
}

/*
Checks if there is a wall at the beginning and end of each column.
Raises an error if a wall is missing, indicating an invalid map structure.
game: Pointer to a structure (t_game) holding game-related information.
*/
void	ft_check_columns(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.columns)
	{
		if (game->map.full[0][i] != WALL)
			ft_error_msg("Invalid Map. \
There's a Wall missing from the first column.\n\
The Map must be surrounded by walls!.", game);
		else if (game->map.full[game->map.rows - 1][i] != WALL)
			ft_error_msg("Invalid Map. \
There's a Wall missing from the last column.\n\
The Map must be surrounded by walls!.", game);
		i++;
	}
}

/*
Iterates through the map, counts occurrences of specific
characters, and updates player information.
Counts pizza, exits, and players.
Updates player's position if a player is found.
game: Pointer to a structure (t_game) holding game-related information.
*/
void	ft_count_map_parameters(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (!ft_strchr("CEP01", game->map.full[y][x]))
				ft_error_msg("Invalid Map. Not expected map parameter.", game);
			else if (game->map.full[y][x] == PLAYER)
			{
				game->map.players++;
				game->map.player.x = x;
				game->map.player.y = y;
			}
			else if (game->map.full[y][x] == PIZZA)
				game->map.pizza++;
			else if (game->map.full[y][x] == MAP_EXIT)
				game->map.exit++;
			x++;
		}
		y++;
	}
}

/*
Verifies if the map has at least one pizza, one exit, and one player.
Raises an error if any of these conditions are not met.
game: Pointer to a structure (t_game) holding game-related information.
*/
void	ft_verify_map_parameters(t_game *game)
{
	if (game->map.pizza == 0)
		ft_error_msg("Invalid Map. There is no PIZZA!", game);
	else if (game->map.exit == 0)
		ft_error_msg("Invalid Map. There is no Exit.", game);
	else if (game->map.players != 1)
		ft_error_msg("Invalid Map. Invalid Player quantity. \
It's a single player game.", game);
}
