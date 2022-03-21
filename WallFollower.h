
#ifndef COSC_ASSIGN_ONE_WALL_FOLLOWER
#define COSC_ASSIGN_ONE_WALL_FOLLOWER

#include "Position.h"
#include "Trail.h"
#include "Types.h"

class WallFollower {
public:

   /*                                           */
   /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
   /*                                           */


   // Constructor/Destructor
   WallFollower();
   ~WallFollower();

   // Solve the maze
   void execute(Maze maze);

   // Get a DEEP COPY of the path the robot travelled
   Trail* getFullPath();

   /*                                           */
   /* YOU MAY ADD YOUR MODIFICATIONS HERE       */
   /*                                           */
   
   //Make a copy of the input maze
   void copyMaze(Maze maze);
   //Find the starting position of the robot
   void robotPosition(Maze maze);
   //Solve the maze by following the 'Right hand" algorithm
   void robotMovement(Maze maze);
   //Test to see whether robot has arrived at 'G'
   bool arrivedAtG(Maze maze);
   //Replace the input maze with the copied maze that contains the robot's journeys
   void replaceMaze(Maze maze_copy, Maze maze);
   

private:

   /*                                           */
   /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
   /*                                           */

   // Trail of positions that the robot travelled
   Trail* path;

   /*                                           */
   /* YOU MAY ADD YOUR MODIFICATIONS HERE       */
   /*                                           */
   //x-position in the maze of the robot
   int _x;
   //y-position in the maze of the robot
   int _y;
   //boolean to check whether robot has arrived at 'G'
   bool atG;
   //orientation of the robot
   Orientation _orien;
   //copy of 2d array maze
   Maze maze_copy;

   Trail* trail = new Trail();
};

#endif // COSC_ASSIGN_ONE_WALL_FOLLOWER