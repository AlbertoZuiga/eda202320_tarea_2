#include <iostream>
#include "maze/maze.hpp"
#include "lLists/node.hpp"
#include "lLists/queue.hpp"
#include "lLists/stack.hpp"
using namespace maze;

int main(int nargs, char** vargs){
	Maze laberinto(21,21);
	laberinto.print();

	std::vector<llist::Pair> solution_queue = laberinto.solveQueue(0,10,20,10);
	laberinto.print(solution_queue);
	laberinto.printSolution(solution_queue);
	
	std::vector<llist::Pair> solution_stack = laberinto.solveStack(0,10,20,10);
	laberinto.print(solution_stack);
	laberinto.printSolution(solution_stack);
	
	return 0;
}