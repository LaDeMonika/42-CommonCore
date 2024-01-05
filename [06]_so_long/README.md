<h1 align="center"> so_long | 42 Vienna</h1>

<p align="center">"So_long" is a project that involves creating a 2D game in C, challenging players to navigate a maze, gather items, and reach an exit. The project relies on the MinilibX library (mlx) for graphics and input management, enabling the development of an engaging and interactive gaming experience.</p>
<p align="center"><img align="center" alt="so_long" src="https://user-images.githubusercontent.com/81205527/179134510-48689e9e-f8e4-4165-be40-2e0ec8f5d60d.png"> </a></p>
<p align="center" alt="screenshot of 2D game"><img src="https://github.com/LaDeMonika/42-Vienna-CommonCore/assets/128793184/11a4724c-a818-4fb4-a6f1-bbec9eea1f8b"></p>


<h2 align="center" id="requirements"> Requirements </h2>

<p  align="center"> :warning: The project must be written in accordance with the <a href="https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf" target="_blank">Norm</a> </p>
The Norm  is a programming standard that defines a set of rules to follow when writing code at 42. It applies to all C projects within the Common Core by default, and
to any project where it's specified.
    
<h2 align="center"> How does it work? </h2>

You'll be able to play once you install the <a href="https://github.com/42Paris/minilibx-linux">MiniLibx</a> features or if you're using one of the machines at 42.

To play, first compile the project with make:

	make

run ./so_long followed by the map:
	
	./so_long assets/maps/valid/map2.ber	
	
<h3 align="center"> Maps </h3>   
You can parse any kind of map, as long as it respects the below rules:

The map must be a .ber file.

And can only contain these characters:
    
| CHAR |	OBJECT   |
| --------- | ---------- |
| 1         |   Wall   |
| C	        | Coin |
| E	        |   Exit  |
| P         |   Player  |      
| 0         |   Floor     |


The map must be rectangular and surrounded by walls '1'.

The map must contain at least one exit, one collectible, and one starting position.

Check some examples in the folder /assets/maps.
	
As in assets/maps/valid/map4.ber:

<img src="https://github.com/LaDeMonika/42-Vienna-CommonCore/assets/128793184/08db8599-8a54-4136-902e-09b452db5eab">


This .ber file generates this map:
    
    
<img src="https://github.com/LaDeMonika/42-Vienna-CommonCore/assets/128793184/59fb6e27-b6ba-4316-bd27-5bd53ac7d58f">
	
<h3 align="center"> Controls </h3>   
    
| KEY |	OBJECT   |
| --------- | ---------- |
| W or ⬆️        |    Move up   |
| A	or ⬅️        |    Move left |
| S	or ⬇️     |    Move down   |
| D or ➡️       |   Move para right|      
| Q or Esc      |   Close the game     | 
    
    
Use WASD or arrow keys to move.
	
	
After getting all the coin bags, the exit opens and you can escape downstairs.
	
You can close the game by Clicking on the red cross on the window’s frame, or pressing Q or Esc.
