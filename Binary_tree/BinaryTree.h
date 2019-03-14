#pragma once
#include "Node.h"
class BinaryTree
{
private:
	Node* root = nullptr;
public:
	BinaryTree();
	~BinaryTree();
	void insert(int data);
	void deleteNode(int node);
	void deleteRoot();
	void print();
	void deleteList();
	bool contains(int node);
};

