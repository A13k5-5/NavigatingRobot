#define _USE_MATH_DEFINES
#include <math.h>
#include <stdbool.h>
#include "robotDraw.h"
#include "background.h"
#include "main.h"
#include "robot.h"
#include "graphics.h"
#include "control.h"

double convertDirToAngle(enum dirs dir)
{
    switch (dir)
    {
    case NORTH:
        return 0;
    case EAST:
        return M_PI_2;
    case SOUTH:
        return M_PI;
    case WEST:
        return 3 * M_PI_2;
    }
}

point squareCentre(robot *robot, map *map)
{
    point centre = {gridToCoords(map, robot->pos.x) + SQUARE_SIZE / 2, gridToCoords(map, robot->pos.y) + SQUARE_SIZE / 2};
    return centre;
}

shapeCoords getNorthCoords(robot *robot, map *map, point centre)
{
    shapeCoords northCoords;
    northCoords.x[0] = centre.x - SQUARE_SIZE / 2;
    northCoords.x[1] = centre.x + SQUARE_SIZE / 2;
    northCoords.x[2] = centre.x;
    northCoords.y[0] = centre.y + SQUARE_SIZE / 2;
    northCoords.y[1] = centre.y + SQUARE_SIZE / 2;
    northCoords.y[2] = centre.y - SQUARE_SIZE / 2;
    return northCoords;
}

void rotateShapeCoords(shapeCoords *coords, point center, double angle)
{
    for (int i = 0; i < 3; i++)
    {
        int x = coords->x[i] - center.x;
        int y = coords->y[i] - center.y;
        coords->x[i] = center.x + (x * cos(angle) - y * sin(angle));
        coords->y[i] = center.y + (x * sin(angle) + y * cos(angle));
    }
}

shapeCoords getShapeCoords(robot *robot, map *map)
{
    point centre = squareCentre(robot, map);
    shapeCoords finalCoords = getNorthCoords(robot, map, centre);
    rotateShapeCoords(&finalCoords, centre, convertDirToAngle(robot->dir));
    return finalCoords;
}

void drawRobot(robot *robot, map *map)
{
    foreground();
    clear();
    shapeCoords coords = getShapeCoords(robot, map);
    setColour(ROBOT_COLOUR);
    fillPolygon(3, coords.x, coords.y);
    setColour(GRID_COLOUR);
    sleep(ROBOT_SLEEP_TIME);
}