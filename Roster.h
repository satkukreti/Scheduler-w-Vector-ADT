#include <iostream>
#include <stdlib.h>
using namespace std;

class Roster{
	public:
  		Roster();
  		~Roster();
  		int getsize();
  		string search(string s);
  		void addstring(string s);
  		void removestring(string s);
  		int getquantity();
  		
  		string getstudent(int i);

 	private:
 		int capacity;
 		int quantity;
  		string *str;

};
