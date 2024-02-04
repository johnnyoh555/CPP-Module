#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <iostream>
# include <exception>
# include <limits>
# include <sstream>
# include <cerrno>
# include <cmath>

class ScalarConverter {
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& rhs);
		ScalarConverter& operator=(const ScalarConverter& rhs);

	public:
		static void convert(const std::string& rhs);

};

#endif