#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>
#include <utility>

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void sortVector(std::vector<int> &data);
		void sortDeque(std::deque<int> &data);

	private:
		template <typename C>
		void fordJohnson(C &data);
};

#endif
