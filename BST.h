#include <iostream>
#include "BST.h"

using namespace std;

class BST
{
	public:
		BST();
		~BST();

		void insert(int value);
		bool contains(int value);
		bool deleteNode(int value);

		bool isEmpty();
		bool isFull();
		int getMin(); //left most
		int getMax(); //right most

		TreeNode* getSuccessor(TreeNode d); //helper function for delete method
		//print functions

	private:
		TreeNode* root;
};
