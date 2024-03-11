/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:52:48 by msimic            #+#    #+#             */
/*   Updated: 2024/01/04 18:20:55 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
This function initializes various variables in the game structure.
game: Pointer to a structure (t_game) holding game-related information.
Initializes counters for pizza, exit, and players to zero.
Sets the number of movements to zero.
Calculates the number of columns in the map by subtracting 1 from the
length of the first row of the map.
Sets the initial direction of the player sprite to RIGHT.
*/
void	ft_init_vars(t_game *game)
{
	game->map.pizza = 0;
	game->map.exit = 0;
	game->map.players = 0;
	game->movements = 0;
	game->map.columns = ft_strlen(game->map.full[0]) - 1;
	game->player_sprite = RIGHT;
}

/*
This function initializes the MiniLibX (mlx) for graphics handling.
game: Pointer to a structure (t_game) holding game-related information.
Attempts to initialize MiniLibX using mlx_init().
If the initialization fails, it frees the mlx_ptr and raises an error.
Creates a new window using mlx_new_window with dimensions based on the
number of columns and rows in the map.
If window creation fails, it frees the mlx_ptr and raises an error.
*/
void	ft_init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		free(game->mlx_ptr);
		ft_error_msg("Couldn't find mlx pointer. Try it using a VNC.", game);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
	game->map.columns * IMG_WIDTH, game->map.rows * IMG_HEIGHT, "so_long");
	if (game->win_ptr == NULL)
	{
		free(game->mlx_ptr);
		ft_error_msg("Couldn't create the Window.", game);
	}
}

/*
This function initializes various sprites used in the game.
game: Pointer to a structure (t_game) holding game-related information.
mlx: Pointer to the MiniLibX instance.
Calls ft_new_sprite for each sprite with its corresponding XPM file path.
Initializes various sprite members in the t_game structure.
*/
void	ft_init_sprites(t_game *game)
{
	void	*mlx;

	mlx = game->mlx_ptr;
	game->wall = ft_new_sprite(mlx, WALL_XPM, game);
	game->floor = ft_new_sprite(mlx, FLOOR_XPM, game);
	game->pizza = ft_new_sprite(mlx, COINS_XPM, game);
	game->player_front = ft_new_sprite(mlx, PLAYER_FRONT_XPM, game);
	game->player_left = ft_new_sprite(mlx, PLAYER_LEFT_XPM, game);
	game->player_right = ft_new_sprite(mlx, PLAYER_RIGHT_XPM, game);
	game->player_back = ft_new_sprite(mlx, PLAYER_BACK_XPM, game);
	game->open_exit = ft_new_sprite(mlx, OPEN_EXIT_XPM, game);
	game->exit_closed = ft_new_sprite(mlx, EXIT_CLOSED_XPM, game);
}

/*
This function loads a new sprite from an XPM file.
mlx: Pointer to the MiniLibX instance.
path: Path to the XPM file.
game: Pointer to a structure (t_game) holding game-related information.
Uses mlx_xpm_file_to_image to load the XPM file into an image (sprite.xpm_ptr).
Checks if the loading fails and raises an error if so.
Returns the initialized t_image structure containing information about
the loaded sprite.
*/
t_image	ft_new_sprite(void *mlx, char *path, t_game *game)
{
	t_image	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		ft_error_msg("Couldn't find a sprite. Does it exist?", game);
	return (sprite);
}
