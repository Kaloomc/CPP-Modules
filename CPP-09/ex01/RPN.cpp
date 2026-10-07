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
	std::stack<int, std::list<int> > stack;
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
				long x = stack.top();
				stack.pop();
				long y = stack.top();
				stack.pop();
				long res;
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
				if (res > INT_MAX || res < INT_MIN)
					throw std::runtime_error("Error");
				stack.push(static_cast<int>(res));
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
