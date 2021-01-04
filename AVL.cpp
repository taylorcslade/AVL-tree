#include "Node.h"
#include "AVL.h"
using namespace std;

	NodeInterface * AVL::getRootNode() const{
		return root;
	}

	bool AVL::find(Node*& rooot, int value){
		if (rooot->data == value){
			return true;
		}

		if (value < rooot->data){
			if(rooot->leftChild == NULL){
				return false;
			}
			else {
				find(rooot->leftChild, value);
			}
		}

		else if (value > rooot->data){
			if(rooot->rightChild == NULL){
				return false;
			}
			else {
				find(rooot->rightChild, value);
			}
		}
	}

	int AVL::updateHeight(Node*& n){
		cout << "updating height of "<< n->data << endl;

		int leftheight = -1;
		if (n->leftChild != NULL)
			leftheight = n->leftChild->height;
		int rightheight = -1;
		if (n->rightChild != NULL)
			rightheight = n->rightChild->height;

		int theHeight = 1 + max(leftheight, rightheight);
		cout << "height of "<< n->data<<": "<< theHeight<< endl;

		difference = rightheight - leftheight;

		return 1 + max(leftheight, rightheight);
	}

	void AVL::rebalance(Node*& n){
		int rSideHeight = -1;
		int lSideHeight = -1;
		if (difference > 1){
			cout << n->data << " is out of balance" << endl;
			if(n->rightChild->rightChild != NULL)
				rSideHeight = n->rightChild->rightChild->height;
			if(n->rightChild->leftChild != NULL)
				lSideHeight = n->rightChild->leftChild->height;
			if (rSideHeight < lSideHeight){
				cout << "right left imbalance on " << n->data << endl;
				rightRotation(n->rightChild);
				leftRotation(n);
			}
			else {
				cout << "right right imbalance" << endl;
				leftRotation(n);
			}
		}
		else if (difference < -1){
			cout << n->data << " is out of balance" << endl;
			if(n->leftChild->leftChild != NULL)
				lSideHeight = n->leftChild->leftChild->height;
			if(n->leftChild->rightChild != NULL)
				rSideHeight = n->leftChild->rightChild->height;
			if (lSideHeight < rSideHeight){
				cout << "left right imbalance on " << n->data << endl;
				leftRotation(n->leftChild);
				rightRotation(n);
			}
			else {
				cout << "left left imbalance" << endl;
				rightRotation(n);
			}
		}
		cout << "n = " << n->data << endl;
		if (n->rightChild != NULL){
			cout << "n rc= " << n->rightChild->data << endl;
		}
		if (n->leftChild != NULL){
			cout << "n lc= " << n->leftChild->data << endl;
		}
	}

	void AVL::leftRotation(Node*& n){
		cout << "in left rotation" << endl;
		Node* newRoot = n->rightChild;
		n->rightChild = newRoot->leftChild;
		newRoot->leftChild = n;
		if (n == root)
			root = newRoot;
		n = newRoot;
		n->leftChild->height = updateHeight(n->leftChild);
		n->height = updateHeight(n);
	}

	void AVL::rightRotation(Node*& n){
		cout << "in rightRotation" << endl;
		Node* newRoot = n->leftChild;
		n->leftChild = newRoot->rightChild;
		newRoot->rightChild = n;
		if (n == root)
			root = newRoot;
		n = newRoot;
		n->rightChild->height = updateHeight(n->rightChild);
		n->height = updateHeight(n);
	}

	bool AVL::add(int data){
		if (root == NULL){
			root = new Node(data);
			return true;
		}
		else if (find(root, data) == false){
			return addFunction(root, data);
		}
		else {
			return false;
		}
	}

	bool AVL::addFunction(Node*& rooot, int value){
		cout << "add(" << rooot << ", " << value << ")" << endl;
		if(rooot == NULL) {
    	Node* ptr = new Node(value);
    	rooot = ptr;
    	return true;
  	}
		bool answer = false;
		if (value < rooot->data){
			bool isadded = addFunction(rooot->leftChild, value);
			if (isadded){
				rooot->height=updateHeight(rooot);
				rebalance(rooot);
				answer = true;
			}
			return answer;
		}
		else if (value > rooot->data){
			bool isadded = addFunction(rooot->rightChild, value);
			if (isadded){
				rooot->height = updateHeight(rooot);
				rebalance(rooot);
				answer = true;
			}
			return answer;
		}
	}

	bool AVL::remove(int data){
		if (find(root, data) == true){
			cout << endl << "vemoving " << data << endl;
			bool isremoved = removeFunction(root, data);
			if ((isremoved) && (root != NULL)){
				root->height = updateHeight(root);
				rebalance(root);
			}
			return isremoved;
		}
		else
			return false;
	}

	bool AVL::removeFunction(Node*& localRoot, int value){
		cout << "remove function (" << localRoot->data << ", " << value << ")" << endl;
		if(localRoot->height == 0){
			localRoot = NULL;
		}
		else if(value < localRoot->data){
			removeFunction(localRoot->leftChild, value);
			localRoot->height = updateHeight(localRoot);
			rebalance(localRoot);
		}
		else if(value > localRoot->data){
			removeFunction(localRoot->rightChild, value);
			localRoot->height = updateHeight(localRoot);
			rebalance(localRoot);
		}
		else {
			Node *oldRoot = localRoot;
			if (localRoot->leftChild == NULL){
				localRoot = oldRoot->rightChild;
				localRoot->height = updateHeight(localRoot);
				rebalance(localRoot);
				delete oldRoot;
			}
			else if (localRoot->rightChild == NULL){
				localRoot = oldRoot->leftChild;
				localRoot->height = updateHeight(localRoot);
				rebalance(localRoot);
				delete oldRoot;
			}
			else {
				replace(oldRoot, localRoot->leftChild);
				localRoot->height = updateHeight(localRoot);
				rebalance(localRoot);
			}
		}
		return true;
	}

	void AVL::replace(Node*& oldRoot, Node *& localRoot){
		cout << "replace(" << oldRoot->data << ", " << localRoot->data << ")" << endl;

		if (localRoot -> rightChild != NULL){
			replace(oldRoot, localRoot->rightChild);
		}
		else {
			oldRoot->data = localRoot->data;
			removeFunction(oldRoot->leftChild, localRoot->data);
		}
	}

	void AVL::clear(){
		cout << "in clear" << endl;
		if (root == NULL){
			cout << "cleared" << endl;
			return;
		}
		else{
			clearFunction(root);
			root = NULL;
		}
	}

	void AVL::clearFunction(Node* rooot){
		if(rooot->rightChild != NULL){
			clearFunction(rooot->rightChild);
		}
		if(rooot->leftChild != NULL){
			clearFunction(rooot->leftChild);
		}
		delete rooot;
	}