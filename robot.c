#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "robot.h"
#include "background.h"
#include "robotDraw.h"
#include "map.h"

int canMoveForward(robot *robot, map *map)
{
    int sign = robot->dir / abs(robot->dir);
    bool vertical = robot->dir == NORTH || robot->dir == SOUTH;
    char nextPos = map->map[vertical ? robot->pos.y + sign : robot->pos.y][!vertical ? robot->pos.x + sign : robot->pos.x];
    return nextPos != WALL && nextPos != OBSTACLE;
}

int atMarker(robot *robot, map *map)
{
    return map->map[robot->pos.y][robot->pos.x] == MARKER;
}

int isAtHome(robot *robot, map *map)
{
    return map->map[robot->pos.y][robot->pos.x] == HOME;
}

void forward(robot *robot, map *map)
{
    if (!canMoveForward(robot, map))
        return;
    int sign = robot->dir / abs(robot->dir);
    bool vertical = robot->dir == NORTH || robot->dir == SOUTH;
    vertical ? (robot->pos.y += sign) : (robot->pos.x += sign);
    drawRobot(robot, map);
}

void left(robot *robot)
{
    robot->dir = (robot->dir + DIRECTION_CHANGE) > EAST ? NORTH : (robot->dir + DIRECTION_CHANGE);
}

void right(robot *robot)
{
    robot->dir = (robot->dir - DIRECTION_CHANGE) < NORTH ? EAST : (robot->dir - DIRECTION_CHANGE);
}

void pickUpMarker(robot *robot, map *map)
{
    if (!atMarker(robot, map))
        return;
    robot->numMarkersCaried++;
    map->map[robot->pos.y][robot->pos.x] = EMPTY;
    drawBackground(map);
}

void dropMarker(robot *robot, map *map)
{
    if (robot->numMarkersCaried < 1 || atMarker(robot, map))
        return;
    robot->numMarkersCaried--;
    drawBackground(map);
    drawRobot(robot, map);
}

int markerCount(robot *robot)
{
    return robot->numMarkersCaried;
}
