// maze.hpp

#ifndef MAZE_HPP_
#define MAZE_HPP_

#include <vector>
#include "lLists/pair.hpp"

namespace maze {
	typedef unsigned char uchar;

	class Maze{
	private:
		uchar**  grid;
		int width;
		int height;
		int dir[4];
		void shuffle_dir();
		void delete_maze();
		void visit(int i, int j);
	public:
		static const unsigned char WALL;
		static const unsigned char EMPTY;
		static const unsigned char SOLUTION;
		static const int NORTH;
		static const int SOUTH;
		static const int EAST;
		static const int WEST;
		Maze(int h, int  w);
		void generate_maze(int h, int w);
		void reset_maze(int h, int w);
		bool inRange(int i, int j);
		void print();
		void print(std::vector<llist::Pair> solution);
		void printSolution(int type);
		std::vector<llist::Pair> solveStack(int f1, int c1, int f2, int c2);
		std::vector<llist::Pair> solveQueue(int r1, int c1, int r2, int c2);
	};
} // namespace maze

#endif /* MAZE_HPP_ */