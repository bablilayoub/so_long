# So Long

## Summary
This project is a very small 2D game, aimed at making you work with textures, sprites, and some other basic gameplay elements.

## Common Instructions
- Your project must be written in C.
- Your project must be written in accordance with the Norm.
- Functions should not quit unexpectedly (segmentation fault, bus error, double free, etc.), apart from undefined behaviors.
- All heap allocated memory space must be properly freed when necessary. No leaks will be tolerated.
- If the subject requires it, you must submit a Makefile that will compile your source files to the required output with the flags -Wall, -Wextra, and -Werror, using cc. Your Makefile must not relink.
- Your Makefile must at least contain the rules $(NAME), all, clean, fclean, and re.
- To turn in bonuses, include a rule bonus in your Makefile.
- If your project allows you to use your libft, copy its sources and its associated Makefile into a libft folder with its associated Makefile. Your project’s Makefile must compile the library using its Makefile, then compile the project.
- Create test programs for your project. They won’t have to be submitted, but they will give you a chance to easily test your work and your peers’ work. These tests will be useful during your defense.
- Submit your work to your assigned git repository. Only the work in the git repository will be graded. If Deepthought is assigned to grade your work, it will be done after your peer-evaluations.

## Mandatory Part
- **Program name:** so_long
- **Turn in files:** Makefile, *.h, *.c, maps, textures
- **Makefile rules:** NAME, all, clean, fclean, re
- **Arguments:** A map in the format *.ber
- **External functions allowed:**
  - open, close, read, write, malloc, free, perror, strerror, exit
  - All functions of the math library (-lm compiler option, man man 3 math)
  - All functions of the MiniLibX
  - ft_printf and any equivalent YOU coded
- **Libft authorized:** Yes

## Game
- The player's goal is to collect every collectible present on the map and then escape by choosing the shortest possible route.
- Use the W, A, S, and D keys to move the main character.
- The player should be able to move in these 4 directions: up, down, left, right.
- The player should not be able to move into walls.
- Display the current number of movements at every move in the shell.
- Use a 2D view (top-down or profile).
- The game doesn’t have to be real time.
- Although the given examples show a dolphin theme, you can create the world you want. If you prefer, you can use ZQSD or the arrow keys on your keyboard to move your main character.

## Graphic Management
- Your program has to display the image in a window.
- The management of your window must remain smooth (changing to another window, minimizing, and so forth).
- Pressing ESC must close the window and quit the program in a clean way.
- Clicking on the cross on the window’s frame must close the window and quit the program in a clean way.
- The use of the images of the MiniLibX is mandatory.

## Map
- The map has to be constructed with 3 components: walls, collectibles, and free space.
- The map can be composed of only these 5 characters:
  - 0 for an empty space,
  - 1 for a wall,
  - C for a collectible,
  - E for a map exit,
  - P for the player’s starting position.
- The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.
- If the map contains duplicate characters (exit/start), display an error message.
- The map must be rectangular.
- The map must be closed/surrounded by walls. If it’s not, the program must return an error.
- You have to check if there’s a valid path in the map.
- You must be able to parse any kind of map, as long as it respects the above rules.

## Bonus Part
Usually, you would be encouraged to develop your own original extra features. However, there will be much more interesting graphic projects later. They are waiting for you!! Don’t lose too much time on this assignment!
You are allowed to use other functions to complete the bonus part as long as their use is justified during your evaluation. Be smart!
You will get extra points if you:
- Make the player lose when they touch an enemy patrol.
- Add some sprite animation.
- Display the movement count directly on screen instead of writing it in the shell.
You can add files/folders based on bonuses as needed.
The bonus part will only be assessed if the mandatory part is PERFECT. Perfect means the mandatory part has been integrally done and works without malfunctioning. If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all.
