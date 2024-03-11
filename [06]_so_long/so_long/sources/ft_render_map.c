/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:52:06 by msimic            #+#    #+#             */
/*   Updated: 2024/01/04 17:57:38 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Renders the entire map by iterating through each element.
Calls ft_identify_sprite for each element to determine which sprite to render.
Prints the current number of movements using ft_print_movements.
game: Pointer to a structure (t_game) holding game-related information.
Returns 0.
*/
int	ft_render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			ft_identify_sprite(game, y, x);
			x++;
		}
		y++;
	}
	ft_print_movements(game);
	return (0);
}

/*
Identifies the type of sprite at a given position (y, x) in the map.
Calls ft_render_sprite or ft_render_player based on the identified sprite type.
game: Pointer to a structure (t_game) holding game-related information.
y: Vertical position in the map.
x: Horizontal position in the map.
*/
void	ft_identify_sprite(t_game *game, int y, int x)
{
	char	parameter;

	parameter = game->map.full[y][x];
	if (parameter == WALL)
		ft_render_sprite (game, game->wall, y, x);
	else if (parameter == FLOOR)
		ft_render_sprite (game, game->floor, y, x);
	else if (parameter == PIZZA)
		ft_render_sprite (game, game->pizza, y, x);
	else if (parameter == MAP_EXIT)
	{
		if (game->map.pizza == 0)
			ft_render_sprite (game, game->open_exit, y, x);
		else
			ft_render_sprite (game, game->exit_closed, y, x);
	}
	else if (parameter == PLAYER)
		ft_render_player (game, y, x);
}

/*
Renders the player sprite based on the current player sprite direction.
Calls ft_render_sprite with the appropriate player sprite.
game: Pointer to a structure (t_game) holding game-related information.
y: Vertical position in the map.
x: Horizontal position in the map.
*/
void	ft_render_player(t_game *game, int y, int x)
{
	if (game->player_sprite == FRONT)
		ft_render_sprite (game, game->player_front, y, x);
	if (game->player_sprite == LEFT)
		ft_render_sprite (game, game->player_left, y, x);
	if (game->player_sprite == RIGHT)
		ft_render_sprite (game, game->player_right, y, x);
	if (game->player_sprite == BACK)
		ft_render_sprite (game, game->player_back, y, x);
}

/*
Renders a sprite at a specified position in the window using MiniLibX functions.
game: Pointer to a structure (t_game) holding game-related information.
sprite: Structure containing information about the sprite image.
line: Vertical position in the window.
column: Horizontal position in the window.
*/
void	ft_render_sprite(t_game *game, t_image sprite, int line, int column)
{
	mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
	sprite.xpm_ptr, column * sprite.x, line * sprite.y);
}

/*
Prints the current number of movements on the game window.
Uses mlx_string_put to display the text.
game: Pointer to a structure (t_game) holding game-related information.
*/
void	ft_print_movements(t_game *game)
{
	char	*movements;
	char	*phrase;

	movements = ft_itoa(game->movements);
	phrase = ft_strjoin("Movements : ", movements);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 40, 20, 99999, phrase);
	free(movements);
	free(phrase);
}
