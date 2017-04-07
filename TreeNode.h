#include <iostream>

using namespace std;

class TreeNode
{
	public:
		TreeNode();
		TreeNode(int key);
		virtual ~TreeNode(); //determines dynamic binding vs static binding 
		int key;
		//Student myStudent;
		TreeNode *left;
		TreeNode *right;

};
