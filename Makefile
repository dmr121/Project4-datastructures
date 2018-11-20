OBJS=buildMaze.o DisjSets.o maze.o


main: $(OBJS)
	g++ -o main $(OBJS)

maze.o: maze.cpp maze.h mazeCell.h
buildMaze.o: buildMaze.cpp
DisjSets.o: DisjSets.cpp DisjSets.h
