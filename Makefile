TARGETS = Test_AVL_Search_Tree_Numbers avl
CC = g++
CCFLAGS = -std=c++11 -g
avl: main.cpp AVLInterface.h NodeInterface.h AVL.h AVL.cpp Node.h Node.cpp
	$(CC) $(CCFLAGS) -o avl main.cpp AVL.cpp Node.cpp
