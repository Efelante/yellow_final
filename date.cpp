#include <iomanip>

#include "date.h"

using namespace std;

bool operator<(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() != rhs.GetYear()){
		return lhs.GetYear() < rhs.GetYear();
	} else if (lhs.GetMonth() != rhs.GetMonth()){
		return lhs.GetMonth() < rhs.GetMonth();
	} else {
		return lhs.GetDay() < rhs.GetDay();
	} 
}

bool operator==(const Date& lhs, const Date& rhs)
{
	return (lhs.GetYear() == rhs.GetYear() &&
			lhs.GetMonth() == rhs.GetMonth() &&
			lhs.GetDay() == rhs.GetDay());
}

bool operator!=(const Date& lhs, const Date& rhs)
{
	return (!(lhs == rhs));
}

bool operator<=(const Date& lhs, const Date& rhs)
{
	return ((lhs < rhs) || (lhs == rhs));
}

bool operator>(const Date& lhs, const Date& rhs)
{
	return (!(lhs <= rhs));
}

bool operator>=(const Date& lhs, const Date& rhs)
{
	return ((lhs > rhs) || (lhs == rhs));
}

istream& operator>>(istream &stream, Date &date)
{
	int year;
	int month;
	int day;
	stream >> year;
	stream.ignore(1);
	stream >> month;
	stream.ignore(1);
	stream >> day;
	date = Date(Year(year), Month(month), Day(day));
	return stream;
}

ostream& operator<<(ostream &stream, const Date &date)
{
	char delimeter = '-';
	stream << setfill('0') << setw(4) << date.GetYear();
	stream << delimeter;
	stream << setfill('0') << setw(2) << date.GetMonth();
	stream << delimeter;
	stream << setfill('0') << setw(2) << date.GetDay();
	return stream;
}

void CheckDelimeterAndSkip(istream &stream)
{
	if (stream.peek() != '-'){
		throw runtime_error("Wrong date format: ");
	} else {
		stream.ignore(1);
	}
}

void CheckMonth(int month)
{
	if (month < 1 || month > 12){
		throw runtime_error("Month value is invalid: " + to_string(month));
	} else {
		// Do nothing
	}
}

void CheckDay(int day)
{
	if (day < 1 || day > 31){
		throw runtime_error("Day value is invalid: " + to_string(day));
	} else {
		// Do nothing
	}
}

Date ParseDate(istream &date_stream)
{
	int year;
	int month;
	int day;
	string date_string;
	date_stream >> date_string;
	istringstream is(date_string);
	if (is >> year){
		// Year is a number
		// Read month and day
		try {
			CheckDelimeterAndSkip(is);
		} catch (exception &e) {
			throw runtime_error("Wrong date format: " + date_string);
		}
		if (is >> month){
			// Month is a number
			// Read the day
			try {
				CheckDelimeterAndSkip(is);
			} catch (exception &e) {
				throw runtime_error("Wrong date format: " + date_string);
			}
			if (is >> day){
					if(!is.eof() && is.peek() != ' '){
							throw runtime_error("Wrong date format: " + date_string);
					} else {
							is.ignore(1);
							CheckMonth(month);
							CheckDay(day);
							return Date(Year(year),
											Month(month),
											Day(day));
					}
			} else {
				// Not a day
				throw runtime_error("Wrong date format: " + date_string);
			}
		} else {
			// Not a month
			throw runtime_error("Wrong date format: " + date_string);
		}
	} else {
		// Not a year
		throw runtime_error("Wrong date format: " + date_string);
	}

}
