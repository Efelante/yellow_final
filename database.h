#pragma once

#include <iostream>
#include <memory>
#include <map>
#include <set>
#include <string>
#include <functional>
#include <utility>

#include "node.h"
#include "date.h"

using namespace std;

ostream& operator<<(ostream &stream, pair<Date, string> event);

class Database {
public:
	Database();
	void Add(const Date &date, const string &event);
	void Print(ostream &out) const;
	int RemoveIf(function<bool(const Date &date, const string &event)>);
	map<Date, set<string>> FindIf(function<bool(const Date &date, const string &event)>) const;
	pair<const Date, string> Last(Date date);
private:
	map<Date, set<string>> database;
};
