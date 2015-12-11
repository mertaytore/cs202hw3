/*
 * heap.cpp
 *
 *  Created on: 11 Kas 2015
 *      Author: User
 */

#include "heap.h"
#include <iostream>
#include <math.h>
#include "heap.h"
#include <stdio.h>

/*void inorder( node *root){
	if (root.left != NULL)
		inorder(node.left);
	if (root.value1 != NULL)
		cout << root.value1 << endl;
	if (root.middle != NULL)
		inorder(node.middle);
	if (root.value2!= NULL)
		cout << node.value2 << endl;
	if (root.right != NULL)
		inorder(node.right);
}*/

heap::heap(){
	comparisonNum = 0;
	arrayHeap = new int[200]; //choosing 200 to be default

	maxElements = 200;
	free = 0;

}

heap::heap(int elementNum){
	maxElements = elementNum;
	//having set the given num of max element to the maxElements
	arrayHeap = new int[maxElements];

	free = 0;
	comparisonNum = 0;
}

heap::~heap(){
	//deleting the array
	delete arrayHeap;
}

int heap::getComparisonsCount(){
	return comparisonNum;
}

int heap::maximum(){
	//could be something other than -1
	if ( free == 0)
		return -1;
	return arrayHeap[0];
}

int heap::popMaximum(){
	//could be something other than -1
	if(free == 0)
		return -1;
	int maxKey;
	maxKey = maximum();

	int right, parent, child;
	free = free - 1;
	//rebuilding starting from here to pop
	arrayHeap[0] = arrayHeap[free];
	parent = 0;
	child = 2 * parent + 1;
	while( child < free){
		right = child + 1;
		if (arrayHeap[right] > arrayHeap[child] && right < free)
			child = right;
		if (arrayHeap[child] > arrayHeap[parent])
			std::swap(arrayHeap[child], arrayHeap[parent]);
		comparisonNum = comparisonNum + 2;
		parent = child;
		child = 2 * parent + 1;
	}
	return maxKey;
}

void heap::insert(const int a){
	if( free == maxElements)
		return;
	int parent;
	int child;
	//adding a to the array of the heap
	arrayHeap[free] = a;

	parent = (free - 1)/2;
	child = free;

	//this actually is the heapRebuild() function
	while(arrayHeap[parent] < arrayHeap[child] && parent >= 0){
		std::swap( arrayHeap[parent], arrayHeap[child]);

		//going upwards in the heap
		child = parent;
		parent = (parent-1)/2;
		comparisonNum = comparisonNum + 1;
	}
	free = free + 1;
}
