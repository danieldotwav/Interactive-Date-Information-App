#ifndef DATE_H
#define DATE_H

#include <iostream>


class Date {
	// Overload stream insertion and stream extraction operators
	// Allow user to enter date in the following format:
	// MM / DD / YYYY

	// stream insertion overload
	friend std::ostream& operator<<(std::ostream& , Date& );
	//stream extraction overload
	friend std::istream& operator>>(std::istream& , Date& );
	friend std::istream& operator>>(std::istream& , Date& );

private:
	int month;
	int day;
	int year;
	std::string name;
	std::string firstName;
	std::string lastName;
	std::string horoscope;
	std::string monthName;
	std::string zodiac;

public:
	Date(); //default constructor
	void setName();
	void setMonthName();
	void setHoroscope();
	void setLunarYear();
};




#endif
