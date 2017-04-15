#include <iostream>
#include <string>
#include <iostream>
#include "Stack.h"

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
		BST<Student> getMasterStudent();
		BST<Advisor> getMasterAdvisor();

	private:
		BST<Student> masterStudent;
		BST<Advisor> masterFaculty;
		GenStack<Student> rollbackStd;
		GenStack<Advisor> rollbackAd;
};

Simulation::Simulation(BST<Student> st,BST<Advisor> ad)
{
	masterStudent = st;
	masterFaculty = ad;
}

Simulation::~Simulation()
{

}

int Simulation::checkIntegerInput(string inputString)
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

void Simulation::option1()
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

void Simulation::option2()
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

void Simulation::option3()
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

void Simulation::option4()
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
		cout<<"out"<<endl;
		Advisor theAdvisor = masterFaculty.getNode(Advisor(theID));
		cout<<theAdvisor<<endl;
	}
	else
	{
		cout<<"This faculty member is not in the system."<<endl;
	}
}
void Simulation::option5()
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

void Simulation::option6()
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

void Simulation::option7()
{
	string inputString;
	bool goodValue;
	string name;
	string level;
	string major;
	double GPA;
	int id;			
	int advisorID;
	cout<<"Please enter the student's name: "<<endl;
	cin>>name;
	cout<<"Please enter the student's level: "<<endl;
	cin>>level;
	cout<<"Please enter the student's major: "<<endl;
	cin>>major;
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
		
		if(!masterFaculty.contains(Advisor(advisorID)))
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
void Simulation::option8()
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
	Student myStudent= masterStudent.getNode(Student(theID)); //makes student based off id
	Advisor advisorID = myStudent.getAdvisorID(); //find advisor id 
	Advisor myAdviosr = masterFaculty.getNode(Advisor(advisorID)); //find advisor in bst based off id
	masterFaculty.deleteNode(Advisor(theID)); //delete student id from advisor 
	masterStudent.deleteNode(Student(theID)); //delete student
	rollbackStd.push(myStudent);

}

void Simulation::option9()
{
	string inputString;
	bool goodValue;
	string name;
	string level;
	string department;
	int id;	
	//what do we do about the student IDs??????
	cout<<"Please enter the faculty member's name: "<<endl;
	cin>>name;
	cout<<"Please enter the faculty member's level: "<<endl;
	cin>>level;
	cout<<"Please enter the faculty member's department: "<<endl;
	cin>>department;
	
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
	rollbackAd.push(Advisor(name, level, department, id));
}
void Simulation::option10()
{
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
	Advisor myAdvisor= masterFaculty.getNode(Advisor(theID)); //makes advisor based off id
	masterFaculty.deleteNode(Advisor(theID)); //delete advisor 
	rollbackAd.push(myAdvisor);

}
void Simulation::option11()
{
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
	Advisor myAdvisor= masterFaculty.getNode(Advisor(theID)); //makes advisor based off id
	rollbackAd.push(myAdvisor);

	cout << "Enter the student's ID: " << endl;
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
	Student myStudent= masterStudent.getNode(Student(theID)); //makes student based off id
	rollbackStd.push(myStudent);
}
void Simulation::option12()
{
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
	Advisor myAdvisor= masterFaculty.getNode(Advisor(theID)); //makes advisor based off id
	rollbackAd.push(myAdvisor);

	cout << "Enter the student's ID: " << endl;
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
	Student myStudent= masterStudent.getNode(Student(theID)); //makes student based off id
	rollbackStd.push(myStudent);
}
void Simulation::option13()
{
	while (rollbackAd.isEmpty()==false)
	{
		masterFaculty.insert(rollbackAd.pop()); //pop advisor off stack and back into tree
	}
	while (rollbackStd.isEmpty()==false)
	{
		masterStudent.insert(rollbackStd.pop()); //pop student off stack and back into tree
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


