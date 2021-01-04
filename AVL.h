#pragma once
#include "AVLInterface.h"
#include "Node.h"

class AVL: public AVLInterface {
protected:
	Node *root;
	int difference = 0;
public:
	AVL() {root = NULL;}
	virtual ~AVL() {
		clear();
	}

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	NodeInterface * getRootNode() const;

	bool find(Node*& rooot, int value);

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool add(int data);
	bool addFunction(Node*& n, int value);
	
	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool remove(int data);
	bool removeFunction(Node*& localRoot, int value);
	void replace(Node*& oldRoot, Node *& localRoot);
	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void clear();
	void clearFunction(Node* rooot);
	int updateHeight(Node*& nodeInQuestion);
	void leftRotation(Node*& n);
	void rightRotation(Node*& n);
	void rebalance(Node*& n);
};