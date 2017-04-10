#include <iostream>
#include <string>

using namespace std;

class Student
{
	private:
		string name;
		string level;
		string major;
		double gpa;
		int ID;
		int advisorID;

	public:
		Student();
		~Student();
		Student(string theName, string theLevel, string theMajor, double theGpa, int theID, int theAdvisorID);
		Student(int theID);
		string getName()const;
		string getLevel()const;
		string getMajor()const;
		double getGPA()const;
		int getID()const;
		int getAdvisorID()const;
		bool operator>(Student &myObj);
		bool operator<(Student &myObj);
		bool operator==(Student &myObj);
		bool operator!=(Student &myObj);
		friend ostream& operator<<(ostream& os, const Student& obj);
};

Student::Student()
{
	name = "";
	level = "";
	major = "";
	gpa = 0;
	ID = 0;
	advisorID = 0;
}

Student::~Student(){}//what happens here?

Student::Student(string theName, string theLevel, string theMajor, double theGpa, int theID, int theAdvisorID)
{
	name = theName;
	level = theLevel;
	major = theMajor;
	gpa = theGpa;
	ID = theID;
	advisorID = theAdvisorID;
}

Student::Student(int theID)
{
	name = "";
	level = "";
	major = "";
	gpa = 0;
	ID = theID;
	advisorID = 0;
}

string Student::getName() const
{
	return name;
}

string Student::getLevel() const
{
	return level;
}

string Student::getMajor() const
{
	return major;
}

double Student::getGPA() const
{
	return gpa;
}

int Student::getID() const
{
	return ID;
}
int Student::getAdvisorID() const
{
	return advisorID;
}

bool Student::operator>(Student &myObj)
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

bool Student::operator<(Student &myObj)
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

bool Student::operator==(Student &myObj)
{
	return this->ID ==myObj.ID;
}

bool Student::operator!=(Student &myObj)
{
	return this->ID!=myObj.ID;
}

ostream& operator<<(ostream& os, const Student& obj)
{
   os<<endl<<"Name: "<<obj.getName()<<endl<<"Level: "<<obj.getLevel()<<endl<<"Major: "<<obj.getMajor()<<endl<<"GPA: "<<obj.getGPA()<<endl<<"ID: "<<obj.getID()<<endl<<"Advisor ID: "<<obj.getAdvisorID();
   return os;
}
