// David Rozmajzl dmr121@zips.uakron.edu

#include "maze.h"
#include "DisjSets.h"
#include "mazeCell.h"
#include <iostream>
#include <limits>
#include <ctime>

using std::cout;
using std::endl;

void twoRandom(int &, int &, int);
bool isConnected(int, int);

int main(){
  // Seeding the time
  srand(time(0));
  int columns = 0, rows = 0;
  cout << "Please enter the number of rows greater than 1: ";
  cin >> rows;
  // Validate integer input
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
  // Validate integer input again
  while (cin.fail() || columns <= 1)
  {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "You must enter an integer greater than 1" << endl;
    cout << "Please try again: ";
    cin >> columns;
  }
  maze myMaze(rows, columns);

  cout << "Would you like to see each interation of the maze n: ";
  char yesORno;
  cin >> yesORno;
  bool loopFlag = true;
  // Validate char input to be either y or n
  do{
    if (yesORno == 'y' || yesORno == 'n')
    {
      loopFlag = false;
    }
    else
    {
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      cout << "What was that? Type 'y' or 'n': ";
      cin >> yesORno;
    }
  } while (loopFlag);
  cout << endl;

  myMaze.printMaze();
  cout << endl << endl;
  // Initialize the disjoint set
  DisjSets mySet(myMaze.getRow() * myMaze.getCol());

  int cell1, cell2;
  twoRandom(cell1, cell2, myMaze.getRow() * myMaze.getCol());
  while (!isConnected(mySet.find(0), mySet.find((myMaze.getRow() * myMaze.getCol()) - 1)))
  {
    if (myMaze.neighbors(cell1, cell2) && !isConnected(mySet.find(cell1), mySet.find(cell2)))
    {
      mySet.unionSets(mySet.find(cell1), mySet.find(cell2));
      myMaze.smashWall(cell1, cell2);
      // Print maze if user indicated it before
      if (yesORno == 'y')
      {
        cout << "Neighbors " << cell1 << ", " << cell2 << " wall smashed";
        cout << " below" << endl << endl;
        myMaze.printMaze();
        cout << endl << endl;
      }
    }
    twoRandom(cell1, cell2, myMaze.getRow() * myMaze.getCol());
  }

  // Print end result of maze maze only if the user selected n earlier
  if (yesORno == 'n')
  {
    myMaze.printMaze();
    cout << endl << endl;
  }
  return 0;
}

//PRECONDITION: n1 and n2 are integers passed by reference
//              maxN is the maximum number that either n1 and n2 can be
//
//POSTCONDITION: Assigns a random integer between 0 and maxN to n1
//               and a different random integer between 0 and maxN to n2
void twoRandom(int & n1, int & n2, int maxN)
{
  n1 = rand() % maxN;
  // Ensures that n1 and n2 cannot be the same
  do{
    n2 = rand() % maxN;
  } while (n1 == n2);
}

//PRECONDITION: n1 is the root node of the 1st set
//              n2 is the root node of the 2nd set
//
//POSTCONDITION: Returns true if the two nodes have the same root
bool isConnected(int n1, int n2)
{
  if (n1 == n2)
  {
    return true;
  }
  else
  {
    return false;
  }
}
