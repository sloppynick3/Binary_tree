#pragma once

class Node {
public:
	Node* left = nullptr;
	Node* right = nullptr;
	int data;
	
	Node(int data);
	void insert(int data);
	bool contains(int data);
	void printInOrder();
	void deleteNode(int node);
	void deleteList();
};