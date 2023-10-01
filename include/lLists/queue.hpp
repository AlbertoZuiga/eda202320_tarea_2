/*
 * queue.hpp
 *
 */

#ifndef QUEUE_HPP_
#define QUEUE_HPP_

#include "lLists/node.hpp"

namespace llist {

class Queue {
private:
	Node* head;
	Node* tail;
public:
	Queue();
	void push(int row, int col);
	void push(Node* node);
	void pop();
	Node* top();
	bool isEmpty();
	void clear();
	virtual ~Queue();
};

} /* namespace eda */

#endif /* QUEUE_HPP_ */
