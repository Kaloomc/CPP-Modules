#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _db(other._db) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_db = other._db;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &)
{
	// TODO: read data.csv ("date,exchange_rate") into _db
}

void BitcoinExchange::processInput(const std::string &) const
{
	// TODO: read "date | value" lines, validate, print "date => value = result"
}
