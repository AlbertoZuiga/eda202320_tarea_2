#include <iostream>
#include "maze/maze.hpp"
#include "lLists/node.hpp"
#include "lLists/queue.hpp"
#include "lLists/stack.hpp"
using namespace maze;

int main(int nargs, char** vargs){
	Maze laberinto(21,21);
	//laberinto.solveQueue(0,10,20,10);
	laberinto.solveStack(0,10,20,10);
	laberinto.print();
	return 0;
}