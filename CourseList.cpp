#include "CourseList.h"
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

	CourseList::CourseList(){
		capacity = 1;
		quantity = 0;
		cList = new Course[capacity];
	}
	
	CourseList::~CourseList(){
		delete []cList;	
	}
	
	int CourseList::getsize(){
		return capacity;	
	}
	
	int CourseList::getq(){
		return quantity;	
	}
	
	Course CourseList::getcourse(int i){
		return cList[i];	
	}	
	
	int CourseList::geti(string nCRN){
		for(int i = 0; i < quantity; i++){
			if(cList[i].getCRN().compare(nCRN) == 0){
				return i;
			}
		}
		return -1;
	}	
	
	string CourseList::searchByCRN(string nCRN){
		for(int i = 0; i < quantity; i++){
			if(cList[i].getCRN().compare(nCRN) == 0){
				return cList[i].getCRN();
			}
		}
		return "";
	}
	
	void CourseList::addCourse(Course nCourse){	
		if(quantity == capacity){ //change this condition on resizing
			//resize and deep copy of array
			capacity *= 2;
			Course *temp = new Course[capacity];
			for(int i = 0; i < quantity; i++){
				temp[i] = cList[i];			
			}

			delete [] cList;
			cList = new Course[capacity];
			copy(temp, temp+capacity, cList);
			
			delete [] temp;
		}
		
		cList[quantity] = nCourse;
		quantity++;
	}
	
	void CourseList::removeCourse(string nCRN){
		int pos = 0;	
		for(int i = 0; i < quantity; i++){
			if((cList[i].getCRN().compare(nCRN)) == 0){
				pos = i;
				break;
			}
		}
		
		Course *temp = new Course[capacity];
		if(pos < quantity){
			for(int i = 0; i < pos; i++){
				temp[i] = cList[i];			
			}
			for(int i = pos+1; i < quantity; i++){
				temp[i] = cList[i];		
			}
		} else {
			for(int i = 0; i < pos; i++){
				temp[i] = cList[i];			
			}
		}
		
		delete [] cList;
		cList = new Course[capacity];
		copy(temp, temp+capacity, cList);
			
		delete [] temp;
		quantity--;
		
	}
	
	