
#include "Position.h"

Position::Position(int x, int y, Orientation orientation):
x(x),
y(y),
orientation(orientation)
{
   
}

Position::~Position() {
}

int Position::getX() {
   return x;
}

int Position::getY() {
   return y;
}

Orientation Position::getOrientation() {
   return orientation;
}