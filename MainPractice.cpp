#include <iostream>
#include <cstdlib>
#include "Student.h"
#include "BST.h"
#include "Advisor.h"
#include "Simulation.h"
int main()
{
	
	/*Student myStudent ("Christine", "Junior", "Mathematics", 3.9, 1856076, 1234567);
	//cout<<myStudent;

	BST<Student> myTree;
	//myTree.insert(myStudent);
	myTree.insert(Student("Sandra", "Sophomore", "AT", 3.0, 2256076, 9034567));
	myTree.insert(Student("Emma","Freshman", "English",5.6, 1002345,48503940));
	myTree.printInOrder(myTree.getRoot());
	myTree.insertDataAtNode(myStudent, Student(2256076));
	myTree.printInOrder(myTree.getRoot());*/
	

	/*Advisor myAdvisor("Rene German", "Professor", "Computer Science", 1234567);
	BST<Advisor> someTree;
	myAdvisor.addStudent(1856076);
	myAdvisor.addStudent(1374691);
	myAdvisor.addStudent(3826491);
	myAdvisor.printStudentList();
	someTree.insert(myAdvisor);
	cout<<"done"<<endl;
	someTree.insert(Advisor("g","h","t",12345));
	cout<<"do it: "<<someTree.contains(myAdvisor)<<endl;
	cout<<"ok: "<<endl;
	myAdvisor.printStudentList();
	someTree.printInOrder(someTree.getRoot());
	myAdvisor.printStudentList();
	cout<<myAdvisor<<endl;*/

	/*DLinkedList<int> myList;
	myList.insertBack(1);
	myList.insertBack(2);
	myList.insertBack(3);
	myList.printList();
	myList.removeNode(3);
	myList.printList();*/

	BST<Student> masterStudent;
	BST<Advisor> masterFaculty;//once we do object serialization we will need to fix this
	Simulation simObject(masterStudent, masterFaculty);
	bool myvalue = true;
	
	while(myvalue)
	{

		cout<<"Please enter a number to proceed"<<endl<<endl;
		cout<<"1. Print all students and their information (sorted by ascending ID)"<<endl;
		cout<<"2. Print all faculty and their information (sorted by ascending ID)"<<endl;
		cout<<"3. Find and display student information using ID"<<endl;
		cout<<"4. Find and display faculty information using ID"<<endl;
		cout<<"5. Print information of faculty advisor given student ID"<<endl;
		cout<<"6. Given a faculty ID, print the information of all their students"<<endl;
		cout<<"7. Add a new student"<<endl;
		cout<<"8. Delete a student given ID"<<endl;
		cout<<"9. Add a new faculty member"<<endl;
		cout<<"10. Delete a faculty member given the ID"<<endl;
		cout<<"11. Change a student's advisor given the student ID and new faculty ID"<<endl;
		cout<<"12. Remove an adviseefrom a faculty member given the IDs"<<endl;
		cout<<"13. Rollback"<<endl;
		cout<<"14. Save and Exit"<<endl;

		int userChoice;
		string inputString;
		bool goodValue;
			do//checks that the input is valid
			{
				goodValue = true;			
				cin>>inputString;
				int count = 0;
				userChoice = simObject.checkIntegerInput(inputString);

				if (userChoice < 1||userChoice>14)
				{
					goodValue = false;
					cout<<"Please enter a valid number"<<endl;
				}

			}while(!goodValue);

			if(userChoice==1)
			{
				simObject.option1();
			}

			else if(userChoice==2)
			{
				simObject.option2();
			}

			else if(userChoice==3)
			{
				simObject.option3();
			}

			else if(userChoice==4)
			{
				simObject.option4();

			}

			else if(userChoice==7)
			{
				simObject.option7();
			}

			else if(userChoice==9)
			{
				simObject.option9();
			}
			else//save and exit
			{
				myvalue = false;
			}

	}

}
