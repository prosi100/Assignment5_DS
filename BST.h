#include <iostream>
#include <string>
#include "TreeNode.h"
#include <stdexcept>

using namespace std;

template <typename T>
class BST
{
	public:
		BST();
		~BST();

		void insert(T theValue);
		bool contains(T someValue);
		bool deleteNode(TreeNode<T> someNode);
		void insertDataAtNode(T newData, T oldLocation);

		bool isEmpty();
		TreeNode<T>* getMax(); //right most
		TreeNode<T>* getMin(); //left most
		T getNode(T someValue);//get the entire value at a node

		TreeNode<T>* getSuccessor(TreeNode<T> d); //helper function for delete method
		void printInOrder(TreeNode<T>* n);
		TreeNode<T>* getRoot();
		void write(const std::string& file_name, BST<T> data);
		void read(const std::string& file_name, BST<T> data); 

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
T BST<T>::getNode(T someValue)
{
	if (root==NULL)
	{
		throw std::invalid_argument("This value is not in the tree");
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
				throw std::invalid_argument("This value is not in the tree");
			}
		}
		return current->value;
	}
}

template <typename T>
void BST<T>::insertDataAtNode(T newData, T oldLocation)
{
	if (root==NULL)
	{
		throw std::invalid_argument("This value is not in the tree");
	}

	else
	{
		TreeNode<T>* current = root;//start at the root
		while(current->value!=oldLocation)
		{
			if(oldLocation<current->value)//go left
			{
				current = current->left;
			}
			else
			{
				current = current->right;
			}

			if(current==NULL)
			{
				throw std::invalid_argument("This value is not in the tree");
			}
		}
		current->value = newData;
	}
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

template <typename T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> d)//pass in node we're trying to delete
{
	TreeNode<T>* sp = &d;///successor's parent
	TreeNode<T>* successor = &d;//will be one right, all the way left
	TreeNode<T>* current = d.right;

	while(current!=NULL)	
	{
		sp = successor;
		successor = current;
		current = current->left;
	}

	if(successor!=d.right)//if it isn't immediately to the right
	{
		sp->left = successor->right;
		successor->right = d.right;
	}

	return successor;
}

template <typename T>
bool BST<T>::deleteNode(TreeNode<T> someNode)//could return something else
{
	if (root==NULL)//empty tree
	{
		return false;
	}

	TreeNode<T> *current = root;//always start at root
	TreeNode<T> *parent = NULL;
	bool isLeft = true;

	while(current->value!=someNode.value)
	{
		parent = current;
		if(someNode.value<current->value)
		{
			isLeft = true;
			current = current->left;
		}
		else
		{
			isLeft = false;
			current = current->right;
		}

		if(current==NULL)
		{
			cout<<"Value not found"<<endl;
			return false;
		}

	}
	//yay we found what needs to be deleted.

	if(current->left == NULL && current->right == NULL)//no children, leaf node
	{
		if(current == root)
		{
			root = NULL;
		}

		else if(isLeft==true)
		{
			parent->left = NULL;//deleted the node in question
		}
		else
		{
			parent->right = NULL;//deleted the node in question
		}
	}

	else if(current->right==NULL)//has one child (the left child)
	{
		if(current==root)
		{
			root = current->left;
		}
		else if(isLeft == true)
		{
			parent->left = current->left;
		}
		else
		{
			parent->right = current->left;
		}
	}

	else if (current->left ==NULL)//has one child (the right child)
	{
		if(current==root)
		{
			root = current->right;
		}
		else if (isLeft==true)
		{
			parent->left = current->right;
		}
		else
		{
			parent->right = current->right;
		}
	}

	else//two children!!!
	{
		TreeNode<T>* successor = getSuccessor(*current);

		if(current==root)	
		{
			root = successor;
		}
		else if (isLeft)//checks if it is the left of the immediate parent
		{
			parent->left = successor;	
		}
		else
		{
			parent->right = successor;
		}
		successor->left = current->left;
	}
	current->left =NULL;
	current->right=NULL;

	return true;

}
template <typename T>
TreeNode<T>* BST<T>::getRandomNode(TreeNode<T>* someNode)//pass in root 
{
	int random = rand()%size;
	cout<<"Random Number: "<<random<<endl;
	TreeNode<T>* temp = someNode;
	someNode = getRandomNode(random, temp, 0);
	//cout<<"10"<<endl;
	return someNode;
}

template <typename T>
TreeNode<T>* BST<T>::getRandomNode(int random, TreeNode<T>* temp, int count)
{	
	if(temp!=NULL&&count!=random)
	{
		++count;
		TreeNode<T>* temp2 = NULL;
		if(temp->left!=NULL)//you can go left
		{
			temp = getRandomNode(random, temp->left, count);
		}
		else//you can't go left
		{
			temp = getRandomNode(random, temp->right, count);
		}
		return temp;

		/*++count;
		int pathRan = rand()%2;		
		TreeNode<T>* temp2 = NULL;
		if (pathRan==0)//go left
		{					
			if (temp2==NULL)//if you can't go left, try right
			{
				temp2 = getRandomNode(random, temp->right, count);
			}
			temp2 = getRandomNode(random, temp->left, count);
		}
		else
		{		
			if(temp2 ==NULL)
			{
				temp2 = getRandomNode(random, temp->left, count);
			}
			temp2 = getRandomNode(random, temp->right, count);
		}
		return temp2;*/
	}
	return temp;
}

template <typename T>
void BST<T>::write(const std::string& file_name, BST<T> data) // Writes the given BST data to the given file name.
{
	ofstream out;
	out.open(file_name,std::ios::binary);
	out.write(reinterpret_cast<char*>(&data), sizeof(BST<T>));
	out.close();
}
template <typename T>
void BST<T>::read(const std::string& file_name, BST<T> data) // Reads the given file and assigns the data to the given BST.
{
	ifstream in;
	in.open(file_name,std::ios::binary);
	in.read(reinterpret_cast<char*>(&data), sizeof(BST<T>));
	in.close();
}

