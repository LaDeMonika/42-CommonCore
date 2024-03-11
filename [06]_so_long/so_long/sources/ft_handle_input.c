/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:53:09 by msimic            #+#    #+#             */
/*   Updated: 2024/01/04 18:20:34 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Handles keyboard input events.
Moves the player based on the pressed keys (W, A, S, D or arrow keys).
Calls ft_player_move with the new player position and sprite direction.
If the Q key or ESC key is pressed, calls ft_close_game to close the game.
keysym: Integer representing the key code.
game: Pointer to a structure (t_game) holding game-related information.
Returns 0.
*/
int	ft_handle_input(int keysym, t_game *game)
{
	if (keysym == KEY_UP || keysym == KEY_W)
		ft_player_move(game, game->map.player.y - 1, game->map.player.x, BACK);
	if (keysym == KEY_LEFT || keysym == KEY_A)
		ft_player_move(game, game->map.player.y, game->map.player.x - 1, LEFT);
	if (keysym == KEY_RIGHT || keysym == KEY_D)
		ft_player_move(game, game->map.player.y, game->map.player.x + 1, RIGHT);
	if (keysym == KEY_DOWN || keysym == KEY_S)
		ft_player_move(game, game->map.player.y + 1, game->map.player.x, FRONT);
	if (keysym == KEY_Q || keysym == KEY_ESC)
		ft_close_game(game);
	return (0);
}

/*
Updates the player's position and the game state based on the new position.
game: Pointer to a structure (t_game) holding game-related information.
new_y: New y-coordinate for the player.
new_x: New x-coordinate for the player.
player_sprite: Direction of the player sprite (BACK, LEFT, RIGHT, FRONT).
Checks if the new position is a valid move, a victory condition, or if
the game should be closed.
Updates the player's position and map accordingly.
Renders the updated map using ft_render_map.
Increments the movement count.
If the player reaches the exit with no remaining collectibles, calls ft_victory.
Handles the case where the new position is either an empty floor or
a collectible (pizza).
*/
void	ft_player_move(t_game *game, int new_y, int new_x, int player_sprite)
{
	int	last_x;
	int	last_y;

	game->player_sprite = player_sprite;
	last_x = game->map.player.x;
	last_y = game->map.player.y;
	if (game->map.full[new_y][new_x] == MAP_EXIT && game->map.pizza == 0)
		ft_victory(game);
	else if ((game->map.full[new_y][new_x] == FLOOR)
	|| (game->map.full[new_y][new_x] == PIZZA))
	{
		game->map.full[last_y][last_x] = FLOOR;
		if (game->map.full[new_y][new_x] == PIZZA)
			game->map.pizza--;
		game->map.player.x = new_x;
		game->map.player.y = new_y;
		game->map.full[new_y][new_x] = PLAYER;
		game->movements++;
		ft_render_map(game);
	}
}
