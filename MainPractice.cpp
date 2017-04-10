#include <iostream>
#include "Student.h"
#include "BST.h"
int main()
{
	Student myStudent ("Christine", "Junior", "Mathematics", 3.9, 1856076, 1234567);
	//cout<<myStudent;

	BST<Student> myTree;
	myTree.insert(myStudent);
	myTree.insert(Student("Sandra", "Sophomore", "AT", 3.0, 2256076, 9034567));
	myTree.insert(Student("Emma","Freshman", "English",5.6, 1002345,48503940));
	myTree.printInOrder(myTree.getRoot());
	TreeNode<Student>* something = myTree.getMin();
	cout<<something->getData()<<endl;
}