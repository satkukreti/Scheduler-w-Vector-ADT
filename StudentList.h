#include "Student.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

class StudentList{
	public:
		StudentList();
		~StudentList();
		int getsize();
		
		string rfirstlast(string BNUM);		
		
		string searchByBnum(string nBNUM);
		void addStudent(Student nS);
		void removeStudent(string nBNUM);
		
	private:
		Student *sList;
		int capacity;
		int quantity;
};
	
