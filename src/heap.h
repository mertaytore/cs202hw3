/*
 * heap.h
 *
 */

#ifndef HEAP_H_
#define HEAP_H_
#include <iostream>
#include <stdio.h>
#include <string>

class heap{
public:
	//const & dest
	heap();
	heap(int elementNum);
	~heap();
	//for output purposes
	int 	getComparisonsCount();
	//functions that are wanted
	void 	insert(const int a);
	int 	maximum();
	int 	popMaximum();

private:
	int 		free;
	int* 		arrayHeap;
	int 		maxElements;
	int 	comparisonNum;
};


#endif /* HEAP_H_ */
