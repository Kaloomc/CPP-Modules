#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <cstddef>

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		static void sortVector(std::vector<int> &data);
		static void sortDeque(std::deque<int> &data);

	private:
		static void sortIndexesVector(const std::vector<int> &vals, std::vector<size_t> &idx);
		static size_t searchVector(const std::vector<int> &vals, const std::vector<size_t> &chain,
			int value, size_t hi);

		static void sortIndexesDeque(const std::deque<int> &vals, std::deque<size_t> &idx);
		static size_t searchDeque(const std::deque<int> &vals, const std::deque<size_t> &chain,
			int value, size_t hi);
};

#endif
