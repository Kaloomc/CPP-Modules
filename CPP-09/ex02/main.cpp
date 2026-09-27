#include <iostream>
#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	// TODO: parse positive ints (error on negative / non-numeric), fill vector + deque,
	//       print Before/After, time each sort (both must include data management)
	(void)av;
	return 0;
}
