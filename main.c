#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "main.h"
#include "background.h"
#include "robot.h"
#include "random.h"
#include "graphics.h"
#include "map.h"
#include "control.h"

canvas initializeCanvas(int width, int height)
{
    return (canvas){width * SQUARE_SIZE + 2 * OFFSET, height * SQUARE_SIZE + 2 * OFFSET};
}

map initializeMap(int width, int height)
{
    canvas canvas = initializeCanvas(width, height);
    map map = {
        width,
        height,
        canvas,
        generateMap(width, height)};
    return map;
}

robot initializeRobot(map *map)
{
    // initializeMap left all points that can access all markers and home as VISITED
    point startingPos = randomEmptyPointOnMap(map->map, VISITED, map->width, map->height);
    resetVisited(map->map, map->height, map->width);
    robot robot = {startingPos, randomDir(), 0, false};
    return robot;
}

void exploreMap(map *map, robot *robot, char lookingFor)
{
    char **mapCopy = copyMap(map->map, map->width, map->height);
    movingEverywhereRecurAbs(map, mapCopy, robot->pos, robot, lookingFor);
    freeMap(mapCopy, map->width, map->height);
}

void run()
{
    srand(time(NULL));
    const int width = randomNumber(MIN_HEIGHT_AND_WIDTH, MAX_HEIGHT_AND_WIDTH);
    const int height = randomNumber(MIN_HEIGHT_AND_WIDTH, MAX_HEIGHT_AND_WIDTH);

    map map = initializeMap(width, height);
    robot robot = initializeRobot(&map);

    drawBackground(&map);

    exploreMap(&map, &robot, MARKER);
    exploreMap(&map, &robot, HOME);

    freeMap(map.map, map.width, map.height);
}

int main(void)
{
    run();
    return 0;
}
