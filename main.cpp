#include "CourseList.h"
#include "StudentList.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <regex>

using namespace std;


int main(){
	int exit = 1;
	
	CourseList cl;
	StudentList sl;
	while(exit != 0){
		
		cout << "Enter [\"build <crn> <department> <number> <name>\"" << std::endl <<
                "       \"cancel <crn>\"" << std::endl <<
                "       \"enroll <bnumber> <userid> <first> <last>\"" << std::endl <<
                "       \"add <bnumber> <crn>\"" << std::endl <<
                "       \"drop <bnumber> <crn>\"" << std::endl <<
                "       \"roster <crn>\"" << std::endl <<
                "       \"schedule <bnumber>\"" << std::endl <<
                "       \"quit\"]" << endl <<
                ": ";		
		
		//storing input into a string
		string input;
		getline(cin, input);
		
		//creating string tokens
		vector <string> tokens;
		stringstream location(input);
		string cmds;
		
		//while(getline(location, cmds, ' ')){
		while(location >> cmds){		
			tokens.push_back(cmds);
		}

		//executing user defined commands & error checking
		if(tokens[0].compare("build") == 0){
			if(tokens.size() >= 5){
				if(regex_match(tokens[1], regex("[0-9]{6}"))){
					if(regex_match(tokens[2], regex("[A-Z]{2,4}"))){
						int q = stoi(tokens[3]);
						if(q >= 100 && q <= 700){
						//if(regex_match(tokens[3], regex("[0-9]{3}"))){ //need to fix regex
							string cname = "";							
							for(int i = 4; i < (int)tokens.size(); i++){
								cname += tokens[i];
								cname += " ";							
							}							
							
							if(cl.searchByCRN(tokens[1]).compare("") == 0){
									Course c;
									c.setcrn(tokens[1]); 
									c.setdepartment(tokens[2]); 
									c.setnum(tokens[3]); 
									c.setname(cname);
												
									cl.addCourse(c);
									cout << "Success: built course " << c.getdepartment() << c.getnumber() << " (CRN: " << c.getCRN() << "): " << c.getname() << endl;
							} else {
								cout << "Fail: cannot build course " << tokens[2] << tokens[3] << " (CRN: " << tokens[1] << "): CRN exists" << endl; //CS240 (CRN: 123456): CRN exists
								continue;							
							}
								
						} else {
							cout << "Input Error: illegal course number" << endl;						
						}
					} else {
						cout << "Input Error: illegal department" << endl;					
					}
				} else {
					cout << "Input Error: illegal CRN" << endl;			
				}
			} else {
				cout << "Input Error: too few arguments" << endl;
			}
		} else if(tokens[0].compare("cancel") == 0){
			if(tokens.size() >= 2){
				if(regex_match(tokens[1], regex("[0-9]{6}"))){
					if(cl.searchByCRN(tokens[1]).compare("") == 0){
						if(tokens.size() > 2){ cout << "Warning: ignoring extra argument(s)" << endl;}						
						cout << "Fail: cannot cancel course, CRN does not exist" << endl;
						continue;						
					} else {
						cl.removeCourse(tokens[1]);
						if(tokens.size() > 2){ cout << "Warning: ignoring extra argument(s)" << endl;}						
						cout << "Success: canceled course " << tokens[1] << endl;
						continue;							
					}
				} else {
					cout << "Input Error: illegal CRN" << endl;
				}
			} else {
				cout << "Input Error: too few arguments" << endl;
			}
		} else if(tokens[0].compare("enroll") == 0){
			if(tokens.size() >= 5){
				if(regex_match(tokens[1], regex("B[0-9]{8}"))){
					if(regex_match(tokens[2], regex("[A-Za-z0-9]+"))){
						if(regex_match(tokens[3], regex("[A-Za-z]+"))){ //need to fix regex
							string slast = "";							
							for(int i = 4; i < (int)tokens.size(); i++){
								slast += tokens[i];
								slast += " ";							
							}							
							
							if(sl.searchByBnum(tokens[1]).compare("") == 0){
									Student s;
									s.setbnum(tokens[1]); 
									s.setuserid(tokens[2]); 
									s.setfirst(tokens[3]); 
									s.setlast(slast);
												
									sl.addStudent(s);
									cout << "Success: enrolled student " << s.getbnum() << " (" << s.getuserid() << ") " << s.getlast() << ", " << s.getfirst() << endl;
							} else {
								cout << "Fail: cannot enroll student, B Number exists" << endl;
								continue;							
							}
								
						} else {
							cout << "Input Error: illegal first name" << endl;						
						}
					} else {
						cout << "Input Error: illegal user id" << endl;					
					}
				} else {
					cout << "Input Error: illegal B Number" << endl;			
				}
			} else {
				cout << "Input Error: too few arguments" << endl;
			}
		} else if(tokens[0].compare("add") == 0){
			if(tokens.size() >= 3){
				if(regex_match(tokens[1], regex("B[0-9]{8}"))){
					if(regex_match(tokens[2], regex("[0-9]{6}"))){
							if(tokens.size() > 3){ cout << "Warning: ignoring extra argument(s)" << endl;	}							
							if(sl.searchByBnum(tokens[1]).compare("") == 0){
								cout << "Fail: cannot add student as student does not exist" << endl;
								continue;							
							}
							if(cl.searchByCRN(tokens[2]).compare("") != 0){
								//Roster rr = cl.getcourse((cl.geti(tokens[2]))).getr(); //rr.search(tokens[1]).compare(tokens[1]) == 0
								if(cl.getcourse(cl.geti(tokens[2])).check(tokens[1])) {
									cout << "Fail: cannot add, student " << tokens[1] << " already enrolled into course " << tokens[2] << endl;
								} else {
									//cout << rr.search(tokens[1]) << endl; //debugging: not printing out the string			
									cl.getcourse((cl.geti(tokens[2]))).addr(tokens[1]);
									cout << "Success: added student " << tokens[1] << " into course " << tokens[2] << endl;
								}
							} else {
								cout << "Fail: cannot add student as course does not exist" << endl;
								continue;							
							}
					} else {
						cout << "Input Error: illegal CRN" << endl;					
					}
				} else {
					cout << "Input Error: illegal B Number" << endl;			
				}
			} else {
				cout << "Input Error: too few arguments" << endl;
			}
		} else if(tokens[0].compare("drop") == 0){
			if(tokens.size() >= 3){
				if(regex_match(tokens[1], regex("B[0-9]{8}"))){
					if(regex_match(tokens[2], regex("[0-9]{6}"))){
							if(tokens.size() > 3){ cout << "Warning: ignoring extra argument(s)" << endl;	}							
							if(sl.searchByBnum(tokens[1]).compare("") == 0){
								cout << "Fail: cannot remove student as student does not exist" << endl;
								continue;							
							}
							if(cl.searchByCRN(tokens[2]).compare("") != 0){
								if(cl.getcourse(cl.geti(tokens[2])).check(tokens[1])) {
									cl.getcourse((cl.geti(tokens[2]))).dropr(tokens[1]);
									cout << "Success: removed student " << tokens[1] << " from course " << tokens[2] << endl;
								} else {
									cout << "Fail: cannot drop, student " << tokens[1] << " not enrolled in course " << tokens[2] << endl;
								}
							} else {
								cout << "Fail: cannot remove student as course does not exist" << endl;
								continue;							
							}
					} else {
						cout << "Input Error: illegal CRN" << endl;					
					}
				} else {
					cout << "Input Error: illegal B Number" << endl;			
				}
			} else {
				cout << "Input Error: too few arguments" << endl;
			}
		} else if(tokens[0].compare("roster") == 0){
			if(tokens.size() >= 2){
				if(regex_match(tokens[1], regex("[0-9]{6}"))){
							if(tokens.size() > 2){ cout << "Warning: ignoring extra argument(s)" << endl;	}							
							if(cl.searchByCRN(tokens[1]).compare("") != 0){
								
								cout << "CRN: " << tokens[1] << endl;								
								cout << "Students: " << cl.getcourse(cl.geti(tokens[1])).getq() << endl;

								for(int k = 0; k < cl.getcourse(cl.geti(tokens[1])).getq(); k++){
									cout << cl.getcourse(cl.geti(tokens[1])).getstu(k) << " " << sl.rfirstlast(cl.getcourse(cl.geti(tokens[1])).getstu(k)) << endl;				
								}
								
								
							} else {
								cout << "Fail: cannot display roster as course does not exist" << endl;
								continue;							
							}
				} else {
					cout << "Input Error: illegal CRN" << endl;			
				}
			} else {
				cout << "Input Error: too few arguments" << endl;
			}
		} else if(tokens[0].compare("schedule") == 0){
			if(tokens.size() >= 2){
				if(regex_match(tokens[1], regex("B[0-9]{8}"))){
							if(tokens.size() > 2){ cout << "Warning: ignoring extra argument(s)" << endl;	}							
							if(sl.searchByBnum(tokens[1]).compare("") != 0){
								
								cout << "Student: " << tokens[1] << ": " << sl.rfirstlast(tokens[1]) << endl;
								for(int k = 0; k < cl.getq(); k++){
									for(int g = 0; g < cl.getcourse(k).getq(); g++){
										if(cl.getcourse(k).getstu(g).compare(tokens[1]) == 0){
											cout << cl.getcourse(k).getCRN() << " " << cl.getcourse(k).getdepartment() << " " << cl.getcourse(k).getnumber() << " " << cl.getcourse(k).getname() << endl;
										}						
									}								
								}
								
								
							} else {
								cout << "Fail: cannot display schedule as student does not exist" << endl;
								continue;							
							}
				} else {
					cout << "Input Error: illegal B Number" << endl;			
				}
			} else {
				cout << "Input Error: too few arguments" << endl;
			}
		} else if(tokens[0].compare("quit") == 0){
			exit = 0;			
		} else {
			cout << "Command not recognized, please try again." << endl;
		}
	}
}