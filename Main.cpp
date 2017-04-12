#include <iostream>
#include "Student.h"
#include "BST.h"
#include <string>
#include <fstream>
#include "Advisor.h"
#include <cstdlib>
#include <Stack.h>

int main()
{
	Student myStudent ("Christine", "Junior", "Mathematics", 3.9, 1856076, 1234567);
	//cout<<myStudent;
	Advisor myAdvisor ("Joe", "professor", "science", 21234567);

	BST<Student> myTree;
	myTree.insert(myStudent);
	myTree.insert(Student("Sandra", "Sophomore", "AT", 3.0, 2256076, 9034567));
	myTree.insert(Student("Emma","Freshman", "English",5.6, 1002345,48503940));
	//myTree.printInOrder(myTree.getRoot());
	//TreeNode<Student>* something = myTree.getMin();
	//cout<<something->getData()<<endl;
	myTree.deleteNode(TreeNode<Student>(Student(1856076)));
	//myTree.printInOrder(myTree.getRoot());
	
	/*BST<Advisor> myTree2;
	myTree2.insert(myAdvisor);

	cout << "hello" << endl;
	myTree2.printInOrder(myTree2.getRoot());


	ofstream facultyFile;
	facultyFile.open("facultyTable");
	facultyFile.write((char *)&myTree2, sizeof(myTree2));
	facultyFile.close();*/

	/*ofstream studentFile;
	studentFile.open("studentTable.txt", ios::binary);
	for (int i = 0; i < myTree, ++i)
	{
		int numID = myTree.preOrder(myTree.getID());
		numID.save(studentFile);
		studentFile.close();
	}*/
	/*studentFile.write((char *)&myTree, sizeof(myTree));
	studentFile.close();

	ifstream openFile("studentTable.txt", ios::binary);
	openFile.read((char *)&myTree, sizeof(myTree));

	BST<Student> newTree;
	newTree.insert()

	myTree.insert(Student("Jenn", "Sophomore", "science", 3.7, 2262063, 9034567));
	myTree.printInOrder(myTree.getRoot());

	studentFile.write((char *)&myTree, sizeof(myTree));*/



	int choice;

	cout << "Menu: " << endl;
	cout << "1. Print all students and their information" << endl;
	cout << "2. Print all faculty and their information" << endl;
	cout << "3. Find and display student information given the student id" << endl;
	cout << "4. Find and display faculty information given the faculty id" << endl;
	cout << "5. Given a student's id, print the name and info of their faculty advisor" << endl;
	cout << "6. Given a faculty id, print all the names and infor of his/her advisees" << endl;
	cout << "7. Add a new student" << endl;
	cout << "8. Delete a student given their id" << endl;
	cout << "9. Add a new faculty member given the id" << endl;
	cout << "10. Delete a faculty member given the id" << endl;
	cout << "11. Change a student's advisor given the student id and the new faculty id" << endl;
	cout << "12. Remove an advisee from a faculty member givne the ids" << endl;
	cout << "13. Rollback" << endl;
	cout << "14. Exit" << endl;

	cout << "Enter the menu option you want to use: " << endl;
	cin << choice;
	if (choice == 1)
	{
		myTree.printInOrder(myTree.getRoot());
	}
	else if (choice == 2)
	{
		myTree2.printInOrder(myTree2.getRoot());
	}
	else if (choice == 3)
	{
		string studentID;
		cout << "Enter the student's ID: " << endl;
		cin >> studentID;
		int stdID = atoi(studentID);
		//find student
	}
	else if (choice == 4)
	{
		string advisorID;
		cout << "Enter the advisor's ID: " << endl;
		cin >> advisorID;
		int adID = atoi(advisorID);
		//find advisor
	}
	else if (choice == 5)
	{
		string studentID;
		cout << "Enter the student's ID: " << endl;
		cin >> studentID;
		int stdID = atoi(studentID);
		//fin advisor 
	}
	else if (choice == 6)
	{
		string advisorID;
		cout << "Enter the advisor's ID: " << endl;
		cin >> advisorID;
		int adID = atoi(advisorID);
		//find students
	}
	else if (choice == 7)
	{
		string name;
		cout << "Enter the name of the student: " << endl;
		cin >> name;
		string level;
		cout << "Enter the grade level: " << endl;
		cin >> level;
		string major;
		cout << "Enter the major: " << endl;
		cin >> major;
		string numGPA;
		cout << "Enter the student's GPA: " << endl;
		cin >> numGPA;
		double gpa = atof(numGPA);
		string numID;
		cout << "Enter the ID number: " << endl;
		cin >> numID;
		int ID = atoi(numID);
		string advisorID;
		cout << "Enter the advisor's ID: " << endl;
		cin >> advisorID;
		int adID = atoi(advisorID);

		myTree.insert(Student(name, level, major, gpa, ID, adID));
	}
	else if (choice == 8)
	{
		string studentID;
		cout << "Enter the student's ID: " << endl;
		cin >> studentID;
		int stdID = atoi(studentID);
		//find ID in advior list and delete it
		//delete student
	}
	else if (choice == 9)
	{
		string name;
		cout << "Enter the name of the advisor: " << endl;
		cin >> name;
		string level;
		cout << "Enter the position level: " << endl;
		cin >> level;
		string dep;
		cout << "Enter the department: " << endl;
		cin >> dep;
		string numID;
		cout << "Enter the advisor's ID number: " << endl;
		cin >> numID;
		int ID = atoi(numID);

		myTree2.insert(Student(name, level, dep, ID));
	}
	else if (choice == 10)
	{
		string advisorID;
		cout << "Enter the advisor's ID: " << endl;
		cin >> advisorID;
		int adID = atoi(advisorID);
		//reassign students to new advisor
		//delete advisor
	}
	else if (choice == 11)
	{
		string studentID;
		cout << "Enter the student's ID: " << endl;
		cin >> studentID;
		int stdID = atoi(studentID);

		string advisorID;
		cout << "Enter the new advisor's ID: " << endl;
		cin >> advisorID;
		int adID = atoi(advisorID);

		//remove advisor ID and replace it
		//remove student from advisors list
	}
	else if (choice == 12)
	{
		string studentID;
		cout << "Enter the student's ID: " << endl;
		cin >> studentID;
		int stdID = atoi(studentID);

		string advisorID;
		cout << "Enter the new advisor's ID: " << endl;
		cin >> advisorID;
		int adID = atoi(advisorID);

		//remove student from advisor list
	}
	else if (choice == 13)
	{
		//rollback from template stack
	}
	else //exit
	{
		break;
	}

}



















