#include "database.h"

Database::Database()
{
	// empty constructor
}

void Database::Add(const Date& date, const string& event)
{
	database[date].insert(event);
}

void Database::Print(ostream &out) const
{
	for (const auto &record : database){
		for (const auto &event : record.second){
			out << record.first << " " << 
				event << 
				endl;
		}
	}
}

ostream& operator<<(ostream &stream, const pair<const Date, string> &event)
{
	stream << event.first << " " << event.second;
	return stream;
}

//bool DeleteEvent(const Date& date, const string& event)
//{
//	if (database.count(date) > 0){
//		if (database[date].count(event) > 0){
//			database[date].erase(event);
//			return true; 
//		} else {
//			return false;
//		}
//	} else {
//		// No events at this date
//		return false;
//	}
//}
//int  DeleteDate(const Date& date){
//	int res = 0;
//	if (database.count(date) > 0){
//		res = database[date].size();
//		database[date].clear();
//	} else {
//		// No such a date. Return 0
//	}
//	return res;
//}
//
//set<string> Find(const Date& date) const
//{
//	if (database.count(date) > 0){
//		return database.at(date);
//	} else {
//		// No events at this date
//		return {};	
//	}
//}



