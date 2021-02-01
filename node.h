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
		Date d1;
		Date d2;
		return d1 == d2;
	}
};

class EmptyNode: public Node
{
public:
	bool Evaluate(const Date &date, const string &event) const override
	{
		return true;	
	}

};

class DateComparisonNode: public Node
{
public:
	DateComparisonNode(Comparison op, Date date): _op(op), _date(date)
	{

	}
	bool Evaluate(const Date &date, const string &event) const override
	{
		if (_op == Comparison::Less){
			return date < _date;
		} else if (_op == Comparison::LessOrEqual){
			return date <= _date;
		} else if (_op == Comparison::Greater){
			return date > _date;
		} else if (_op == Comparison::GreaterOrEqual){
			return date >= _date;
		} else if (_op == Comparison::Equal){
			return date == _date;
		} else {
			return _date != date;
		}
	}
private:
	Comparison _op;
	const Date _date;
};

class EventComparisonNode: public Node
{
public:
	EventComparisonNode(Comparison op, const string &event): _op(op), _event(event)
	{

	}
	bool Evaluate(const Date &date, const string &event) const override
	{
		if (_op == Comparison::Less){
			return event < _event;
		} else if (_op == Comparison::LessOrEqual){
			return event <= _event;
		} else if (_op == Comparison::Greater){
			return event > _event;
		} else if (_op == Comparison::GreaterOrEqual){
			return event >= _event;
		} else if (_op == Comparison::Equal){
			return event == _event;
		} else {
			return _event != event;
		}
		return true;	
	}
private:
	Comparison _op;
	const string _event;
};

class LogicalOperationNode: public Node
{
public:
	LogicalOperationNode(LogicalOperation op, shared_ptr<Node> left, shared_ptr<Node> right):
		_op(op), _left(left), _right(right)
	{

	}
	bool Evaluate(const Date &date, const string &event) const override
	{
		if (_op == LogicalOperation::Or){
			return (_left->Evaluate(date, event) || _right->Evaluate(date, event));
		} else {
			return (_left->Evaluate(date, event) && _right->Evaluate(date, event));
		}
	}
private:
	LogicalOperation _op;
	shared_ptr<Node> _left;
	shared_ptr<Node> _right;
};
