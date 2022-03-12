# So_long   :video_game:

The project so_long is one of the projects in teh second circle of the 42cursus.
It aims to create a small 2d game using the minilibx. Here's a link to install it : [install minilibx](https://achedeuzot.me/2014/12/20/installer-la-minilibx/)

### Objectives
  * Create a program that takes as argument a file (ending with '.ber') containing a map and displays a window representing each character with an image
  * Make the player move and take the coins, then exit
  * Do some sprite animations (for the bonus part)
  * Make the ennemies move (for the bonus part)
  * Make a small counter for the movements in te screen (for the bonus part)


### Example of a valid map
  11111111111
  1CN00C00101
  1000N0100C1
  1P0C00C0NE1
  11111111111
  
  * 1 for the walls on the sides. And for the box in the middle.
  * 0 for an empty space
  * C for coins
  * N for ennemies
  * P for a player
  * E for an exit (you can exit only after taking all the coins)

### Final grade
  125/100
  
### How to use
  * Type make, it will compile the files using the necessary framworks, then execute so_long program like this : ./so_long 'maphere.ber'
  * You can use the maps folder 'maps', or create your own map and test it.
  * Note that the program will generate an error if the file doesn't exist, doesn't have permissions, the map doesn't contain all characters, the map isn't rectangular ....
