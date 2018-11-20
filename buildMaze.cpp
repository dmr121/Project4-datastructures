// David Rozmajzl dmr121@zips.uakron.edu

#include "maze.h"
#include "DisjSets.h"
#include "mazeCell.h"
#include <iostream>
#include <limits>

using std::cout;
using std::endl;

int main(){
  int columns = 0, rows = 0;
  cout << "Please enter the number of rows greater than 1: ";
  cin >> rows;
  while (cin.fail() || rows <= 1)
  {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "You must enter an integer greater than 1" << endl;
    cout << "Please try again: ";
    cin >> rows;
  }

  cout << "Please enter the number of columns greater than 1: ";
  cin >> columns;
  while (cin.fail() || columns <= 1)
  {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "You must enter an integer greater than 1" << endl;
    cout << "Please try again: ";
    cin >> columns;
  }
  maze myMaze(rows, columns);
  myMaze.maze::printMaze();
  cout << endl;
  return 0;
}
