#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Advisor
{
private:
	string name;
	string level;
	string department;
	int ID;
	//DLinkedList<int> studentList;
	vector<int> studentList;

public:
	Advisor();
	~Advisor();
	Advisor(string theName, string theLevel, string theDepartment, int theID);
	Advisor(string theName, string theLeve, string theDepartment, int theID, vector<int> theList);
	Advisor(string dataRec);
	Advisor(int theID);
	void addStudent(int studentID);
	void removeStudent(int studentID);
	int locateStudent(int studentID);
	string getName()const;
	string getLevel()const;
	string getDepartment()const;	
	string studentListToString()const;
	string convertToString(int theValue) const;
	int getID()const;
	vector<int> getStudentList();
	void printStudentList();
	bool operator>(Advisor &myObj);
	bool operator<(Advisor &myObj);
	bool operator==(Advisor &myObj);
	bool operator!=(Advisor &myObj);
	virtual string ToString();
	friend ostream& operator<<(ostream& os, const Advisor& obj);	
};

Advisor::Advisor()
{
	name = "";
	level = "";
	department = "";
	ID = 0;
}

Advisor::Advisor(string theName, string theLevel, string theDepartment, int theID)
{
	name = theName;
	level = theLevel;
	department = theDepartment;
	ID = theID;
}

Advisor::Advisor(string theName, string theLevel, string theDepartment, int theID, vector<int> theList)
{
	name = theName;
	level = theLevel;
	department = theDepartment;
	ID = theID;
	studentList = theList;
}

 // Stores varaibles for faculty
Advisor::Advisor(string dataRec) 
{
    istringstream data(dataRec);
    int numStudents;
    data >> name >> level >> department >> ID >> numStudents;
    for (int i = 0; i < numStudents; i++) 
    {
       int studentID;
       data >> studentID;
       studentList.push_back(studentID);
    }
}

Advisor::Advisor(int theID)
{
	name = "";
	level ="";
	department="";
	ID = theID;
}

Advisor::~Advisor()
{
	
}

void Advisor::addStudent(int studentID)
{
	studentList.push_back(studentID);
}

int Advisor::locateStudent(int studentID)
{
	for(int i=0; i<studentList.size();++i)
	{
		if (studentID==studentList[i])
		{
			return i;
		}
	}
	return -1;
}

void Advisor::removeStudent(int studentID)
{
	int index = locateStudent(studentID);
	if (index==-1)
	{
		cout<<"Student does not belong to this advisor"<<endl;
	}
	else
	{
		studentList.erase(studentList.begin()+index);
	}
}

void Advisor::printStudentList()
{
	for(int i=0; i<studentList.size();++i)
	{
		cout<<studentList[i]<<" ";
	}
	cout<<endl;
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

vector<int> Advisor::getStudentList() 
{
	return studentList;
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

string Advisor::convertToString(int theValue) const
{
   stringstream ss;//create a stringstream
   ss << theValue;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

string Advisor::ToString() //print method for faculty
{
    stringstream s;
    string sep = " ";
    s <<name << sep << level << sep << department << sep <<  ID << sep << studentList.size() << sep;
    string result;
    for (int i = 0; i < studentList.size (); ++i)
    {
        s << studentList[i] << sep;
        s << '\n';
    }
    result = s.str();
    return result;
}

string Advisor::studentListToString() const
{
	string myString = "";
	for (int i=0; i<studentList.size(); ++i)
	{
		myString +=convertToString(studentList[i])+" ";	
	}	
	return myString;
}

ostream& operator<<(ostream& os, const Advisor& obj)
{
   os<<endl<<"Name: "<<obj.getName()<<endl<<"Level: "<<obj.getLevel()<<endl<<"Department: "<<obj.getDepartment()<<endl<<"ID: "<<obj.getID()<<endl<<"List of Students: "<<obj.studentListToString()<<endl;
   return os;
}

