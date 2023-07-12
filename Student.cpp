#include "Student.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

	Student::Student(){
		bnum = " ";
		userid = " ";
		first = " ";
		last = " ";
	}

	void Student::setbnum(string s){
		bnum = s;	
	}

	void Student::setuserid(string s){
		userid = s;	
	}
	
	void Student::setfirst(string s){
		first = s;	
	}
	
	void Student::setlast(string s){
		last = s;	
	}

	string Student::getbnum(){
		return bnum;
	}
	
	string Student::getuserid(){
		return userid;
	}
	
	string Student::getfirst(){
		return first;
	}
	
	string Student::getlast(){
		return last;
	}