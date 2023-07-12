#include "Course.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

class CourseList{
	public:
		CourseList();
		~CourseList();
		int getsize();
		int getq();
		Course getcourse(int i);
		int geti(string nCRN);
		string searchByCRN(string nCRN);
		void addCourse(Course nCourse);
		void removeCourse(string nCRN);		
		
	private:
		Course *cList;
		int capacity;
		int quantity;
};