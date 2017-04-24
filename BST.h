#include <iostream>
#include <string>
#include "TreeNode.h"
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <cstdlib>

#define MARKER "NULL"

using namespace std;

template <typename T>
class BST
{
	public:
		BST();
		BST(string theFile);
		~BST();

		BST(const BST<T> & Q);
		void copy(TreeNode<T>* n);
		void chop(TreeNode<T> *n);
		const BST<T>& operator=(const BST<T> &Q);

		void insert(T theValue);
		int getSize()const;
		bool contains(T someValue);
		bool deleteNode(TreeNode<T> someNode);
		void insertDataAtNode(T newData, T oldLocation);
		void writePreOrder(TreeNode<T>* n);

		bool isEmpty();
		TreeNode<T>* getMax(); //right most
		TreeNode<T>* getMin(); //left most
		TreeNode<T>* getRandomNode(TreeNode<T>* someNode);
		TreeNode<T>* getRandomNode(int random, TreeNode<T>* temp, int count);
		T getNode(T someValue);//get the entire value at a node

		TreeNode<T>* getSuccessor(TreeNode<T> d); //helper function for delete method
		void printInOrder(TreeNode<T>* n);
		TreeNode<T>* getRoot();

		void makeSerializedString(TreeNode<T> *node, ostringstream& serialStream);
		void serialize();
		void deserialize();

	private:
		TreeNode<T>* root;
		string fileName;
		int size;
};

template <typename T>
BST<T>::BST()
{
	root = NULL;
	size =0;
}

template <typename T>
BST<T>::BST(string theFile)
{
	fileName = theFile;
}

template <typename T>
BST<T>::~BST()
{

}

template <typename T>
BST<T>::BST(const BST<T> & Q)//copy constructor
{
     root=NULL;
     copy(Q.root);
}

template <typename T>
void BST<T>::copy(TreeNode<T>* n)//copy constructor helper function
{
     if(n!=NULL)
     {
         insert(n->value);
         copy(n->left);
         copy(n->right);
     }
}

template <typename T>
void BST<T>::chop(TreeNode<T> *n)//to help with assignment operator
{
     if(n)
     {
         chop(n->left);
         chop(n->right);
         delete n;
     }
}

template <typename T>
const BST<T> & BST<T>::operator=(const BST<T> &Q)//assignment overloaded so that copy constructor will work
{
     if(this != &Q)
     {
          chop(root);
          root=NULL;
          copy(Q.root);
     }
     return *this;
}

template <typename T>
bool BST<T>::isEmpty()
{
	return root==NULL;
}

template <typename T>
int BST<T>::getSize() const
{
	return size;
}

template <typename T>
TreeNode<T>* BST<T>::getMax()//returns maximum 
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
TreeNode<T>* BST<T>::getMin()//returns minimum
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
T BST<T>::getNode(T someValue)//to retrieve a particular node given the data
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
TreeNode<T>* BST<T>::getRandomNode(TreeNode<T>* someNode)//pass in root 
{
	int random = rand()%size;
	TreeNode<T>* temp = someNode;
	someNode = getRandomNode(random, temp, 0);
	//cout<<"10"<<endl;
	return someNode;
}

template <typename T>
TreeNode<T>* BST<T>::getRandomNode(int random, TreeNode<T>* temp, int count)//to get a random node from the tree
{	
	if(temp!=NULL&&count!=random)
	{
		++count;
		if(temp->left!=NULL)//you can go left
		{
			temp = getRandomNode(random, temp->left, count);
		}
		else if(temp->right!=NULL)//you can go right
		{
			temp = getRandomNode(random, temp->right, count);
		}
		return temp;
	}
	return temp;
}

template <typename T>
void BST<T>::insertDataAtNode(T newData, T oldLocation)//to put new data at a particular node
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
	++size;

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
bool BST<T>::contains(T someValue)//checks for existence of a value
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
void BST<T>::printInOrder(TreeNode<T>* n)//prints in order
{
	if (n!=NULL)
	{
		printInOrder(n->left);
		cout<<n->value<<endl;
		printInOrder(n->right);
	}
}

template <typename T>
void BST<T>::writePreOrder(TreeNode<T>* n)//writes in preorder so that we can save data
{
	if(n!=NULL)
	{
		write("mytable.bin", *n);
		writePreOrder(n->left);
		writePreOrder(n->right);
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
	--size;
	return true;

}


//creates a string version of the database that can be saved or used to rebuild the tree
template <typename T>
void BST<T>::makeSerializedString(TreeNode<T> *node, ostringstream& serialStream)
{
	if(node == NULL) 
	{
    	serialStream << MARKER << '\n';
    	return;
    }
        
        makeSerializedString(node->left, serialStream);
        serialStream << node->value.ToString()<<'\n';
        makeSerializedString(node->right, serialStream);
}
    
    
template <typename T>
void BST<T>::serialize()//writes tree to file
{
    ofstream outFile; 
    outFile.open(fileName.c_str());
    ostringstream outStream;
    makeSerializedString(root, outStream);
    outFile << outStream.str();
    outFile.close();
}
    
   
template <typename T>
void BST<T>::deserialize() //reads tree from file
{
        delete root;
        root = NULL;
        
        ifstream inFile;
        inFile.open(fileName.c_str());
        string textLine;
        while (getline(inFile, textLine)){
            if(textLine != MARKER)
                insert(T(textLine));
        }
        
        inFile.close();
}
    

    
