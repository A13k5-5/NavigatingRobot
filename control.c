#include <stdbool.h>
#include <stdlib.h>
#include "main.h"
#include "robot.h"
#include "background.h"
#include "random.h"
#include "map.h"
#include "control.h"

void turnToDir(robot *robot, enum dirs newDir)
{
    while (robot->dir != newDir)
    {
        right(robot);
    }
}

void moveTo(robot *robot, point newPos, map *map)
{
    if (robot->isFinished)
        return;

    int dx = newPos.x - robot->pos.x;
    int dy = newPos.y - robot->pos.y;

    if (!dx && !dy)
        return;

    enum dirs newDir = dx ? (dx < 0 ? WEST : EAST) : 0;
    newDir = dy ? (dy < 0 ? NORTH : SOUTH) : newDir;
    turnToDir(robot, newDir);
    forward(robot, map);
}

void setVisited(char **mapCopy, point visitedPoint)
{
    mapCopy[visitedPoint.y][visitedPoint.x] = VISITED;
}

void end(robot *robot)
{
    robot->isFinished = true;
}

void getHome(robot *robot, map *map)
{
    while (markerCount(robot))
    {
        dropMarker(robot, map);
    }
    end(robot);
}

void checkPos(robot *robot, map *map, char lookingFor)
{
    if (lookingFor == MARKER && atMarker(robot, map))
    {
        pickUpMarker(robot, map);
    }
    else if (lookingFor == HOME && isAtHome(robot, map))
    {
        getHome(robot, map);
    }
}

void movingEverywhereRecurAbs(map *map, char **mapCopy, point curPos, robot *robot, char lookingFor)
{
    if (mapCopy[curPos.y][curPos.x] == WALL || mapCopy[curPos.y][curPos.x] == OBSTACLE || mapCopy[curPos.y][curPos.x] == VISITED || robot->isFinished)
    {
        return;
    }
    setVisited(mapCopy, curPos);
    moveTo(robot, curPos, map);
    checkPos(robot, map, lookingFor);

    point *neighbouringPoints = neighbourPoints(robot->pos);
    for (int i = 0; i < 4; i++)
    {
        movingEverywhereRecurAbs(map, mapCopy, neighbouringPoints[i], robot, lookingFor);
        // As the recursion unwinds, move back
        moveTo(robot, curPos, map);
    }
    free(neighbouringPoints);
}