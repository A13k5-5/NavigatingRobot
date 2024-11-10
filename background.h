#pragma once
#include "main.h"

#define WALL_COLOUR red
#define MARKER_COLOUR gray
#define OBSTACLE_COLOUR black
#define HOME_COLOUR blue
#define GRID_COLOUR black

int coordsToGrid(map *map, int x);
int coordsToGrid(map *map, int x);
int gridToCoords(map *map, int x);
void drawBackground(map *map);