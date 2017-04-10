#include <iostream>
#include "Student.h"
#include "BST.h"
int main()
{
	Student myStudent ("Christine", "Junior", "Mathematics", 3.9, 1856076, 1234567);
	//cout<<myStudent;

	BST<Student> myTree;
	myTree.insert(myStudent);
	myTree.printInOrder(myTree.getRoot());
}