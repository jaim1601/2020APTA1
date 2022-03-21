
#include "Trail.h"


Trail::Trail() {
}

Trail::Trail(Trail& other) {
   for (int i = 0; i<other.size(); ++i){
      //Position* cpyTrail = new Position(*other.positions[i]);
      this->addCopy(other.getPosition(i));
   }
}

Trail::~Trail() {
}

int Trail::size() {
   return length;
}

Position* Trail::getPosition(int i) {
   Position* out = positions[i];
   return out;
}

void Trail::addCopy(Position* t) {
   positions[length]= new Position(*t);
   ++length;
}