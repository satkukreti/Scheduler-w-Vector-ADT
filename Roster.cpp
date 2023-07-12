#include "Roster.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

	Roster::Roster(){
		capacity = 1;
		quantity = 0;	  	
	  	str = new string[capacity];
	}
	
	Roster::~Roster(){
		delete [] str;	
	}
	
	int Roster::getsize(){
		return capacity;	
	}
	
	int Roster::getquantity(){
		return quantity;	
	}

	string Roster::search(string s){
		for(int i = 0; i < quantity; i++){
			if(str[i].compare(s) == 0){
				return str[i];
			}
		}
		return "";
	}
	
	string Roster::getstudent(int i){
		return str[i];
	}	
	
	void Roster::addstring(string s){	
		if(quantity == capacity){ //change this condition on resizing
			//resize and deep copy of array
			capacity *= 2;
			string *temp = new string[capacity];
			for(int i = 0; i < quantity; i++){
				temp[i] = str[i];			
			}

			delete [] str;
			str = new string[capacity];
			copy(temp, temp+capacity, str);
			
			delete [] temp;
		}
		
		str[quantity] = s;
		quantity++;
	}
	
	void Roster::removestring(string s){
		int pos = 0;	
		for(int i = 0; i < quantity; i++){
			if((str[i].compare(s)) == 0){
				pos = i;
				break;
			}
		}
		
		string *temp = new string[capacity];
		if(pos < quantity){
			for(int i = 0; i < pos; i++){
				temp[i] = str[i];			
			}
			for(int i = pos+1; i < quantity; i++){
				temp[i] = str[i];		
			}
		} else {
			for(int i = 0; i < pos; i++){
				temp[i] = str[i];			
			}
		}
		
		delete [] str;
		str = new string[capacity];
		copy(temp, temp+capacity, str);
			
		delete [] temp;
		quantity--;
	}
	