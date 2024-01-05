/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:50:11 by msimic            #+#    #+#             */
/*   Updated: 2024/01/04 18:22:37 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libraries/Libft/libft.h"
//# include <stdbool.h> zamjeniti t_bool sa ovim mozda

//**PIXELS
# define IMG_HEIGHT			32
# define IMG_WIDTH			32

//**MAP_DEF
# define WALL				'1'
# define FLOOR 				'0'
# define PIZZA  			'C'
# define PLAYER				'P'
# define MAP_EXIT 		 	'E'

//MOVES
# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100

//**MOVES
# define KEY_UP  			65362
# define KEY_LEFT  			65361
# define KEY_RIGHT 			65363
# define KEY_DOWN  			65364

//**EXIT_GAME
# define KEY_Q				113
# define KEY_ESC  			65307

//**SIDES
# define FRONT				1
# define LEFT				2
# define RIGHT				3
# define BACK				4

//**ASSETS_DEF
# define WALL_XPM			"assets/sprites/wall.xpm"
# define FLOOR_XPM			"assets/sprites/floor.xpm"
# define COINS_XPM			"assets/sprites/coin-bag.xpm"
# define PLAYER_FRONT_XPM	"assets/sprites/player/front.xpm"
# define PLAYER_LEFT_XPM	"assets/sprites/player/left.xpm"
# define PLAYER_RIGHT_XPM	"assets/sprites/player/right.xpm"
# define PLAYER_BACK_XPM	"assets/sprites/player/back.xpm"
# define OPEN_EXIT_XPM		"assets/sprites/open-exit.xpm"
# define EXIT_CLOSED_XPM	"assets/sprites/exit-closed.xpm"

//**COLOR_DEF
# define GREEN				"\033[0;32m"
# define RED 				"\033[1;31m"
# define GREY 				"\033[0;90m"
# define CYAN				"\033[1;96m"
# define RESET 				"\033[0m"

//***STRUCTS***
typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_position
{
	int	x;
	int	y;
}	t_positon;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_map
{
	char		**full;
	int			rows;
	int			columns;
	int			pizza;
	int			exit;
	int			players;
	t_positon	player;
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			movements;
	int			player_sprite;
	t_map		map;
	t_bool		map_alloc;
	t_image		wall;
	t_image		floor;
	t_image		pizza;
	t_image		open_exit;
	t_image		exit_closed;
	t_image		player_front;
	t_image		player_left;
	t_image		player_right;
	t_image		player_back;
}	t_game;

//***FUNC***
//ft_check_map.c
void	ft_check_map(t_game *game);
void	ft_check_rows(t_game *game);
void	ft_check_columns(t_game *game);
void	ft_count_map_parameters(t_game *game);
void	ft_verify_map_parameters(t_game *game);
//ft_close_game.c
int		ft_victory(t_game *game);
int		ft_close_game(t_game *game);
int		ft_error_msg(char *message, t_game *game);
//ft_free_memory.c
void	ft_free_all_allocated_memory(t_game *game);
void	ft_destroy_images(t_game *game);
void	ft_free_map(t_game *game);
//ft_handle_input.c
int		ft_handle_input(int keysym, t_game *game);
void	ft_player_move(t_game *game, int x, int y, int player_sprite);
//ft_init_game.c
void	ft_init_vars(t_game *game);
void	ft_init_mlx(t_game *game);
void	ft_init_sprites(t_game *game);
t_image	ft_new_sprite(void *mlx, char *path, t_game *game);
//ft_init_map.c
void	ft_check_command_line_arguments(int argc, char **argv, t_game *game);
void	ft_init_map(t_game *game, char *argv);
void	ft_check_for_empty_line(char *map, t_game *game);
//ft_render_map.c
int		ft_render_map(t_game *game);
void	ft_identify_sprite(t_game *game, int x, int y);
void	ft_render_player(t_game *game, int x, int y);
void	ft_render_sprite(t_game *game, t_image sprite, int column, int line);
void	ft_print_movements(t_game *game);
//ft_utils.c
char	*ft_strappend(char **s1, const char *s2);
//check where it is ! ! !
size_t	ft_strlen_line(const char *str);

#endif