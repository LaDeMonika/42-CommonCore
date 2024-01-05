/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:53:25 by msimic            #+#    #+#             */
/*   Updated: 2024/01/04 18:20:17 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
This function is responsible for freeing all dynamically allocated
memory used in the game.
Calls two sub-functions (ft_destroy_images and ft_free_map) to handle
specific memory deallocation.
Destroys the game window and display using MiniLibX functions.
Frees the MiniLibX pointer and the game structure itself.
game: Pointer to a structure (t_game) holding game-related information.
*/
void	ft_free_all_allocated_memory(t_game *game)
{
	ft_destroy_images(game);
	ft_free_map(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
}

/*
Destroys images (sprites) used in the game.
Calls MiniLibX mlx_destroy_image for each image.
game: Pointer to a structure (t_game) holding game-related information.
*/
void	ft_destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->floor.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->pizza.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_front.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_left.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_right.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_back.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit_closed.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->open_exit.xpm_ptr);
}

/*
Frees the dynamically allocated memory for the game map.
Iterates through each row of the map and frees the memory.
Frees the array of row pointers.
game: Pointer to a structure (t_game) holding game-related information.
*/
void	ft_free_map(t_game *game)
{
	int	string;

	string = 0;
	while (string < game->map.rows)
		free(game->map.full[string++]);
	free(game->map.full);
}
