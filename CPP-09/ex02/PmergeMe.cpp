#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &)
{
	return *this;
}

PmergeMe::~PmergeMe() {}

template <typename C>
void PmergeMe::fordJohnson(C &data)
{
	// [0] cas de base
	if (data.size() <= 1)
		return;

	// [1] paires (grand, petit) + straggler si taille impaire
	std::vector<std::pair<int, int> > pairs;
	bool hasStraggler = (data.size() % 2 != 0);
	int straggler = hasStraggler ? data.back() : 0;
	for (size_t i = 0; i + 1 < data.size(); i += 2) {
		if (data[i] > data[i + 1])
			pairs.push_back(std::make_pair(data[i], data[i + 1]));
		else
			pairs.push_back(std::make_pair(data[i + 1], data[i]));
	}

	// [2] trier les grands recursivement
	C bigs;
	for (size_t i = 0; i < pairs.size(); i++)
		bigs.push_back(pairs[i].first);
	fordJohnson(bigs);

	// [3] pend[k] = petit associe a bigs[k]
	C pend;
	std::vector<bool> used(pairs.size(), false);
	for (size_t k = 0; k < bigs.size(); k++) {
		for (size_t j = 0; j < pairs.size(); j++) {
			if (!used[j] && pairs[j].first == bigs[k]) {
				used[j] = true;
				pend.push_back(pairs[j].second);
				break;
			}
		}
	}

	// [4] main chain : pend[0] <= bigs[0], il va direct en tete
	C mainChain = bigs;
	mainChain.insert(mainChain.begin(), pend[0]);

	// [5] insertion dans l'ordre de Jacobsthal : 3, 5, 11, 21, 43...
	size_t prev = 1;
	size_t jPrev = 1;
	size_t jCur = 3;
	while (prev < pend.size()) {
		size_t end = std::min(jCur, pend.size());
		for (size_t k = end; k > prev; k--) {
			// [6] recherche binaire bornee par le grand associe
			typename C::iterator bound = std::find(mainChain.begin(), mainChain.end(), bigs[k - 1]);
			typename C::iterator pos = std::lower_bound(mainChain.begin(), bound, pend[k - 1]);
			mainChain.insert(pos, pend[k - 1]);
		}
		prev = end;
		size_t next = jCur + 2 * jPrev;
		jPrev = jCur;
		jCur = next;
	}

	// [7] straggler sur toute la chaine
	if (hasStraggler)
		mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), straggler), straggler);

	// [8] resultat
	data = mainChain;
}

void PmergeMe::sortVector(std::vector<int> &data)
{
	fordJohnson(data);
}

void PmergeMe::sortDeque(std::deque<int> &data)
{
	fordJohnson(data);
}
