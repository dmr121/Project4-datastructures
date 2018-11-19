// David Rozmajzl dmr121@zips.uakron.edu
#include "maze.h"

maze(int r, int c)
{
  row = r;
  col = c;
  for (int i = 0; i < r * c; ++i)
  {
    theMaze.push_back(i);
  }
}

bool neighbors(int cell, int neigh) const
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

void printMaze()
{
  return;
}
