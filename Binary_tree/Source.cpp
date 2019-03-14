#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main() {
	BinaryTree* tree = new BinaryTree();

	tree->print();
	tree->insert(5);
	tree->insert(2);
	tree->insert(10);
	tree->insert(14);
	tree->insert(4);
	tree->insert(15);
	tree->insert(24);
	tree->insert(3);
	tree->insert(1);

	tree->print();

	cout <<"Contains: " << tree->contains(14) << endl;
	tree->print();

	tree->deleteNode(5);
	tree->print();


	tree->deleteList();
	tree->print();

	std::cin.get();


	return 0;
}