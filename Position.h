
#ifndef COSC_ASSIGN_ONE_Position
#define COSC_ASSIGN_ONE_Position

#include "Types.h"

class Position {
public:

   /*                                           */
   /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
   /*                                           */

   // Constructor/Desctructor
   Position(int x, int y, Orientation orientation);
   ~Position();

   // x-co-ordinate of the particle
   int getX();

   // y-co-ordinate of the particle
   int getY();

   // Orientation the robot is facing
   Orientation getOrientation();

private:

   /*                                           */
   /* DO NOT MOFIFY THESE VARIABLES             */
   /*                                           */
   int x;
   int y;
   Orientation orientation;

};

#endif // COSC_ASSIGN_ONE_Position