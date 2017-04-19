#include <iostream>
#include <string>
#include <cstdlib>
#include "Student.h"
#include "BST.h"
#include "Advisor.h"
#include "Simulation.h"
#include <ctime>

using namespace std;


BST<Student> masterStudent("studentTable.txt");
BST<Advisor> masterFaculty("facultyTable.txt");

//deserializes student/faculty trees
	void initDatabases()
	{
    	//masterStudent.deserialize();
    	masterFaculty.deserialize();
	}

//serializes student/faculty trees
	void saveDatabases()
	{
    	//masterStudent.serialize();
    	masterFaculty.serialize();
	}


int main()
{
	Advisor myAdvisor("Rene", "Top","CS", 124861);
	cout<<myAdvisor.ToString();
	srand(time(NULL));
	/*int size = 4;
	string s;
	while (true)
	{
		int random = rand()%size;
		cout<<random<<endl;
		cin>>s;
	}*/

	initDatabases();

	//masterStudent.read("studentTable.txt", masterStudent);
	//masterFaculty.read("facultyTable.txt", masterFaculty);
	//masterFaculty.printInOrder(masterFaculty.getRoot());

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
		cout<<"12. Remove an advisee from a faculty member given the student ID"<<endl;
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

			else if(userChoice==5)
			{
				simObject.option5();
			}

			else if(userChoice==6)
			{
				simObject.option6();
			}

			else if(userChoice==7)
			{
				simObject.option7();
			}

			else if(userChoice==8)
			{
				simObject.option8();
			}

			else if(userChoice==9)
			{
				simObject.option9();
			}

			else if(userChoice==10)
			{
				simObject.option10();
			}

			else if(userChoice==11)
			{
				simObject.option11();
			}

			else if(userChoice==12)
			{
				simObject.option12();
			}

			else if(userChoice==13)
			{
				simObject.option13();
			}

			else//save and exit
			{
				masterFaculty = simObject.getMasterAdvisor();
				masterFaculty.printInOrder(masterFaculty.getRoot());
				masterStudent = simObject.getMasterStudent();
				saveDatabases();
				//for(int i=0;i<100;++i)
				//{
				//	someTree.insert(Advisor("Joe Smith", "High Level", "Comp Sci", i*112));
				//}
				//someTree.printInOrder(someTree.getRoot());
				//someTree.writePreOrder(someTree.getRoot());
				//someTree.read("facultyTable.bin", myTree);
				//cout<<"Size Before: "<<sizeof(someTree)<<endl;
				//cout<<"Size: "<<myTree.getSize()<<endl;
				myvalue = false;
				/*masterFaculty.write("facultyTable.txt", simObject.getMasterAdvisor());
				masterStudent.write("studentTable.txt", simObject.getMasterStudent());
				masterStudent.read("studentTable.txt", masterStudent);
				masterFaculty.read("facultyTable.txt",masterFaculty);
				cout<<masterFaculty.getSize()<<endl;*/
			}

	}

}
