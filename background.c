#include <stdio.h>
#include <stdbool.h>
#include "background.h"
#include "main.h"
#include "graphics.h"
#include "map.h"
#include "control.h"

int coordsToGrid(map *map, int x)
{
    return (x - OFFSET) / SQUARE_SIZE;
}

int gridToCoords(map *map, int x)
{
    return x * SQUARE_SIZE + OFFSET;
}

colour squareColour(char square)
{
    switch (square)
    {
    case WALL:
        return WALL_COLOUR;
    case OBSTACLE:
        return OBSTACLE_COLOUR;
    case HOME:
        return HOME_COLOUR;
    case MARKER:
        return MARKER_COLOUR;
    default:
        return GRID_COLOUR;
    }
}

void drawGridSquares(map *map, int x, int y)
{
    drawRect(gridToCoords(map, x), gridToCoords(map, y), SQUARE_SIZE, SQUARE_SIZE);
    colour col = squareColour(map->map[y][x]);
    setColour(col);
    if (map->map[y][x] != EMPTY)
    {
        fillRect(gridToCoords(map, x), gridToCoords(map, y), SQUARE_SIZE, SQUARE_SIZE);
    }
    setColour(GRID_COLOUR);
    drawRect(gridToCoords(map, x), gridToCoords(map, y), SQUARE_SIZE, SQUARE_SIZE);
}

void drawBackground(map *map)
{
    setWindowSize(map->canvas.width, map->canvas.height);
    background();
    clear();
    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
            drawGridSquares(map, x, y);
        }
    }
}