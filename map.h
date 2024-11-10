#pragma once

#define EMPTY 'o'
#define WALL 'w'
#define MARKER 'm'
#define HOME 'h'
#define OBSTACLE 'b'
#define VISITED 'v'

#define MIN_OBSTALCE_LEN 1
#define MAX_OBSTALCE_LEN 3

#define INVALID_POINT \
    (point) { -1, -1 }

void freeMap(char **map, int width, int height);
char **generateMap(int width, int height);
char **copyMap(char **map, int width, int height);
void resetVisited(char **map, int height, int width);
point *neighbourPoints(point p);