#include "database.h"
#include <algorithm>
#include <string>

using namespace std;

Database::Database()
{
	// empty constructor
}

void Database::Add(const Date& date, const string& event)
{
	auto &events = database[date];
	if (count(events.begin(), events.end(), event) == 0){
		events.push_back(event);
	}
}

string Database::Last(Date date)
{
	ostringstream os;
	auto upper_bound_date = database.upper_bound(date);
	if (upper_bound_date == database.begin()){
		os << "No entries" << endl;
	} else {
		const auto &res_date = prev(upper_bound_date);
		const auto &event = (res_date->second)[res_date->second.size() - 1]; 
		os << res_date->first << " " << event;
	}
	return os.str();
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
vector<pair<Date, string>> Database::FindIf(function<bool(const Date &date, const string &event)> predicate) const
{
	vector<pair<Date, string>> res;
	for (const auto &record : database){
		for (const auto &event : record.second){
			if (predicate(record.first, event)){
				res.push_back(make_pair(record.first, event));
			}
		}
	}
	return res;
}

int Database::RemoveIf(function<bool(const Date &date, const string &event)> predicate)
{
	int res = 0;
	for (auto &record: database){
		auto &_date = record.first;
		auto &_events = record.second;
		auto remove_it = remove_if(_events.begin(), _events.end(), [_date, predicate](const string &e){return predicate(_date, e);});
		res += _events.end() - remove_it;
		_events.erase(remove_it, _events.end());
	}
	return res;
}

ostream& operator<<(ostream &stream, pair<Date, string> event)
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



