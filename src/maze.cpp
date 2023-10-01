#include "maze/maze.hpp"
#include "lLists/stack.hpp"
#include "lLists/queue.hpp"
#include "lLists/pair.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

namespace maze{

const unsigned char Maze::WALL  = '@';
const unsigned char Maze::EMPTY = '-';
const unsigned char Maze::SOLUTION = 'x';
const int Maze::NORTH= 0;
const int Maze::SOUTH= 1;
const int Maze::EAST= 2;
const int Maze::WEST= 3;

Maze::Maze(int h, int w):
		height(h),
		width(w),
		grid(nullptr){
	dir[0] = NORTH;
	dir[1] = SOUTH;
	dir[2] = EAST;
	dir[3] = WEST;
	std::srand(time(0));
	generate_maze(h, w);

}

void Maze::reset_maze(int h, int w){
	delete_maze();
	height = h;
	width= w;
	grid = new uchar*[height];
	for (int i = 0; i < height; i++){
		grid[i] = new uchar[width];
		for (int j = 0; j < width; j++){
			grid[i][j] = 1;
		}
	}
}

void Maze::generate_maze(int h, int w){
	reset_maze(h, w);
	visit(0,0);
}

void Maze::delete_maze(){
	if (grid != nullptr){
		for (int i = 0; i < height; i++){
			delete[] grid[i];
		}
		delete[] grid;
	}
}

void Maze::shuffle_dir(){
	for (int i = 0; i < 4; i++){
		int r = std::rand() & 3;
		int aux = dir[r];
		dir[r] = dir[i];
		dir[i] = aux;
	 }
}

bool Maze::inRange(int i, int j){
	return ((i >= 0) && (i< height) && (j >= 0) && (j< width));
}

void Maze::visit(int i, int j){
	int dx  = 0;
	int dy = 0;
	int i_next = 0;
	int j_next = 0;
	grid[i][j] = 0;
	shuffle_dir();
	for(int k = 0; k <  4; k++){
		if (dir[k] == NORTH){
			dy = -1;
			dx = 0;
		}
		else if (dir[k] == SOUTH){
			dy = 1;
			dx = 0;
		}
		else if (dir[k] == EAST){
			dy = 0;
			dx = 1;
		}
		else if (dir[k] == WEST){
			dy = 0;
			dx = -1;
		}
		i_next = i + (dy<<1);
		j_next = j + (dx<<1);
		if (inRange(i_next, j_next) && grid[i_next][j_next] == 1){
			grid[i_next - dy][j_next - dx] = 0;
			visit(i_next, j_next);

		}
	}
}

void Maze::print(){
	char LIMIT = '=';
	std::cout << " Maze ( "<< height << " x " << width << " ) " << std::endl;
	std::cout << " ";
	for (int j = 0; j < width; j++){
		std::cout << LIMIT;
	}
	std::cout << " ";
	std::cout << std::endl;
	for (int i = 0; i < height; i++){
		std::cout << "|";
		for (int j = 0; j < width; j++){
			if (grid[i][j] == 1) {
				std::cout << WALL;
			}
			else {
				std::cout << EMPTY;
			}
		}
		std::cout << "|";
		std::cout << std::endl;
	}
	std::cout << " ";
	for (int j = 0; j < width; j++){
		std::cout << LIMIT;
	}
	std::cout << " ";
	std::cout << std::endl;
}

void Maze::print(std::vector<llist::Pair> solution){
	std::cout << "Se recorrieron " << solution.size() << " nodos para llegar desde el nodo inicial al nodo final" << std::endl;
	for (int i = 0; i < solution.size(); i++){
		solution[i].print();
		if (i==solution.size()-1){
			std::cout << std::endl;
		}
		else {
			std::cout << "->";
		}
	}
}

void Maze::printSolution(int type){
	// type 0 corresponde a stack, type 1 corresponde a queue
	if (type == 0){
		std::cout << "Solución Stack" << std::endl;
	}
	else if (type == 1){
		std::cout << "Solución Queue" << std::endl;
	}
	else {
		std::cout << "El tipo ingresado no es valido (0 -> Stack, 1 -> Queue)" << std::endl;
		return;
	}
	type += 2;
	
	char LIMIT = '=';
	std::cout << " Maze ( "<< height << " x " << width << " ) " << std::endl;
	std::cout << " ";
	for (int j = 0; j < width; j++){
		std::cout << LIMIT;
	}
	std::cout << " ";
	std::cout << std::endl;
	for (int i = 0; i < height; i++){
		std::cout << "|";
		for (int j = 0; j < width; j++){
			if (grid[i][j]== 0){
				std::cout << EMPTY;
			}
			else if (grid[i][j] == 1) {
				std::cout << WALL;
			}
			else if ((grid[i][j]== type) || (grid[i][j]== 4)){
				std::cout << SOLUTION;
			}
			else {
				std::cout << grid[i][j];
			}
		}
		std::cout << "|";
		std::cout << std::endl;
	}
	std::cout << " ";
	for (int j = 0; j < width; j++){
		std::cout << LIMIT;
	}
	std::cout << " ";
	std::cout << std::endl;
}

std::vector<llist::Pair> Maze::solveStack(int r1, int c1, int r2, int c2) {
	std::vector<llist::Pair> solution;
    if (grid[r1][c1] == 1 || grid[r2][c2] == 1) {
        std::cout << "La posición inicial o final es una pared. No se puede encontrar una solución." << std::endl;
        return solution;
    }

    llist::Stack stack;
	std::vector<llist::CellPair> solutionPath;
    std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));

    stack.push(r1, c1);
    visited[r1][c1] = true;

    while (!stack.isEmpty()) {
        llist::Pair* current = stack.top()->getData();
		stack.pop();
        int row = current->getRow();
        int col = current->getCol();
        if (row == r2 && col == c2) {
			if (grid[r1][c1] == 3){
				grid[r1][c1] = 4;
			}
			else {
				grid[r1][c1] = 2;
			};
			if (grid[r2][c2] == 3){
				grid[r2][c2] = 4;
			}
			else {
				grid[r2][c2] = 2;
			};

			while(!solutionPath.empty()) {
				if (current == solutionPath.back().curr){
					solution.insert(solution.begin(), *current);
					if (grid[row][col] == 3){
						grid[row][col] = 4;
					}
					else {
						grid[row][col] = 2;
					};
					current = solutionPath.back().prev;
				}
				row = current->getRow();
				col = current->getCol();
				solutionPath.pop_back();
			};
			solution.insert(solution.begin(), llist::Pair (r1,c1));
			return solution;
        }

		shuffle_dir();
        int drow = 0;
        int dcol = 0;
		int next_row = 0;
		int next_col = 0;

        for (int k = 0; k < 4; k++) {
            if (dir[k] == NORTH){
				drow = -1;
				dcol = 0;
			}
			else if (dir[k] == SOUTH){
				drow = 1;
				dcol = 0;
			}
			else if (dir[k] == EAST){
				drow = 0;
				dcol = 1;
			}
			else if (dir[k] == WEST){
				drow = 0;
				dcol = -1;
			}

			next_row = row + (drow);
			next_col = col + (dcol);

            if (inRange(next_row, next_col) && grid[next_row][next_col] != 1 && !visited[next_row][next_col]) {
                stack.push(next_row, next_col);
                visited[next_row][next_col] = true;
				solutionPath.push_back(llist::CellPair(current, stack.top()->getData()));
            }
        }
    }
	if (grid[r1][c1]!=2){
		std::cout << "El laberinto no tiene solucion" << std::endl;
	}
	return solution;
}

std::vector<llist::Pair> Maze::solveQueue(int r1, int c1, int r2, int c2) {
	std::vector<llist::Pair> solution;
    if (grid[r1][c1] == 1 || grid[r2][c2] == 1) {
        std::cout << "La posición inicial o final es una pared. No se puede encontrar una solución." << std::endl;
        return solution;
    }

    llist::Queue queue;
    std::vector<llist::CellPair> solutionPath;
    std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));

    queue.push(r1, c1);
    visited[r1][c1] = true;

    while (!queue.isEmpty()) {
        llist::Pair* current = queue.top()->getData();
        queue.pop();
        int row = current->getRow();
        int col = current->getCol();

        if (row == r2 && col == c2) {
			if (grid[r1][c1] == 2){
				grid[r1][c1] = 4;
			}
			else {
				grid[r1][c1] = 3;
			};
			if (grid[r2][c2] == 2){
				grid[r2][c2] = 4;
			}
			else {
				grid[r2][c2] = 3;
			};
            while (!solutionPath.empty()) {
				if (current == solutionPath.back().curr){
					solution.insert(solution.begin(),*current);
					if (grid[row][col] == 2){
						grid[row][col] = 4;
					}
					else {
						grid[row][col] = 3;
					};
					current = solutionPath.back().prev;
				}
                row = current->getRow();
				col = current->getCol();
				solutionPath.pop_back();
            }
			solution.insert(solution.begin(), llist::Pair (r1,c1));
			return solution;
        }

        shuffle_dir();
		int drow = 0;
		int dcol = 0;
		int next_row = 0;
		int next_col = 0;

        for (int k = 0; k < 4; k++) {
            if (dir[k] == NORTH) {
                drow = -1;
                dcol = 0;
            } else if (dir[k] == SOUTH) {
                drow = 1;
                dcol = 0;
            } else if (dir[k] == EAST) {
                drow = 0;
                dcol = 1;
            } else if (dir[k] == WEST) {
                drow = 0;
                dcol = -1;
            }

            next_row = row + drow;
            next_col = col + dcol;

            if (inRange(next_row, next_col) && grid[next_row][next_col] != 1 && !visited[next_row][next_col]) {
                llist::Node* temp = new llist::Node(next_row, next_col);
				queue.push(temp);
                visited[next_row][next_col] = true;
                solutionPath.push_back(llist::CellPair(current, temp->getData()));
            }
        }
    }
	if (grid[r1][c1] != 3){
		std::cout << "El laberinto no tiene solucion" << std::endl;
	}
	return solution;
}

}