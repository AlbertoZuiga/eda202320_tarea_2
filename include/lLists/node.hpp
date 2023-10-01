//node.hpp

#ifndef NODE_HPP_
#define NODE_HPP_

#include "lLists/pair.hpp"

namespace llist {

class Node {
private:
	Pair* data;
	Node* ptrNext;

public:
	Node();
	Node(Pair* _data, Node* next = nullptr);
	Node(int row, int col, Node* next = nullptr);
	void setData(Pair* _data);
	void setNext(Node* _next);
	Pair* getData();
	Node* getNext();
	void print();
	virtual ~Node();
};

} // namespace llist

#endif /* NODE_HPP_ */