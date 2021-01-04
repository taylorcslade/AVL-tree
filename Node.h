#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "NodeInterface.h"

class Node :
	public NodeInterface
{

public:
	Node * leftChild;
	Node * rightChild;
	int data;
	int height = 0;
	Node(int value) {
		data = value;
		leftChild = NULL;
		rightChild = NULL;
		height = 0;
		//cout << "height of " << data << ": " << height << endl;
	}
	~Node() {}


	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	int getData() const;
		/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	NodeInterface * getLeftChild() const;

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	NodeInterface * getRightChild() const;

	int getHeight();

};
#endif