#pragma once

#define SQUARE_SIZE 50
#define OFFSET 50
#define MIN_HEIGHT_AND_WIDTH 10
#define MAX_HEIGHT_AND_WIDTH 16

typedef struct
{
    // Width and height in px
    int width;
    int height;
} canvas;
typedef struct
{
    int x;
    int y;
} point;
typedef struct
{
    int width;
    int height;
    canvas canvas;
    char **map;
} map;
