
#include "WallFollower.h"

WallFollower::WallFollower() {
}

WallFollower::~WallFollower() {
   delete trail;
}

void WallFollower::execute(Maze maze) {
   WallFollower::copyMaze(maze);
   WallFollower::robotPosition(maze);
   WallFollower::robotMovement(maze);
   WallFollower::replaceMaze(maze_copy, maze);
}

Trail* WallFollower::getFullPath() {
   Trail* cpyTrail = new Trail(*trail);
   return cpyTrail;
}

void WallFollower::copyMaze(Maze maze){
   for(_y=0; _y<MAZE_DIM; ++_y){
      for (_x=0; _x<MAZE_DIM; ++_x){
         maze_copy[_y][_x] = maze[_y][_x];
      }
   }
}

void WallFollower::robotPosition(Maze maze){
   for(_y=0; _y<MAZE_DIM; ++_y){
      for(_x=0; _x<MAZE_DIM; ++_x){
         if (maze[_y][_x] == '>') {
            _orien = ORIEN_EAST;
            Position* position = new Position(_x, _y, _orien);           
            trail->addCopy(position);
         }
         else if (maze[_y][_x] == '^') {
            _orien = ORIEN_NORTH;
            Position* position = new Position(_x, _y, _orien);
            trail->addCopy(position);
         }
         else if (maze[_y][_x] == '<') {
            _orien = ORIEN_WEST;
            Position* position = new Position(_x, _y, _orien);
            trail->addCopy(position);
         }
         else if (maze[_y][_x] == 'v') {
            _orien = ORIEN_SOUTH;
            Position* position = new Position(_x, _y, _orien);
            trail->addCopy(position);
         }    
      }
   }
}

void WallFollower::robotMovement(Maze maze) {
   int size = (trail->size())-1;
   
   Position* getPos = trail->getPosition(size);
   
   _x = getPos->getX();
   _y = getPos->getY();
   _orien = getPos->getOrientation();
   
   while(atG == false) {
      int size = (trail->size())-1;
      getPos = trail->getPosition(size);      
      _x = getPos->getX();
      _y = getPos->getY();
      _orien = getPos->getOrientation();
      if (_orien == ORIEN_NORTH && maze[_y][_x+1] == '=') { 
         if (maze[_y-1][_x] == '.') {
            maze_copy[_y-1][_x] = '^';
            Position* newPos = new Position(_x, _y-1, ORIEN_NORTH);
            trail->addCopy(newPos);
         }
         else if (maze[_y-1][_x] == '=') {
            maze_copy[_y][_x] = '<';
            Position* newPos = new Position(_x, _y, ORIEN_WEST);
            trail->addCopy(newPos);
         }
         else {
            atG = WallFollower::arrivedAtG(maze);
         }
      }
      else if (_orien == ORIEN_EAST && maze[_y+1][_x] == '=') { 
         if (maze[_y][_x+1] == '.') {
            maze_copy[_y][_x+1] = '>';
            Position* newPos = new Position(_x+1, _y, ORIEN_EAST); 
            trail->addCopy(newPos);
         }
         else if (maze[_y][_x+1] == '=') {
            maze_copy[_y][_x] = '^';
            Position* newPos = new Position(_x, _y, ORIEN_NORTH);
            trail->addCopy(newPos);
         }
         else {
            atG = WallFollower::arrivedAtG(maze);
         }
      } 
      else if (_orien == ORIEN_SOUTH && maze[_y][_x-1] == '=') { 
         if (maze[_y+1][_x] == '.') {
            maze_copy[_y+1][_x] = 'v';
            Position* newPos = new Position(_x, _y+1, ORIEN_SOUTH);
            trail->addCopy(newPos);
         }
         else if (maze[_y+1][_x] == '=') {
            maze_copy[_y][_x] = '>';
            Position* newPos = new Position(_x, _y, ORIEN_EAST);
            trail->addCopy(newPos);
         }
         else {
            atG = WallFollower::arrivedAtG(maze);
         }
      }
      else if (_orien == ORIEN_WEST && maze[_y-1][_x] == '=') { 
         if (maze[_y][_x-1] == '.') {
            maze_copy[_y][_x-1] = '<';
            Position* newPos = new Position(_x-1, _y, ORIEN_WEST); 
            trail->addCopy(newPos);
         }
         else if (maze[_y][_x-1] == '=') {
            maze_copy[_y][_x] = 'v';
            Position* newPos = new Position(_x, _y, ORIEN_SOUTH);
            trail->addCopy(newPos);
         }
         else {
            atG = WallFollower::arrivedAtG(maze);
         }
      } 
      else if (_orien == ORIEN_NORTH && maze[_y][_x+1] == '.') { 
         maze_copy[_y][_x] = '>';
         Position* newPos = new Position(_x, _y, ORIEN_EAST);
         trail->addCopy(newPos);
         maze_copy[_y][_x+1] = '>';
         newPos = new Position(_x+1, _y, ORIEN_EAST);
         trail->addCopy(newPos);
      }
      else if (_orien == ORIEN_EAST && maze[_y+1][_x] == '.') { 
         maze_copy[_y][_x] = 'v';
         Position* newPos = new Position(_x, _y, ORIEN_SOUTH);
         trail->addCopy(newPos);
         maze_copy[_y+1][_x] = 'v';
         newPos = new Position(_x, _y+1, ORIEN_SOUTH);
         trail->addCopy(newPos);
      }
      else if (_orien == ORIEN_SOUTH && maze[_y][_x-1] == '.') { 
         maze_copy[_y][_x] = '<';
         Position* newPos = new Position(_x, _y, ORIEN_WEST);
         trail->addCopy(newPos);
         maze_copy[_y][_x-1] = '<';
         newPos = new Position(_x-1, _y, ORIEN_WEST);
         trail->addCopy(newPos);
      }
      else if (_orien == ORIEN_WEST && maze[_y-1][_x] == '.') { 
         maze_copy[_y][_x] = '^';
         Position* newPos = new Position(_x, _y, ORIEN_NORTH);
         trail->addCopy(newPos);
         maze_copy[_y-1][_x] = '^';
         newPos = new Position(_x, _y-1, ORIEN_NORTH);
         trail->addCopy(newPos);
      }
   }
}

bool WallFollower::arrivedAtG(Maze maze) {
   if (maze[_y-1][_x] == 'G') {
      atG = true;
   }
   else if (maze[_y][_x+1] == 'G') {
      atG = true;
   }
   else if (maze[_y+1][_x] == 'G') {
      atG = true;
   }
   else if (maze[_y][_x-1] == 'G') {
      atG = true;
   }
   else {
      atG = false;   
   }
   return atG;   
}

void WallFollower::replaceMaze(Maze maze_copy, Maze maze){
   for(_y=0; _y<MAZE_DIM; ++_y){
      for (_x=0; _x<MAZE_DIM; ++_x){
         maze[_y][_x] = maze_copy[_y][_x];
      }
   }
}