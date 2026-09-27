#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN() {}

int RPN::evaluate(const std::string &expr)
{
	// TODO: tokenize, push digits, apply operators, throw on error
	
	std::istringstream stream(expr);

	char c;

	while(stream)
	{
		stream >> c;
		if(stream)
		{
			if(std::isdigit(c))
			{
				if(std::isdigit(stream.peek()))
					throw std::runtime_error("Error");
				_stack.push(c - '0');
			}
			else if(c == '+' || c == '-' || c == '*' || c == '/')
			{
				if(_stack.size() < 2)
					throw std::runtime_error("Error");
				int x = _stack.top();
				_stack.pop();
				int y = _stack.top();
				_stack.pop();
				int res;
				if(c == '+')
					res = y + x;
				else if(c == '-')
					res = y - x;
				else if(c == '*')
					res = y * x;
				else
				{
					if(x == 0)
						throw std::runtime_error("Error");
					res = y / x;
				}
				_stack.push(res);
			}
			else
				throw std::runtime_error("Error");
		}
	}
	if(_stack.size() != 1)
		throw std::runtime_error("Error");
	int result = _stack.top();
	_stack.pop();
	return result;
}
