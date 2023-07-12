#include <iostream>
#include <stdlib.h>
using namespace std;

class Student{
	public:
		Student();
		
		void setbnum(string s);
		void setuserid(string s);
		void setfirst(string s);
		void setlast(string s);
		string getbnum();
		string getuserid();
		string getfirst();
		string getlast();
	
	private:
		string bnum;
		string userid;
		string first;
		string last;


};
