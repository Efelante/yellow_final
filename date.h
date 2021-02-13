#pragma once

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

struct Year {
	Year(int new_year){
		value = new_year;
	}
	int value;
};

struct Month {
	Month(int new_month){
		value = new_month;
	}
	int value;
};

struct Day {
	Day(int new_day){
		value = new_day;
	}
	int value;
};

class Date {
public:
	Date(){}
	Date(const Year& new_year, 
	     const Month& new_month, 
	     const Day& new_day){
		year = new_year.value;	
		month = new_month.value;
		day = new_day.value;
	}
	//Date (int new_year, int new_month, int new_day){
	//	year = new_year;	
	//	month = new_month;
	//	day = new_day;
	//}
	int GetYear() const {return year;};
	int GetMonth() const {return month;};
	int GetDay() const {return day;};
private:
	int year;
	int month;
	int day;
};

bool operator<(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
istream& operator>>(istream &stream, Date &date);
ostream& operator<<(ostream &stream, const Date &date);
Date ParseDate(istream &is);
