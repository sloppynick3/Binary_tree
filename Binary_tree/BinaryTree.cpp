#include "BinaryTree.h"
#include <iostream>


BinaryTree::BinaryTree()
{
}


BinaryTree::~BinaryTree()
{
	deleteList();
	delete this;
}

void BinaryTree::insert(int data) {
	if (root == nullptr) {
		root = new Node(data);
	}
	else {
		root->insert(data);
	}
}

void BinaryTree::deleteNode(int node) {
	if (root->data == node) {
		deleteRoot();
	}
	else {
		root->deleteNode(node);
	}

}

void BinaryTree::deleteRoot() {
	//Finds the biggest value smaller than the current root value and sets it as the new root value
	Node* cursor = root->left;
	Node* previous = cursor;
	while (cursor->right != nullptr) {
		previous = cursor;
		cursor = cursor->right;
	}

	if (cursor->left != nullptr) {
		previous->right = cursor->left;
	}
	else {
		previous->right = nullptr;
	}
	cursor->left = root->left;
	cursor->right = root->right;
	delete root;
	root = cursor;
}

void BinaryTree::print() {
	if (root == nullptr) {
		std::cout << "List is empty" << std::endl;
		return;
	}

	root->printInOrder();
	std::cout << std::endl;
}

void BinaryTree::deleteList()
{
	root->deleteList();
	root = nullptr;
}

bool BinaryTree::contains(int node)
{
	return root->contains(node);
}
