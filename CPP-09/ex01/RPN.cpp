#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &) {}

RPN &RPN::operator=(const RPN &)
{
	return *this;
}

RPN::~RPN() {}

int RPN::evaluate(const std::string &expr)
{
	// TODO: tokenize, push digits, apply operators, throw on error
	
	std::stack<int> stack;
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
				stack.push(c - '0');
			}
			else if(c == '+' || c == '-' || c == '*' || c == '/')
			{
				if(stack.size() < 2)
					throw std::runtime_error("Error");
				int x = stack.top();
				stack.pop();
				int y = stack.top();
				stack.pop();
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
				stack.push(res);
			}
			else
				throw std::runtime_error("Error");
		}
	}
	if(stack.size() != 1)
		throw std::runtime_error("Error");
	int result = stack.top();
	stack.pop();
	return result;
}
