# ft_printf

## Description

This project is about coding a simple 2D game to get familiar with the mlx library and UI in general.     
The files have to compile with -Wall -Werror -Wextra and to be free of memory leaks. The written code must follow certain rules, which are specified in a standard of the school 42.


### Allowed functions

```
open, close, read, write,
malloc, free, perror, strerror, exit
```
```
all functions of the math library
all functions of the MiniLibX library
```
```
self coded ft_printf
```

## Mandatory Part
### About the game
##### Map


The executable ``so_long`` will receive a map as the only argument, and this map will have a ``.ber`` filetype.

The map must follow these rules:
- Only ``P`` *(player)*, ``1`` *(wall)*, ``0`` *(empty)*, ``C`` *(collectible)*, and ``E`` *(exit)* will be accepted characters in our map
- The map must be rectangular, i.e. all rows must have the same length
- There must be at least one exit, one player, and one collectible on the map
- The map must be closed, i.e. surrounded by walls

If any of these checks fail, the game must end with ``Error\n`` followed by a custom message.

The goal is for the player to collect all the collectibles on the map before going to an exit in the least possible number of steps.

##### Controls
You can use ``WASD`` to move and close it with ``Esc``. You move one tile at a time.  After picking up all collectibles, the exits open and you may leave to see how many moves you’ve used to solve the map.


## Skills

* Graphics
* Imperative programming


## Getting Started

### Clone the repository
```shell
git clone git@github.com:wolumen/so_long.git
cd so_long
```

### Debian/Ubuntu

**Installing the dependencies**

```
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

### Compiling
#### Execute the game
The make file has the following rules:

| Rule | Function |
| - | - |
| ``make`` | Compiles so_long executable. |
| ``make clean`` | Deletes all object files. |
| ``make fclean`` | Deletes the object files and the executable. |
| ``make re`` | makes ``fclean`` and ``make`` again. |
| ``make map[1-3]`` | Doeas ``make`` and runs the game with the selected map. E.g. make map1. |
| `` make play`` | Allows you to play some of the maps I designed in a defined succession. To play the next map just press ``esc``. |

To play you can use some of the makefile rules, or execute the file so_long if it's been generated, passing the map you want to play as parameter.  ``./so_long mapFileToPlay.ber``, you can choose between 11 maps. For example:
```
 ./so_long maps/map8.ber
 ```
 
 <p align="center">
![Screenshot 2022-05-10_110753](https://user-images.githubusercontent.com/78870401/167614701-b2a4b58e-96d9-4172-9646-d1c5fc3c4445.png)
</p>
