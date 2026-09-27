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

bool BitcoinExchange::loadDatabase(const std::string &path)
{
	std::ifstream file(path.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return false;
	}
	std::string line;
	std::getline(file, line); // skip header "date,exchange_rate"
	while (std::getline(file, line))
	{
		size_t pos = line.find(',');
		if (pos == std::string::npos)
			continue;
		std::string date = line.substr(0, pos);
		std::string rateStr = line.substr(pos + 1);
		float rate = std::atof(rateStr.c_str());
		_db[date] = rate;
	}
	file.close();
	return true;
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int maxDay = daysInMonth[month - 1];
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		maxDay = 29;
	if (day > maxDay)
		return false;
	return true;
}

void BitcoinExchange::processInput(const std::string &path) const
{
	std::ifstream file(path.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}
	std::string line;
	std::getline(file, line); // skip header "date | value"
	while (std::getline(file, line))
	{
		size_t pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, pos);
		std::string valueStr = line.substr(pos + 1);

		// trim surrounding spaces
		date.erase(0, date.find_first_not_of(" \t"));
		date.erase(date.find_last_not_of(" \t") + 1);
		valueStr.erase(0, valueStr.find_first_not_of(" \t"));
		valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		char *end;
		float value = static_cast<float>(std::strtod(valueStr.c_str(), &end));
		if (valueStr.empty() || *end != '\0')
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		std::map<std::string, float>::const_iterator it = _db.lower_bound(date);
		if (it == _db.end() || it->first != date)
		{
			if (it == _db.begin())
			{
				std::cerr << "Error: no earlier date in database." << std::endl;
				continue;
			}
			--it;
		}
		float rate = it->second;
		std::cout << date << " => " << value << " = " << (rate * value) << std::endl;
	}
	file.close();
}
