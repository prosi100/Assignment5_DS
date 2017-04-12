#include <iostream>
#include <string>
#include "DLinkedList.h"
using namespace std;

class Advisor
{
private:
	string name;
	string level;
	string department;
	int ID;
	DLinkedList<int> studentList;

public:
	Advisor();
	~Advisor();
	Advisor(string theName, string theLevel, string theDepartment, int theID);
	Advisor(int theID);
	void addStudent(int studentID);
	void removeStudent(int studentID);
	string getName()const;
	string getLevel()const;
	string getDepartment()const;	
	string studentListToString()const;
	int getID()const;
	DLinkedList<int>* getStudentList();
	void printStudentList();
	bool operator>(Advisor &myObj);
	bool operator<(Advisor &myObj);
	bool operator==(Advisor &myObj);
	bool operator!=(Advisor &myObj);
	friend ostream& operator<<(ostream& os, const Advisor& obj);	
};

Advisor::Advisor()
{
	name = "";
	level = "";
	department = "";
	ID = 0;
	DLinkedList<int> studentList;
}

Advisor::Advisor(string theName, string theLevel, string theDepartment, int theID)
{
	name = theName;
	level = theLevel;
	department = theDepartment;
	ID = theID;
	DLinkedList<int> studentList;
}

Advisor::Advisor(int theID)
{
	ID = theID;
}

Advisor::~Advisor()
{

}

void Advisor::addStudent(int studentID)
{
	studentList.insertBack(studentID);
}

void Advisor::removeStudent(int studentID)
{

}

void Advisor::printStudentList()
{
	studentList.printList();
}

string Advisor::getName() const
{
	return name;
}

string Advisor::getLevel() const
{
	return level;
}

string Advisor::getDepartment() const
{
	return department;
}

int Advisor::getID() const
{
	return ID;
}

DLinkedList<int>* Advisor::getStudentList() 
{
	return &studentList;
}

bool Advisor::operator>(Advisor &myObj)
{
	if (this->ID>myObj.ID)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool Advisor::operator<(Advisor &myObj)
{
	if (this->ID<myObj.ID)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool Advisor::operator==(Advisor &myObj)
{
	return this->ID ==myObj.ID;
}

bool Advisor::operator!=(Advisor &myObj)
{
	return this->ID!=myObj.ID;
}

string Advisor::studentListToString() const
{
	return studentList.listToString();
}

ostream& operator<<(ostream& os, const Advisor& obj)
{
   os<<endl<<"Name: "<<obj.getName()<<endl<<"Level: "<<obj.getLevel()<<endl<<"Department: "<<obj.getDepartment()<<endl<<"ID: "<<obj.getID()<<endl<<"List of Students: "<<obj.studentListToString()<<endl;
   return os;
}

