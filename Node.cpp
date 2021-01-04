#include <iostream>
#include "Node.h"

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	int Node::getData() const
  {
		//cout << "getData:" << data << endl;
    return data;
  }

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	NodeInterface * Node::getLeftChild() const
  {
		//cout << "getLeftChild: "<< leftChild << endl;
    return leftChild;
  }

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	NodeInterface * Node::getRightChild() const
  {
		//cout << "getRightChild: "<< rightChild << endl;
    return rightChild;
  }

	int Node::getHeight() {
		// cout << "getHeight: " << height << endl;
		return height;
	}