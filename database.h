#pragma once

#include <iostream>
#include <memory>
#include <map>
#include <unordered_set>
#include <string>
#include <functional>
#include <vector>
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
	vector<pair<Date, string>> FindIf(function<bool(const Date &date, const string &event)>) const;
	pair<const Date, string> Last(Date date);
private:
	map<Date, unordered_set<string>> database;
};
