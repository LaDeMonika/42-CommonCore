/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:53:44 by msimic            #+#    #+#             */
/*   Updated: 2024/01/04 18:30:13 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
This function is called when the player achieves victory in the game.
game: Pointer to a structure (t_game) holding game-related information.
Increments the number of movements and prints the current number.
Frees all allocated memory using ft_free_all_allocated_memory.
Prints a victory message in green.
Exits the program with EXIT_FAILURE status.
*/
int	ft_victory(t_game *game)
{
	ft_printf(CYAN"\n			Movements: %d\n"RESET, ++game->movements);
	ft_free_all_allocated_memory(game);
	ft_printf(GREEN"\n	      ⲯ﹍︿﹍︿﹍ 𝚢𝚎𝚎𝚎𝚢 ﹍ⲯ﹍ⲯ﹍︿﹍☼\n\n\n"RESET);
	exit (EXIT_FAILURE);
}

/*
This function is called when the game is closed without victory.
game: Pointer to a structure (t_game) holding game-related information.
Prints the number of movements made during the game.
Frees all allocated memory using ft_free_all_allocated_memory.
Prints a "CLOSED" message in grey.
Exits the program with EXIT_FAILURE status.
*/
int	ft_close_game(t_game *game)
{
	ft_printf(CYAN"Movements: %d\n"RESET, game->movements);
	ft_free_all_allocated_memory(game);
	ft_printf(GREY"CLOSED\n"RESET);
	exit (EXIT_FAILURE);
}

/*
This function is called in case of an error to display an error message and
terminate the program.
message: The error message to be displayed.
game: Pointer to a structure (t_game) holding game-related information.
Checks if the map has been allocated (map_alloc) and frees it if necessary
using ft_free_map.
Frees the game structure.
Prints an error message in red along with the provided error message.
Exits the program with EXIT_FAILURE status.
*/
int	ft_error_msg(char *message, t_game *game)
{
	if (game->map_alloc == true)
		ft_free_map(game);
	free(game);
	printf(RED"Error\n"GREY"%s\n"RESET, message);
	exit (EXIT_FAILURE);
}
