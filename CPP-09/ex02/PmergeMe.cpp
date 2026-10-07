#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &)
{
	return *this;
}

PmergeMe::~PmergeMe() {}

size_t PmergeMe::searchVector(const std::vector<int> &vals, const std::vector<size_t> &chain,
	int value, size_t hi)
{
	size_t lo = 0;
	while (lo < hi) {
		size_t mid = lo + (hi - lo) / 2;
		if (vals[chain[mid]] < value)
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
}

void PmergeMe::sortIndexesVector(const std::vector<int> &vals, std::vector<size_t> &idx)
{
	if (idx.size() <= 1)
		return;

	std::vector<size_t> bigs;
	std::vector<size_t> smallOf(vals.size());
	for (size_t i = 0; i + 1 < idx.size(); i += 2) {
		size_t a = idx[i];
		size_t b = idx[i + 1];
		if (vals[a] < vals[b]) {
			size_t tmp = a;
			a = b;
			b = tmp;
		}
		bigs.push_back(a);
		smallOf[a] = b;
	}
	bool hasStraggler = (idx.size() % 2 != 0);
	size_t straggler = idx.back();

	sortIndexesVector(vals, bigs);

	std::vector<size_t> pend;
	for (size_t k = 0; k < bigs.size(); k++)
		pend.push_back(smallOf[bigs[k]]);
	if (hasStraggler)
		pend.push_back(straggler);

	std::vector<size_t> chain;
	chain.push_back(pend[0]);
	chain.insert(chain.end(), bigs.begin(), bigs.end());

	size_t prev = 1;
	size_t jPrev = 1;
	size_t jCur = 3;
	while (prev < pend.size()) {
		size_t end = (jCur < pend.size()) ? jCur : pend.size();
		std::vector<size_t> inserted;
		for (size_t k = end; k > prev; k--) {
			size_t bound = chain.size();
			if (k - 1 < bigs.size()) {
				bound = prev + k - 1;
				for (size_t i = 0; i < inserted.size(); i++)
					if (inserted[i] <= bound)
						bound++;
			}
			size_t p = searchVector(vals, chain, vals[pend[k - 1]], bound);
			chain.insert(chain.begin() + p, pend[k - 1]);
			inserted.push_back(p);
		}
		prev = end;
		size_t next = jCur + 2 * jPrev;
		jPrev = jCur;
		jCur = next;
	}

	idx = chain;
}

void PmergeMe::sortVector(std::vector<int> &data)
{
	std::vector<size_t> idx;
	for (size_t i = 0; i < data.size(); i++)
		idx.push_back(i);
	sortIndexesVector(data, idx);

	std::vector<int> sorted;
	for (size_t i = 0; i < idx.size(); i++)
		sorted.push_back(data[idx[i]]);
	data = sorted;
}

size_t PmergeMe::searchDeque(const std::deque<int> &vals, const std::deque<size_t> &chain,
	int value, size_t hi)
{
	size_t lo = 0;
	while (lo < hi) {
		size_t mid = lo + (hi - lo) / 2;
		if (vals[chain[mid]] < value)
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
}

void PmergeMe::sortIndexesDeque(const std::deque<int> &vals, std::deque<size_t> &idx)
{
	if (idx.size() <= 1)
		return;

	std::deque<size_t> bigs;
	std::deque<size_t> smallOf(vals.size());
	for (size_t i = 0; i + 1 < idx.size(); i += 2) {
		size_t a = idx[i];
		size_t b = idx[i + 1];
		if (vals[a] < vals[b]) {
			size_t tmp = a;
			a = b;
			b = tmp;
		}
		bigs.push_back(a);
		smallOf[a] = b;
	}
	bool hasStraggler = (idx.size() % 2 != 0);
	size_t straggler = idx.back();

	sortIndexesDeque(vals, bigs);

	std::deque<size_t> pend;
	for (size_t k = 0; k < bigs.size(); k++)
		pend.push_back(smallOf[bigs[k]]);
	if (hasStraggler)
		pend.push_back(straggler);

	std::deque<size_t> chain(bigs);
	chain.push_front(pend[0]);

	size_t prev = 1;
	size_t jPrev = 1;
	size_t jCur = 3;
	while (prev < pend.size()) {
		size_t end = (jCur < pend.size()) ? jCur : pend.size();
		std::deque<size_t> inserted;
		for (size_t k = end; k > prev; k--) {
			size_t bound = chain.size();
			if (k - 1 < bigs.size()) {
				bound = prev + k - 1;
				for (size_t i = 0; i < inserted.size(); i++)
					if (inserted[i] <= bound)
						bound++;
			}
			size_t p = searchDeque(vals, chain, vals[pend[k - 1]], bound);
			chain.insert(chain.begin() + p, pend[k - 1]);
			inserted.push_back(p);
		}
		prev = end;
		size_t next = jCur + 2 * jPrev;
		jPrev = jCur;
		jCur = next;
	}

	idx = chain;
}

void PmergeMe::sortDeque(std::deque<int> &data)
{
	std::deque<size_t> idx;
	for (size_t i = 0; i < data.size(); i++)
		idx.push_back(i);
	sortIndexesDeque(data, idx);

	std::deque<int> sorted;
	for (size_t i = 0; i < idx.size(); i++)
		sorted.push_back(data[idx[i]]);
	data = sorted;
}
