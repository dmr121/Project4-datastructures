// David Rozmajzl dmr121@zips.uakron.edu
#include "maze.h"
#include <iostream>

using std::cout;
using std::endl;

maze::maze(int r, int c)
{
  row = r;
  col = c;
  // Creating the first cell
  theMaze.push_back(mazeCell(false, true, false, true));
  // Creating all the in between cells
  for (int i = 1; i < (r * c) - 1; ++i)
  {
    theMaze.push_back(mazeCell());
  }
  // Creating the last cell
  theMaze.push_back(mazeCell(true, false, true, false));
}

bool maze::neighbors(int cell, int neigh) const
{
  if (cell == neigh + 1 && 0 != cell % col)
  {
    return true;
  }
  else if (cell == neigh - 1 && (col - 1) != cell % col)
  {
    return true;
  }
  else if (col == cell - neigh || col == neigh - cell)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void maze::smashWall(int cell, int neigh)
{
  if (cell == neigh + 1 && 0 != cell % col)
  {
    theMaze[cell].setLeft(false);
    theMaze[neigh].setRight(false);
  }
  else if (cell == neigh - 1 && (col - 1) != cell % col)
  {
    theMaze[neigh].setLeft(false);
    theMaze[cell].setRight(false);
  }
  else if (col == cell - neigh)
  {
    theMaze[cell].setTop(false);
    theMaze[neigh].setBot(false);
  }
  else if (col == neigh - cell)
  {
    theMaze[cell].setBot(false);
    theMaze[neigh].setTop(false);
  }
}

void maze::printMaze()
{
  // Print top row of lines
  cout << "  ";
  for (int i = 1; i < col; ++i)
  {
    cout << " _";
  }
  cout << endl;
  // Handle the printing of the first cell
  if (theMaze[0].getBot() == 1)
  {
    cout << " _";
  }
  else
  {
    cout << "  ";
  }

  // Printing the middle cells
  for (int i = 1; i < theMaze.size() - 1; ++i)
  {
    if (i % col == 0)
    {
      cout << "|";
      cout << endl;
    }
    if (theMaze[i].getLeft() == 1)
    {
      cout << "|";
    }
    else
    {
      cout << " ";
    }
    if (theMaze[i].getBot() == 1)
    {
      cout << "_";
    }
    else
    {
      cout << " ";
    }
  }

  if (theMaze[theMaze.size() - 1].getLeft() == 1)
  {
    cout << "|";
  }
  else
  {
    cout << " ";
  }
}
