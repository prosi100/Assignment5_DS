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
		Student operator>(Student &myObj);
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

Student::operator>(Student &myObj)
{
	if (this.ID>myObj->ID)
	{
		return this;
	}

	else
	{
		return myObj;
	}
}
