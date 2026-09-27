#include <iostream>
#include <exception>
#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	try {
		RPN rpn;
		std::cout << rpn.evaluate(av[1]) << std::endl;
	} catch (const std::exception &) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	return 0;
}
