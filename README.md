# CS-Sprint

## Prequisites

To compile CS-Sprint requires SDL2-dev and SDL2-image-dev; they can be installed by running:
```
$ sudo apt-get install libsdl2-dev libsdl2-image-dev sqlite3
```

# Usage
## Building

The included [`Makefile`](/Makefile) will automatically compile the game.
Simply call:
```
$ make
```
to create the game executable.

## Using

From the root of the source tree, run:
```
$ ./main.o
```
# Todo
These are things that we need have planned to do:
  * [X] Baseline graphics engine $
  * [X] World generation $
    * [X] Tile based system $
  * [x] Collision Testing $
    * [ ] Sector based testing $
  * [x] Loading in a map $
    * [X] Having a map to load in $
  * [ ] Database handling $
    * [ ] Questions database
    * [ ] High score database $
  * [X] Camera scrolling $
  * [X] Player $
    * [X] Input $
    * [X] Movement $
  * [x] Enemy $
    * [x] Pathfinding $
    * [x] Movement $
  * [ ] Menu
    * [ ] Main
    * [ ] Pause
  * [ ] HUD
  * [ ] Exam question "combat system" $

$ These things are **mission critical**.
