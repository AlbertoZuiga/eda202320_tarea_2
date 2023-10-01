/*
 * nodo.cpp
 */

#include "lLists/node.hpp"
#include "lLists/pair.hpp"
#include <iostream>

namespace llist {


Node::Node(): data(), ptrNext(nullptr) {
}

Node::Node(Pair* val, Node* next): data(val), ptrNext(next) {
}

Node::Node(int row, int col, Node* next) : data(new Pair(row, col)), ptrNext(next) { // Nueva sobrecarga
}

void Node::setData(Pair* _data){
	data = _data;
}

void Node::setNext(Node* next){
	ptrNext = next;
}

Pair* Node::getData(){
	return data;
}
Node* Node::getNext(){
	return ptrNext;
}

void Node::print(){
	data->print();
}

Node::~Node() {

}

} 