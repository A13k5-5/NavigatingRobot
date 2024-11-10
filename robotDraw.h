#pragma once
#include "main.h"
#include "robot.h"

#define ROBOT_COLOUR green
#define ROBOT_SLEEP_TIME 100
typedef struct
{
    int x[3];
    int y[3];
} shapeCoords;

void drawRobot(robot *robot, map *map);