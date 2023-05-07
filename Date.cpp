#include "Date.h"
#include <iomanip>
#include <string>
using namespace std;

Date::Date() {
	month = 0;
	day = 0;
	year = 0;
    name = "";
	monthName = "";
}

ostream& operator<<(ostream& output, Date& date) {
	const int w = 12;
	int monthNum = date.month;

	output << "You entered:\n\n";
	output << "Name:           " << setw(w) << date.name << endl;
	output << "Month:          " << setw(w) << date.monthName << endl;
	output << "Day:            " << setw(w) << date.day << endl;
	output << "Year:           " << setw(w) << date.year << endl;
	output << "Horoscope:      " << setw(w) << date.horoscope << endl;
	output << "Lunar Year:     " << setw(w) << date.zodiac << endl;

	return output;
}

// Overloaded Operator for Birthdate
istream& operator>>(istream& input, Date& date) {
	char ch{}; // empty char
	bool invMonth, invDay, invYear;

	do {
		invMonth = invDay = invYear = false; // used for input validation
		cout << "Enter a birth date using the folowing format: MM/DD/YYYY\n";
    
		input >> date.month;
		input >> ch; // skip the /
    
		input >> date.day;
		input >> ch; // skip the second /
		input >> date.year;

		cout << endl;
		if (date.month <= 0 || date.month > 12) {
			invMonth = true;
			cout << "INVALID MONTH\n";
		}
		if( (date.day <= 0) || (date.day > 31) || (date.month == 2 && date.day > 28) ) {
			invDay = true;
			cout << "INVALID DAY\n";
		}
		if (date.year < 0) {
			invYear = true;
			cout << "INVALID YEAR (must be the year of, or any year after, the birth of our lord and savior)\n";
		}
		cout << endl;

	} while (invMonth || invDay || invYear);

	return input;
}


void Date::setName() {
	string fName{ "" };
	string lName{ "" };

	cout << "Enter a name: ";
	getline(cin, name, '\n');
	
	while(name.length() > 50) {
		cout << "Name exceeds maximum length\n";
		cout << "Enter a reasonably sized name\n";
		cin >> name;
	}
	//cin.clear();
	//cin.ignore(255,'\n');
}

void Date::setMonthName() {

	// determine the month
	switch (month) {
		case 1:
			monthName = "January";
			break;
		case 2:
			monthName = "February";
			break;
		case 3:
			monthName = "March";
			break;
		case 4:
			monthName = "April";
			break;
		case 5:
			monthName = "May";
			break;
		case 6:
			monthName = "June";
			break;
		case 7:
			monthName = "July";
			break;
		case 8:
			monthName = "August";
			break;
		case 9:
			monthName = "September";
			break;
		case 10:
			monthName = "October";
			break;
		case 11:
			monthName = "November";
			break;
		case 12:
			monthName = "December";
			break;
	}
}

void Date::setHoroscope() {
	// According to Wikipedia...
	// Aries: March 21 - April 20 
	// Taurus: April 20 - May 21
	// Gemini: May 21 - June 21
	// Cancer: June 21 - July 22
	// Leo: July 23 - August 22
	// Virgo: August 23 - September 22
	// Libra: September 23 - October 22
	// Scorpio: October 23 - November 22
	// Sagitarius: November 23 - December 22
	// Capricorn: December 23 - January 20
	// Aquarius: January 21 - Feburary 19
	// Pisces: February 20 - March 20
	
	// What we have: the day the month and the year
	// create cutoffs using conditional statements
	// month will always equal a fixed integer - january well always be 1, feb 2, etc
  // NOTE: Convert month and day to days first and then use the 365-days year for cutoff

	if ( (month == 3) && (day >= 21) || (month == 4) && (day < 20) ) {
		horoscope = "Aries";
	}
	else if ( (month == 4) && (day >= 20) || (month == 5) && (day < 21) ) {
		horoscope = "Taurus";
	}
	else if ( (month == 5) && (day >= 21) || (month == 6) && (day < 21) ) {
		horoscope = "Gemini";
	}
	else if ( (month == 6) && (day >= 21) || (month == 7) && (day < 23) ) {
		horoscope = "Cancer";
	}
	else if ( (month == 7) && (day >= 23) || (month == 8) && (day < 23) ) {
		horoscope = "Leo";
	}
	else if ( (month == 8) && (day >= 23) || (month == 9) && (day < 23) ) {
		horoscope = "Virgo";
	}
	else if ( (month == 9) && (day >= 23) || (month == 10) && (day < 23) ) {
		horoscope = "Libra";
	}
	else if ( (month == 10) && (day >= 23) || (month == 11) && (day < 23) ) {
		horoscope = "Scorpio";
	}
	else if ( (month == 11) && (day >= 23) || (month == 12) && (day < 23) ) {
		horoscope = "Sagittarius";
	}
	else if ( (month == 12) && (day >= 23) || (month == 1) && (day < 21) ) {
		horoscope = "Capricorn";
	}
	else if ( (month == 1) && (day >= 21) || (month == 2) && (day < 20) ) {
		horoscope = "Aquarius";
	}
	else if ( (month == 2) && (day >= 20) || (month == 3) && (day < 20) ) {
		horoscope = "Pisces";
	}
}

void Date::setLunarYear() {
	// Chinese Zodiac Signs
	// Rat: ...1948, 1960, 1972 (+12)
	// Ox: ...1949, 1961, 1973 (+12)

	int remainder = (year - 8) % 12;
	
	switch (remainder) {
		case 0: // no remainder
			zodiac = "Dragon";
			break;
		case 1: // remainder of 1
			zodiac = "Snake";
			break;
		case 2:
			zodiac = "Horse";
			break;
		case 3:
			zodiac = "Goat";
			break;
		case 4:
			zodiac = "Monkey";
			break;
		case 5:
			zodiac = "Rooster";
			break;
		case 6:
			zodiac = "Dog";
			break;
		case 7:
			zodiac = "Pig";
			break;
		case 8:
			zodiac = "Rat";
			break;
		case 9:
			zodiac = "Ox";
			break;
		case 10:
			zodiac = "Tiger";
			break;
		case 11:
			zodiac = "Rabbit";
			break;
	}
}


