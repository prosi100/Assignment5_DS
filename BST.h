#include <iostream>
#include <string>

using namespace std;

template <typename T>
class BST
{
	public:
		BST();
		~BST();

		void insert(T value);
		bool contains(int value);
		//bool deleteNode(int value);

		bool isEmpty();
		bool isFull();
		int getMin(); //left most
		int getMax(); //right most

		//TreeNode* getSuccessor(TreeNode d); //helper function for delete method
		//print functions

	private:
		TreeNode* root;
};

BST::BST()
{
	root = NULL;
}

BST::~BST()
{

}

void BST::insert(T value)//like a failed search. Could also make recursive.
{
	/*TreeNode* node = new TreeNode(value);	

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
	}*/
}