/*
 * pair.cpp
 */

#include "lLists/pair.hpp"
#include <iostream>

namespace llist {


Pair::Pair(): row(-1), col(-1) {
}

Pair::Pair(int row, int col): row(row), col(col) {

}

void Pair::setRow(int _row){
	row = _row;
}

void Pair::setCol(int _col){
	col = _col;
}

int Pair::getRow(){
	return row;
}

int Pair::getCol(){
	return col;
}

void Pair::print(){
	std::cout << "("<< row << "," << col << ")" ;
}

Pair::~Pair() {

}

} 