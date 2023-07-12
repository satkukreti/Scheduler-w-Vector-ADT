#include "Roster.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

class Course {
   public:
      //Course(string crn, string department, string number, string name);//: roster(crn); //get this to work
		Course();  
		//~Course();

		void setcrn(string ncrn);
		void setdepartment(string nd);
		void setnum(string nnum);
		void setname(string nn);
		 
		void addr(string s);
		void dropr(string s);
		string getstu(int i);
		int getsize();
		int getq();
		//void printr();
		bool check(string s);
      string getCRN();
      string getdepartment();
      string getnumber();
      string getname();
      void show();

   private:
   	string crn;
   	string department;
   	string number;
      string name;
  		Roster *r;
};
