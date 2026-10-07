#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <ctime>
#include "PmergeMe.hpp"

static bool parseArg(const char *str, int &out)
{
	if (!str || !*str)
		return false;
	for (int i = 0; str[i]; i++)
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return false;
	char *end;
	long val = std::strtol(str, &end, 10);
	if (*end || val <= 0 || val > INT_MAX)
		return false;
	out = static_cast<int>(val);
	return true;
}

template <typename T>
static void print(const std::string &label, const T &c)
{
	std::cout << label;
	for (typename T::const_iterator it = c.begin(); it != c.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

int main(int ac, char **av)
{
	if (ac < 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::vector<int> input;
	for (int i = 1; i < ac; i++) {
		int n;
		if (!parseArg(av[i], n)) {
			std::cerr << "Error" << std::endl;
			return 1;
		}
		input.push_back(n);
	}

	PmergeMe sorter;

	// le temps inclut le remplissage du container + le tri
	std::clock_t start = std::clock();
	std::vector<int> vec;
	for (int i = 1; i < ac; i++)
		vec.push_back(static_cast<int>(std::strtol(av[i], NULL, 10)));
	sorter.sortVector(vec);
	double vecTime = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC * 1000000;

	start = std::clock();
	std::deque<int> deq;
	for (int i = 1; i < ac; i++)
		deq.push_back(static_cast<int>(std::strtol(av[i], NULL, 10)));
	sorter.sortDeque(deq);
	double deqTime = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC * 1000000;

	print("Before:", input);
	print("After: ", vec);
	std::cout << "Time to process a range of " << input.size()
			  << " elements with std::vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << input.size()
			  << " elements with std::deque  : " << deqTime << " us" << std::endl;
	return 0;
}
