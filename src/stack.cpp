/*
 * stack.cpp
 */

#include "lLists/stack.hpp"
#include <iostream>

namespace llist {

Stack::Stack():head(nullptr) {
	// TODO Auto-generated constructor stub

}

void Stack::push(int col, int row){
	Node* node = new Node(col,row);
	push(node);
}

void Stack::push(Node* node){
	node->setNext(head);
	head = node;
}

void Stack::pop(){
	if (!isEmpty()){
		Node* ptr = head;
		head = head->getNext();
		delete ptr;
	}
}

Node* Stack::top(){
	return head;
}

bool Stack::isEmpty(){
	return (head == nullptr);
}

void Stack::clear(){
	while (!isEmpty()){
		pop();
	}
}

Stack::~Stack() {
	std::cout<<"destructor Stack"<<std::endl;
	clear();
}

} 