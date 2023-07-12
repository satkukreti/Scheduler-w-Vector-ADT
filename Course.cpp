#include "Course.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
   
	/*Course::Course(string crn, string department, string number, string name) {
   	crn = crn;
   	department = department;
   	number = number;
   	name = name;
   }*/
   
   Course::Course(){
		crn = " ";
   	department = " ";
   	number = " ";
   	name = " ";
   	r = new Roster();
   }
	
	//Course::~Course(){
		//delete r;
	//}
	
	void Course::addr(string s){
		r->addstring(s);
	}
	
	void Course::dropr(string s){
		r->removestring(s);
	}
	
	string Course::getstu(int i){
		return r->getstudent(i);	
	}
	
	int Course::getsize(){
		return r->getsize();	
	}
	
	int Course::getq(){
		return r->getquantity();	
	}
	
	bool Course::check(string s){
		if(r->search(s).compare(s) == 0){
			return true;
		} else {
			return false;
		}
	}
	
	void Course::setcrn(string ncrn){
		crn = ncrn;
	}
	
	void Course::setdepartment(string nd){
		department = nd;
	}
	
	void Course::setnum(string nnum){
		number = nnum;
	}
	
	void Course::setname(string nn){
		name = nn;
	}

	string Course::getCRN(){
		return crn;
	}
	
	string Course::getdepartment(){
		return department;
	}
	
	string Course::getnumber(){
		return number;
	}
	
	string Course::getname(){
		return name;
	}

   void Course::show() {
      cout << department << name << " (CRN: " << crn << "): ";
   }
