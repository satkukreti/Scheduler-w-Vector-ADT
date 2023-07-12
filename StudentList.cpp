#include "StudentList.h"
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

	StudentList::StudentList(){
		capacity = 1;
		quantity = 0;
		sList = new Student[capacity];
	}
	
	StudentList::~StudentList(){
		delete [] sList;	
	}
	
	int StudentList::getsize(){
		return capacity;	
	}

	string StudentList::rfirstlast(string nBNUM){
		for(int i = 0; i < quantity; i++){
			if(sList[i].getbnum().compare(nBNUM) == 0){
				string toReturn = sList[i].getfirst() + " " + sList[i].getlast();			
				return toReturn;
			}
		}
		return "";
	}

	string StudentList::searchByBnum(string nBNUM){
		for(int i = 0; i < quantity; i++){
			if(sList[i].getbnum().compare(nBNUM) == 0){
				return sList[i].getbnum();
			}
		}
		return "";
	}
	
	void StudentList::addStudent(Student nS){	
		if(quantity == capacity){ //change this condition on resizing
			//resize and deep copy of array
			capacity *= 2;
			Student *temp = new Student[capacity];
			for(int i = 0; i < quantity; i++){
				temp[i] = sList[i];			
			}

			delete [] sList;
			sList = new Student[capacity];
			copy(temp, temp+capacity, sList);
			
			delete [] temp;
		}
		
		sList[quantity] = nS;
		quantity++;
	}
	
	void StudentList::removeStudent(string nBNUM){
		int pos = 0;	
		for(int i = 0; i < quantity; i++){
			if((sList[i].getbnum().compare(nBNUM)) == 0){
				pos = i;
				break;
			}
		}
		
		Student *temp = new Student[capacity];
		if(pos < quantity){
			for(int i = 0; i < pos; i++){
				temp[i] = sList[i];			
			}
			for(int i = pos+1; i < quantity; i++){
				temp[i] = sList[i];		
			}
		} else {
			for(int i = 0; i < pos; i++){
				temp[i] = sList[i];			
			}
		}
		
		delete [] sList;
		sList = new Student[capacity];
		copy(temp, temp+capacity, sList);
			
		delete [] temp;
		quantity--;
		
	}
	
	