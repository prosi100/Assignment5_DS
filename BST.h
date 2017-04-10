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

		void insert(T theValue);
		bool contains(T someValue);
		//bool deleteNode(int value);

		bool isEmpty();
		TreeNode<T>* getMax(); //right most
		TreeNode<T>* getMin(); //left most

		//TreeNode* getSuccessor(TreeNode d); //helper function for delete method
		void printInOrder(TreeNode<T>* n);
		TreeNode<T>* getRoot();

	private:
		TreeNode<T>* root;
};

template <typename T>
BST<T>::BST()
{
	root = NULL;
}

template <typename T>
BST<T>::~BST()
{

}

template <typename T>
bool BST<T>::isEmpty()
{
	return root==NULL;
}

template <typename T>
TreeNode<T>* BST<T>::getMax()
{
	TreeNode<T>* current = root;
	if (root==NULL)
	{
		return NULL;
	}

	while(current->right!=NULL)
	{
		current = current->right;
	}

	return current; 
}

template <typename T>
TreeNode<T>* BST<T>::getMin()
{
	TreeNode<T>* current = root;
	if (root==NULL)
	{
		return NULL;
	}
	while (current->left!=NULL)
	{
		current = current->left;
	}
	return current;
}

template <typename T>
void BST<T>::insert(T theValue)//like a failed search. Could also make recursive.
{
	TreeNode<T>* node = new TreeNode<T>(theValue);	

	if (root==NULL)//empty check
	{
		root = node;
	}

	else
	{
		TreeNode<T>* current = root; //start at the root
		TreeNode<T>* parent; //empty node for now, but will be there so that we can set our pointers accordingly
		while(true)//add break point
		{
			parent = current;

			if (theValue < current->value)//here key is value; go left
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
bool BST<T>::contains(T someValue)
{		
	if (root==NULL)
	{
		return false;
	}

	else
	{
		TreeNode<T>* current = root;//start at the root
		while(current->value!=someValue)
		{
			if(someValue<current->value)//go left
			{
				current = current->left;
			}
			else
			{
				current = current->right;
			}

			if(current==NULL)
			{
				return false;
			}
		}
	}
	return true;
}

template <typename T>
void BST<T>::printInOrder(TreeNode<T>* n)
{
	if (n!=NULL)
	{
		printInOrder(n->left);
		cout<<n->value<<endl;
		printInOrder(n->right);
	}
}

template <typename T>
TreeNode<T>* BST<T>::getRoot()
{
	return root;
}