Robot Navigation Simulation

#Overview#
This program creates a randomly shaped arena with randomly positioned obstacles. 
It then picks a home tile and generates markers so that they are accessible from the home tile. 
A robot is then spawned on a tile that can access all the markers and the home tile. 
It goes around the arena, avoids obstacles and walls, collects all the markers, and brings them home.

#Files and Structure#
- main.c: Entry point of the program. Initializes the map and robot, and starts the exploration process.
- main.h: Header file containing definitions and structures used across the project.
- background.c: Handles drawing the background grid and its elements.
- background.h: Header file for background.c.
- robot.c: Contains the logic for robot movements and interactions with the map.
- robot.h: Header file for robot.c.
- robotDraw.c: Handles the drawing of the robot on the map.
- robotDraw.h: Header file for robotDraw.c.
- control.c: Contains functions for controlling the robot's movements and exploration logic.
- control.h: Header file for control.c.
- random.c: Utility functions for generating random numbers and points.
- random.h: Header file for random.c.
- map.c: Functions for generating and manipulating the map.
- map.h: Header file for map.c.

#How to Run#
1. Compile the project using gcc.
"gcc background.c control.c graphics.c main.c map.c random.c robot.c robotDraw.c -o robot -lm"
2. Run the executable to start the simulation.
"./robot | java -jar drawapp-4.0.jar"
3. The robot will explore the map, pick up markers, and return home.

