#include <iostream>
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	BitcoinExchange btc;
	// TODO: btc.loadDatabase("data.csv"); btc.processInput(av[1]);
	(void)av;
	return 0;
}
