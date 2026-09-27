#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		bool loadDatabase(const std::string &path);
		void processInput(const std::string &path) const;

	private:
		std::map<std::string, float> _db;

		bool isValidDate(const std::string &date) const;
};

#endif
