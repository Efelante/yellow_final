#include "node.h"

bool EmptyNode::Evaluate(const Date &date, const string &event) const
{
	return true;	
}

DateComparisonNode::DateComparisonNode(Comparison op, Date date): 
	_op(op), _date(date)
{

}

bool DateComparisonNode::Evaluate(const Date &date, const string &event) const
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

EventComparisonNode::EventComparisonNode(Comparison op, const string &event): 
	_op(op), _event(event)
{

}
bool EventComparisonNode::Evaluate(const Date &date, const string &event) const
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

LogicalOperationNode::LogicalOperationNode(LogicalOperation op, 
										   shared_ptr<Node> left, 
										   shared_ptr<Node> right):
	_op(op), _left(left), _right(right)
{

}

bool LogicalOperationNode::Evaluate(const Date &date, const string &event) const
{
	if (_op == LogicalOperation::Or){
		return (_left->Evaluate(date, event) || _right->Evaluate(date, event));
	} else {
		return (_left->Evaluate(date, event) && _right->Evaluate(date, event));
	}
}
