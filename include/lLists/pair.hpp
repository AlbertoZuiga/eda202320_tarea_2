// pair.hpp

#ifndef PAIR_HPP_
#define PAIR_HPP_

namespace llist {

class Pair {
private:
	int row;
    int col;
public:
	Pair();
	Pair(int _row, int _col);
	void setRow(int _row);
    void setCol(int _col);
	int getRow();
	int getCol();
	void print();
	virtual ~Pair();

};

struct CellPair {
	Pair* prev;
	Pair* curr;

	CellPair(Pair* prev, Pair* curr) : prev(prev), curr(curr) {}
};

} // namespace llist

#endif /* PAIR_HPP_ */