# So_long   :video_game:

<img width="2242" alt="sc" src="https://user-images.githubusercontent.com/96997041/158020541-efc9072c-5c8f-4704-82ec-d61e915e2618.png">

The project so_long is one of the projects in the second circle of the 42cursus.  
It aims to create a small 2d game using the minilibx. Here's a link to install it : [install minilibx](https://achedeuzot.me/2014/12/20/installer-la-minilibx/). 
Normally mandatory and bonus parts are separeted but I assembled them here. 

### Objectives
  * Create a program that takes as argument a file (ending with '.ber') containing a map and displays a window representing each character with an image
  * Make the player move and take the coins, then exit
  * Do some sprite animations (for the bonus part)
  * Make the ennemies move (for the bonus part)
  * Make a small counter for the movements in the screen (for the bonus part)


### Example of a valid map
 <img width="99" alt="Capture d’écran 2022-03-12 à 14 59 37" src="https://user-images.githubusercontent.com/96997041/158020946-239ee081-1efa-4b29-a30f-2dffd6931d89.png">

  * 1 for the walls on the sides. And for boxes in the middle.
  * 0 for an empty space
  * C for coins
  * N for ennemies
  * P for a player
  * E for an exit (you can exit only after taking all the coins)
  
### How to use
  * Type make, it will compile the files using the necessary framworks, then execute so_long program like this : ./so_long 'maphere.ber'
  * You can use the maps folder 'maps', or create your own map and test it.
  * Note that the program will generate an error if the file doesn't exist, doesn't have permissions, the map doesn't contain all characters, the map isn't rectangular ....
