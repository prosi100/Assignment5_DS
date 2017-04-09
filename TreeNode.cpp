#include <iostream>
#include "TreeNode.h"

using namespace std;

TreeNode::TreeNode()
{
	left = NULL;
	right = NULL;
}
TreeNode::TreeNode(int k)
{
	left = NULL;
	right = NULL;
	key = k;
}
TreeNode::~TreeNode(){}
