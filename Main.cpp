// This program allows user to enter a birth date in the format MM / DD / YYYY
// The program lists the birth month by name, the day and year, along with the corresponding zodiac sign

#include <iostream>
#include <iomanip>
#include "Date.h"

using namespace std;


int main() {

	// Create an object of the Date class
	Date date;
	// Loop control variable
	int choice{ 1 }; 
  
	while(choice == 1){
		date.setName();
		cin >> date; // implicitly calls overloaded operator>>
		date.setMonthName();
		date.setHoroscope();
		date.setLunarYear();
		cout << date; // implicitly calls operator<<

		cout << "\n\nWould you like to run again?\n";
		cout << "Enter 1 for YES, 2 to exit\n";
		cin >> choice;
		cout << endl;
	}
	

	cout << "Exiting Program...\n";
	cout << "*sad computer noises*" << endl;

	return 0;
}