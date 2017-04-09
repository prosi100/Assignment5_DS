#include <iostream>
#include <string>
#include "TreeNode.h"

using namespace std;

template <typename T>
class BST
{
	public:
		BST();
		~BST();

		void insert(int theKey, T theValue);
		//bool contains(int value);
		//bool deleteNode(int value);

		bool isEmpty();
		//bool isFull();
		//int getMin(); //left most
		//int getMax(); //right most

		//TreeNode* getSuccessor(TreeNode d); //helper function for delete method
		void printInOrder();
		TreeNode getRoot();

	private:
		TreeNode* root;
};

template <typename T>
BST::BST()
{
	root = NULL;
}

template <typename T>
BST::~BST()
{

}

template <typename T>
bool BST::isEmpty()
{
	return root==NULL;
}

template <typename T>
void BST::insert(int key, T value)//like a failed search. Could also make recursive.
{
	TreeNode* node = new TreeNode(theKey, theValue);	

	if (root==NULL)//empty check
	{
		root = node;
	}

	else
	{
		TreeNode* current = root; //start at the root
		TreeNode* parent; //empty node for now, but will be there so that we can set our pointers accordingly
		while(true)//add break point
		{
			parent = current;

			if (value < current->key)//here key is value; go left
			{
				current = current->left;
				if (current == NULL)//found our position
				{
					parent->left = node;
					break;
				}
			}
			else//go right
			{
				current = current->right;
				if (current == NULL)//found our position
				{
					parent->right = node;
					break;
				}
			}
		}
	}
}

template <typename T>
void BST::printInOrder(TreeNode n)
{
	if (n!=null)
	{
		printInOrder(n->left);
		cout<<n->data<<endl;
		printInOrder(n->right);
	}
}

template <typename T>
TreeNode BST::getRoot()
{
	return root;
}