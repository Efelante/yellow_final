#pragma once

#include <memory>
#include "date.h"

using namespace std;

enum class Comparison {
		Less,
		LessOrEqual,
		Greater,
		GreaterOrEqual,
		Equal,
		NotEqual
};

enum class LogicalOperation {
		Or,
		And
};

class Node {
public:
	virtual bool Evaluate(const Date &date, const string &event) const
	{
		return true;
	}
};

class EmptyNode: public Node
{
public:
	bool Evaluate(const Date &date, const string &event) const override;
};

class DateComparisonNode: public Node
{
public:
	DateComparisonNode(Comparison op, Date date);
	bool Evaluate(const Date &date, const string &event) const override;
private:
	Comparison _op;
	const Date _date;
};

class EventComparisonNode: public Node
{
public:
	EventComparisonNode(Comparison op, const string &event);
	bool Evaluate(const Date &date, const string &event) const override;
private:
	Comparison _op;
	const string _event;
};

class LogicalOperationNode: public Node
{
public:
	LogicalOperationNode(LogicalOperation op, shared_ptr<Node> left, shared_ptr<Node> right);
	bool Evaluate(const Date &date, const string &event) const override;
private:
	LogicalOperation _op;
	shared_ptr<Node> _left;
	shared_ptr<Node> _right;
};
