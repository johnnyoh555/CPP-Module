#include "BitcoinExchange.hpp"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs) {(void)rhs;}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {(void)rhs; return *this;}

void	BitcoinExchange::makeData() {
	std::ifstream	dataFile("data.csv");
	std::string str;

	if (!dataFile) throw ;
	while (std::getline(dataFile, str)) checkData(str);
}

void	BitcoinExchange::checkData(std::string data) {
	size_t	index;
	std::string	day;
	double value;

	index = data.find(',');
	if (index == std::string::npos || index != 10) return;
	if (!checkDayInfo(data.substr(0, index))) return;
	value = strtod(data.substr(index + 1).c_str(), 0);
	if (value == -1) return;
	this->data.insert(std::make_pair(day, value));
}

bool	BitcoinExchange::checkDayInfo(std::string dayInfo) {
	std::string strYear;
	std::string strMonth;
	long year;
	long month;
	long day;

	strYear = dayInfo.substr(0, dayInfo.find('-'));
	dayInfo.erase(0, dayInfo.find('-'));
	strMonth = dayInfo.substr(0, dayInfo.find('-'));
	dayInfo.erase(0, dayInfo.find('-'));
	year = strtol(strYear.c_str(), 0, 10);
	month = strtol(strMonth.c_str(), 0, 10);
	day = strtol(dayInfo.c_str(), 0, 10);
	if (!checkDay(year, month, day)) return false;
	return true;
}

bool	BitcoinExchange::checkDay(long year, long month, long day) {
	if (year < 0 || year > 9999 || month > 12 || month < 1 || day < 1 || day > 31)
		return false;
	if (month == 2 && day > 28) {
		if (day == 29 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
			return true;
		else
			return false;
	} else if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11)) {
		return false;
	}
	return true;
}

void	BitcoinExchange::parseInfile(std::string infile) {
	std::ifstream	file("data.csv");
	std::string str;

	if (!file) throw ;
	while (std::getline(file, str)) {
		if (str == "date | value") continue;
		checkData(str);
	}
}
