#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <map>
# include <exception>

class BitcoinExchange {
	public:
		BitcoinExchange();
		~BitcoinExchange();
		void	makeData();
		void	parseInfile(std::string infile);
		void	checkData(std::string data);
		void	checkInfile(std::string infile);
		bool	checkDayInfo(std::string day);
		bool	checkDay(long year, long month, long day);

		class FailToOpenData : public std::runtime_error {
			public:
				FailToOpenData();
		};

		class FailToOpenInfile : public std::runtime_error {
			public:
				FailToOpenInfile();
		};

	private:
		std::map<std::string, double> data;

		BitcoinExchange(const BitcoinExchange& rhs);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
};

#endif