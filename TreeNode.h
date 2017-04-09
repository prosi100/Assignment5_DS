#include <iostream>

using namespace std;

template <typename T>
class TreeNode
{
	public:
		TreeNode();
		TreeNode(int k);
		virtual ~TreeNode(); //determines dynamic binding vs static binding 
	private: 
		int key;
		T value;
		TreeNode *left;
		TreeNode *right;
		template <class U> friend class BST;
};

TreeNode::TreeNode()
{
	left = NULL;
	right = NULL;
	key = 0;
	T = NULL;
}
TreeNode::TreeNode(int theKey, T theValue)
{
	left = NULL;
	right = NULL;
	key = k;
	T = theValue;
}
TreeNode::~TreeNode(){}
