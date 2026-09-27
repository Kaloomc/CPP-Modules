#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include <cctype>

class RPN {
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		int evaluate(const std::string &expr);

	private:
		std::stack<int> _stack;
};

#endif
