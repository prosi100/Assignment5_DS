#include <iostream>
#include <string>
#include <iostream>
#include "GenStack.h"

using namespace std;

class Simulation
{
	public:
		Simulation(BST<Student> st,BST<Advisor> ad);
		~Simulation();
		int checkIntegerInput(string inputString);
		void option1();
		void option2();
		void option3();
		void option4();
		void option5();
		void option6();
		void option7();
		void option8();
		void option9();
		void option10();
		void option11();
		void option12();
		void option13();
		BST<Advisor> getMasterAdvisor();
		BST<Student> getMasterStudent();
		

	private:
		BST<Student> masterStudent;
		BST<Advisor> masterFaculty;

		GenStack<BST<Student> > rollbackStd; //make stack for rollback 
		GenStack<BST<Advisor> > rollbackAd;
};

Simulation::Simulation(BST<Student> st,BST<Advisor> ad)
{
	masterStudent = st;
	masterFaculty = ad;
}

Simulation::~Simulation()
{

}

int Simulation::checkIntegerInput(string inputString)//makes sure the input is an integer
{
	int count = 0;
	int userChoice;
		for (int i =0; i < inputString.size(); ++i)
		{
			char myChar = inputString[i];
			if ((myChar== '0')||(myChar== '1')||(myChar== '2')||(myChar== '3')||(myChar== '4')||(myChar== '5')||(myChar== '6')||(myChar== '7')||(myChar== '8')||(myChar== '9'))
			{
				count++;
			}
			else
			{
				return -1;
			}
		}
	inputString = inputString.substr(0,count);
	userChoice = atoi(inputString.c_str());
	return userChoice;
}

void Simulation::option1()//prints students
{
	if(masterStudent.isEmpty())
	{
		cout<<"No students in directory"<<endl;
	}
	else
	{
		masterStudent.printInOrder(masterStudent.getRoot());
	}
}

void Simulation::option2()//prints faculty
{
	if(masterFaculty.isEmpty())
	{
		cout<<"No faculty in directory"<<endl;
	}
	else
	{
		masterFaculty.printInOrder(masterFaculty.getRoot());
	}
}

void Simulation::option3()//prints student info given an ID
{
	bool goodValue;
			string inputString;
			cout<<"Please enter student ID"<<endl;
			int theID;
			do//checks that the input is valid
			{
				goodValue = true;			
				cin>>inputString;
				int count = 0;
				theID = checkIntegerInput(inputString);
				if(theID==-1)
				{
					cout<<"Please enter a valid number"<<endl;
					goodValue=false;
				}

			}while(!goodValue);

			if(masterStudent.contains(Student(theID)))
			{
				cout<<masterStudent.getNode(Student(theID))<<endl;
			}
			else
			{
				cout<<"This student is not in the system."<<endl;
			}
}

void Simulation::option4()//prints faculty info given an id
{
	bool goodValue;
	string inputString;
	cout<<"Please enter faculty ID"<<endl;
	int theID;
	do//checks that the input is valid
	{
		goodValue = true;			
		cin>>inputString;
		int count = 0;
		theID = checkIntegerInput(inputString);
		if(theID==-1)
		{
			cout<<"Please enter a valid number"<<endl;
			goodValue=false;
		}
	}while(!goodValue);
	if(masterFaculty.contains(Advisor(theID)))
	{
		Advisor theAdvisor = masterFaculty.getNode(Advisor(theID));
		cout<<theAdvisor<<endl;
	}
	else
	{
		cout<<"This faculty member is not in the system."<<endl;
	}
}

void Simulation::option5()//prints advisor given student id
{
	bool goodValue;
	string inputString;
	cout << "Enter the student's ID: " << endl;
	int theID;
	do//checks that the input is valid
	{
		goodValue = true;			
		cin>>inputString;
		int count = 0;
		theID = checkIntegerInput(inputString);
		if(theID==-1)
		{
			cout<<"Please enter a valid number"<<endl;
			goodValue=false;
		}
	}while(!goodValue);

	if(masterStudent.contains(Student(theID)))
	{
		Student theStudent = masterStudent.getNode(Student(theID));
		int advID = theStudent.getAdvisorID();
		if(masterFaculty.contains(Advisor(advID)))
		{
			Advisor someAdvisor = masterFaculty.getNode(Advisor(advID));
			cout<<someAdvisor<<endl;
		}
		else
		{
			cout<<"Invalid faculty ID"<<endl;
		}
	}
	else
	{
		cout<<"Invalid Student ID."<<endl;
	}
}


void Simulation::option6()//prints student info given faculty id
{
	bool goodValue;
	string inputString;
	cout << "Enter the faculty's ID: " << endl;
	int theID;
	do//checks that the input is valid
	{
		goodValue = true;			
		cin>>inputString;
		int count = 0;
		theID = checkIntegerInput(inputString);
		if(theID==-1)
		{
			cout<<"Please enter a valid number"<<endl;
			goodValue=false;
		}
	}while(!goodValue);
	
	if (masterFaculty.contains(Advisor(theID)))
	{
		Advisor theAdvisor = masterFaculty.getNode(Advisor(theID));
		vector<int> theList = theAdvisor.getStudentList();
		for(int i=0; i<theList.size();++i)
		{
			cout<<masterStudent.getNode(Student(theList[i]))<<endl;
		}
	}
	else
	{
		cout<<"Invalid advisor ID"<<endl;
	}
}

void Simulation::option7()//adding a new student
{
	rollbackStd.push(masterStudent);//saves current info to stack
	rollbackAd.push(masterFaculty);
	string inputString;
	bool goodValue;
	double GPA;
	int id;			
	int advisorID;
	
	cin.ignore(256, '\n');
	cout<<"Please enter the student's name: "<<endl;
	char name[100];
	cin.getline(name, sizeof(name));
	
	cout<<"Please enter the student's level: "<<endl;
	char level[100];
	cin.getline(level, sizeof(level));

	cout<<"Please enter the student's major: "<<endl;
	char major[100];
	cin.getline(major, sizeof(major));

	cout<<"Please enter the student's GPA: "<<endl;
	do
	{
		goodValue = true;				
		cin>>GPA;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout<<"Invalid GPA, try again"<<endl;
			goodValue =false;
		}
		if ((GPA<0)||(GPA>5))
		{
			cout<<"Invalid GPA.  Try again."<<endl;
			goodValue = false;
		}
	}while(goodValue == false);

	cout<<"Please enter the student's ID: "<<endl;
	do//checks that the input is valid
	{
		goodValue = true;			
		cin>>inputString;
		int count = 0;
		id =checkIntegerInput(inputString);
		if(id==-1)
		{
			cout<<"Please enter a valid number"<<endl;
			goodValue=false;
		}

	}while(!goodValue);

	cout<<"Please enter the ID of the faculty advisor: "<<endl;
	do//checks that the input is valid
	{
		goodValue = true;			
		cin>>inputString;
		int count = 0;
		advisorID = checkIntegerInput(inputString);
		if(advisorID==-1)
		{
			cout<<"Please enter a valid number"<<endl;
			goodValue=false;
			continue;
		}
		
		if(!masterFaculty.contains(Advisor(advisorID)))//must have valid faculty member
		{
			cout<<"This faculty member does not exist in the system.  Returning to menu"<<endl;//exits if the faculty advisor does not exist
			goodValue = false;
			break;
		}
	}while(!goodValue);

	if(goodValue)
	{
		masterStudent.insert(Student(name, level, major, GPA, id, advisorID));
		Advisor theirAdvisor = masterFaculty.getNode(Advisor(advisorID));
		theirAdvisor.addStudent(id);
		masterFaculty.insertDataAtNode(theirAdvisor, theirAdvisor);
	}
}

void Simulation::option8()//deletes a student given the id
{
	rollbackStd.push(masterStudent);
	rollbackAd.push(masterFaculty);
	bool goodValue;
	string inputString;
	cout << "Enter the student's ID: " << endl;
	int theID;
	do//checks that the input is valid
	{
		goodValue = true;			
		cin>>inputString;
		int count = 0;
		theID = checkIntegerInput(inputString);
		if(theID==-1)
		{
			cout<<"Please enter a valid number"<<endl;
			goodValue=false;
		}
	}while(!goodValue);
	
	if(masterStudent.contains(Student(theID)))
	{
		Student myStudent= masterStudent.getNode(Student(theID)); //gets student from tree
		int studentID = myStudent.getID();
		int advID = myStudent.getAdvisorID();//gets advisor id
		Advisor myAdvisor = masterFaculty.getNode(Advisor(advID)); //find advisor in bst based off id
		myAdvisor.removeStudent(studentID);
		masterFaculty.insertDataAtNode(myAdvisor,Advisor(advID));
		masterStudent.deleteNode(myStudent); //delete student
	}
	else
	{
		cout<<"Invalid student ID"<<endl;
	}
}

void Simulation::option9()//add a faculty member
{
	rollbackStd.push(masterStudent);//saves current info
	rollbackAd.push(masterFaculty);
	string inputString;
	bool goodValue;
	
	int id;	
	
	cin.ignore(256, '\n');
	cout<<"Please enter the faculty member's name: "<<endl;
	char name[100];
	cin.getline(name,sizeof(name));
	
	cout<<"Please enter the faculty member's level: "<<endl;
	char level[100];
	cin.getline(level, sizeof(level));
	
	cout<<"Please enter the faculty member's department: "<<endl;
	char department[100];
	cin.getline(department, sizeof(department));
	
	
	cout<<"Please enter the faculty member's ID"<<endl;
	do//checks that the input is valid
	{
		goodValue = true;			
		cin>>inputString;
		int count = 0;
		id =checkIntegerInput(inputString);
		if(id==-1)
		{
			cout<<"Please enter a valid number"<<endl;
			goodValue=false;
		}

	}while(!goodValue);

	masterFaculty.insert(Advisor(name, level, department, id));
}

void Simulation::option10()//delete a faculty member given id
{
	rollbackStd.push(masterStudent);
	rollbackAd.push(masterFaculty);
	bool goodValue;
	string inputString;
	cout << "Enter the advisor's ID: " << endl;
	int theID;
	do//checks that the input is valid
	{
		goodValue = true;			
		cin>>inputString;
		int count = 0;
		theID = checkIntegerInput(inputString);
		if(theID==-1)
		{
			cout<<"Please enter a valid number"<<endl;
			goodValue=false;
		}
	}while(!goodValue);

	if(masterFaculty.contains(Advisor(theID)))
	{
		if(masterStudent.getSize()==0)
		{
			masterFaculty.deleteNode(Advisor(theID));		
		}
		else if(masterFaculty.getSize()>1)
		{
			vector<int> studList = masterFaculty.getNode(Advisor(theID)).getStudentList();
			int theSize = studList.size();//use the student list to reassign student advisors
			masterFaculty.deleteNode(Advisor(theID));			
			for(int i=0; i<theSize;++i)
			{
				int studentID = studList[0];				
				Advisor newAdvisor = masterFaculty.getRandomNode(masterFaculty.getRoot())->getData();//gets data of random advisor
				newAdvisor.addStudent(studentID);
				int newAdvisorID = newAdvisor.getID();
				masterFaculty.insertDataAtNode(newAdvisor, newAdvisor);//updated the advisor by adding the student

				Student updateStudent = masterStudent.getNode(Student(studentID));
				updateStudent.setAdvisorID(newAdvisorID);
				masterStudent.insertDataAtNode(updateStudent, updateStudent);
				studList.erase(studList.begin());//erase the reassigned student from the list
			}
		}
		
		else
		{
			cout<<"You cannot delete the faculty member(s), because the students will have no advisor!"<<endl;
		}

	}

	else
	{
		cout<<"This faculty member does not exist"<<endl;
	}

}

void Simulation::option11()//changes a student's advisor
{
	rollbackStd.push(masterStudent);//save current info
	rollbackAd.push(masterFaculty);
	bool goodValue;
	string inputString;
	cout << "Enter the advisor's ID: " << endl;
	int theID;
	do//checks that the input is valid
	{
		goodValue = true;			
		cin>>inputString;
		int count = 0;
		theID = checkIntegerInput(inputString);
		if(theID==-1)
		{
			cout<<"Please enter a valid number"<<endl;
			goodValue=false;
		}
	}while(!goodValue);
	if (masterFaculty.contains(Advisor(theID)))
	{
		cout << "Enter the student's ID: " << endl;
		int theID2;
		do//checks that the input is valid
		{
			goodValue = true;			
			cin>>inputString;
			int count = 0;
			theID2 = checkIntegerInput(inputString);
			if(theID2==-1)
			{
				cout<<"Please enter a valid number"<<endl;
				goodValue=false;
			}
		}while(!goodValue);
		if (masterStudent.contains(Student(theID2)))
		{
			Student Student1 = masterStudent.getNode(Student(theID2));
			int adID = Student1.getAdvisorID();
			Advisor advisor1 = masterFaculty.getNode(Advisor(adID));
			advisor1.removeStudent(theID2);//removes student from the given advisor
			Student1.setAdvisorID(theID);
			masterStudent.insertDataAtNode(Student1,Student(theID2));
			masterFaculty.insertDataAtNode(advisor1, Advisor(adID));
			Advisor Advisor2 = masterFaculty.getNode(Advisor(theID));
			Advisor2.addStudent(theID2);//gives student to the new advisor
			masterFaculty.insertDataAtNode(Advisor2, Advisor(theID));

		}
		else 
		{
			cout << "This is not a valid student ID" << endl;
		}
	}
	else 
	{
		cout << "This is not a valid advisor ID" << endl;
	}

}

void Simulation::option12()//remove advisee from a faculty member
{
	rollbackStd.push(masterStudent);
	rollbackAd.push(masterFaculty);
	bool goodValue;
	string inputString;
	int studentID;
	cout << "Enter the student's ID: " << endl;
	do//checks that the input is valid
	{
		goodValue = true;			
		cin>>inputString;
		int count = 0;
		studentID = checkIntegerInput(inputString);
		if(studentID==-1)
		{
			cout<<"Please enter a valid number"<<endl;
			goodValue=false;
		}
	}while(!goodValue);
	if(masterStudent.contains(Student(studentID)))
	{
		if(masterFaculty.getSize()>2)
		{
			Student myStudent= masterStudent.getNode(Student(studentID)); //makes student based off id
			int advisorID = myStudent.getAdvisorID();
			Advisor advisor1 = masterFaculty.getNode(Advisor(advisorID));
			advisor1.removeStudent(studentID);
			masterFaculty.insertDataAtNode(advisor1, advisor1);
			Advisor advisor2 = masterFaculty.getRandomNode(masterFaculty.getRoot())->getData();
			while (true)//to get a random new advisor for the student which is not the same advisor
			{	
				advisor2 = masterFaculty.getRandomNode(masterFaculty.getRoot())->getData();			
				if (advisor1!=advisor2)
				{
					break;
				}
			}
			
			advisor2.addStudent(studentID);
			myStudent.setAdvisorID(advisor2.getID());
			masterStudent.insertDataAtNode(myStudent, myStudent);
			masterFaculty.insertDataAtNode(advisor2,advisor2);
		}
		else
		{
			cout<<"You do not have enough faculty members to perform this operation"<<endl;
		}
	}
	else
	{
		cout<<"This is not a valid ID"<<endl;
	}

}

void Simulation::option13()//rollback
{
	if(rollbackAd.getSize()==0)
	{
		cout<<"Could not undo last faculty operation"<<endl;
	}
	else
	{
		masterFaculty = rollbackAd.pop();
	}
	if(rollbackStd.getSize()==0)
	{
		cout<<"Could not undo last student operation"<<endl;
	}
	else
	{
		masterStudent = rollbackStd.pop();
	}
}

BST<Student> Simulation::getMasterStudent()
{
	return masterStudent;
}
		
BST<Advisor> Simulation::getMasterAdvisor()
{
	return masterFaculty;
}
