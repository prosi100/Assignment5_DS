#include <iostream>

using namespace std;

template <typename T>
class TreeNode
{
	public:
		TreeNode();
		TreeNode(T theValue);
		virtual ~TreeNode(); //determines dynamic binding vs static binding 
	private:
		T value;
		TreeNode *left;
		TreeNode *right;
		template <class U> friend class BST;
};

template <typename T>
TreeNode<T>::TreeNode()
{
	left = NULL;
	right = NULL;
	value = NULL;
}

template <typename T>
TreeNode<T>::TreeNode(T theValue)
{
	left = NULL;
	right = NULL;
	value = theValue;
}

template <typename T>
TreeNode<T>::~TreeNode(){}
