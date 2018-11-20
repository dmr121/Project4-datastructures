// David Rozmajzl dmr121@zips.uakron.edu

#include "maze.h"
#include "DisjSets.h"
#include "mazeCell.h"
#include <iostream>

using namespace std;

int main(){
  maze cool(3, 4);
  cool.maze::printMaze();
  return 0;
}
