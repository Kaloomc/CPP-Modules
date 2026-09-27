#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &)
{
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sortVector(std::vector<int> &)
{
	// TODO: Ford-Johnson on std::vector
}

void PmergeMe::sortDeque(std::deque<int> &)
{
	// TODO: Ford-Johnson on std::deque
}
