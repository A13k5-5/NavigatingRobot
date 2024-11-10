#pragma once
#include "main.h"

// Everytime there is a change in direction, either 2 is added or substracted
// Thanks so this north and south, and west and east have opposite signs
enum dirs
{
    NORTH = -3,
    WEST = -1,
    SOUTH = 1,
    EAST = 3
};

#define DIRECTION_CHANGE 2

typedef struct
{
    point pos;
    enum dirs dir;
    int numMarkersCaried;
    bool isFinished;
} robot;

void drawRobot(robot *robot, map *map);
void forward(robot *robot, map *map);
void left(robot *robot);
void right(robot *robot);
int atMarker(robot *robot, map *map);
int canMoveForward(robot *robot, map *map);
void pickUpMarker(robot *robot, map *map);
int isAtHome(robot *robot, map *map);
void dropMarker(robot *robot, map *map);
int markerCount(robot *robot);