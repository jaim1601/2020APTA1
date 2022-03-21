
#include <iostream>
#include <string>

#include "Types.h"
#include "WallFollower.h"

// Read a maze from standard input.
void readMazeStdin(Maze maze);

// Print out a Maze to standard output.
void printMazeStdout(Maze maze, Trail* solution);

/*
For my implementation, I begin by making a copy of the input maze. This copy is used as the maze which I modify to
be printed out. In order to solve the maze, I begin by calling a method which finds the initial starting position
of the robot. Once this has been located, another method is called in which a while loop is used to solve the maze 
until the robot has arrived at 'G'. Once the robot has arrived at 'G', the loop terminates and the maze copy I 
created is copied back onto the original maze 2d array. This is then printed out for the user to see the route the
robot takes. Along with the solved maze, the coordinates of the robot's position along its journey is also printed
*/
int main(int argc, char** argv) {
    // Load Maze from stdin
    Maze maze;
    readMazeStdin(maze);
   
    // Solve using WallFollower
    // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 2
    WallFollower* follower = new WallFollower();
    Trail* fullPath = nullptr;
    follower->execute(maze);
    fullPath = follower->getFullPath();

    // Print Maze to stdout
    printMazeStdout(maze, fullPath);

    delete follower;

    return EXIT_SUCCESS;
}

void readMazeStdin(Maze maze) {
    // ASSUME THE MAZE IS A FIXED SIZE (20X20).
    for(int row=0; row<MAZE_DIM; ++row){
        for(int column=0; column<MAZE_DIM; ++column){
            std::cin >> maze[row][column];
        }
    }
}

void printMazeStdout(Maze maze, Trail* solution) {
    for(int row=0; row<MAZE_DIM; ++row){
      for (int column=0; column<MAZE_DIM; ++column){
        std::cout << maze[row][column];
      }
    std::cout << std::endl;
    }
    int length = solution->size();
    for (int i = 0; i < length; ++i){
        Position* getRoute = solution->getPosition(i);
        std::cout << getRoute->getX() << ",";
        std::cout << getRoute->getY() << ",";
        std::cout << getRoute->getOrientation() << std::endl;
    }
}