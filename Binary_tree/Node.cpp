#include "Node.h"
#include <iostream>

Node::Node(int data) {
	this->data = data;
}

void Node::insert(int data) {
	if (data <= this->data) {
		if (left == nullptr) {
			left = new Node(data);
		}
		else {
			left->insert(data);
		}
	}
	else {
		if (right == nullptr) {
			right = new Node(data);
		}
		else {
			right->insert(data);
		}
	}
}

bool Node::contains(int data) {
	if (this->data == data) {
		return true;
	}

	if (data < this->data) {
		if (left == nullptr) {
			return false;
		}
		else {
			return left->contains(data);
		}
	}
	else {
		if (right == nullptr) {
			return false;
		}
		else {
			return right->contains(data);
		}
	}
}

void Node::printInOrder() {
	if (left != nullptr) {
		left->printInOrder();
	}

	std::cout << data << " ";

	if (right != nullptr) {
		right->printInOrder();
	}
}

void Node::deleteNode(int node)
{
	Node* previous;
	Node* cursor;
	if (left->data == node) {
		previous = left;
		for (cursor = left->right; cursor->left != nullptr; cursor = cursor->left) {
			previous = cursor;
		}
		left = cursor;
		previous->left = nullptr;
	}
	else if (right->data == node) {
		previous = right;
		for (cursor = right->right; cursor->left != nullptr; cursor = cursor->left) {
			previous = cursor;
		}
		right = cursor;
		previous->left = nullptr;
	}
	else {
		if (node < data) {
			if (left == nullptr) {
				std::cout << "AAAAA" << std::endl;
			}
			else {
				left->deleteNode(node);
			}
		}
		else {
			if (right == nullptr) {
				std::cout << "BBBB" << std::endl;
			}
			else {
				right->deleteNode(node);
			}
		}
	}
}

void Node::deleteList()
{
	if (left != nullptr) {
		left->deleteList();
	}
	std::cout << "Deleted: " << data << std::endl;
	if (right != nullptr) {
		right->deleteList();
	}

	delete this;
}
