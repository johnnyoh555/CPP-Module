#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& rhs) {(void)rhs;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {(void)rhs; return *this;}

static void	check_dot_float(const std::string& rhs, bool& dot_flag, bool& float_flag) {
	for (std::size_t i = 0; i < rhs.size(); i ++) {
		if (!(std::isdigit(rhs[i]) || rhs[i] == '.' || rhs[i] == 'f') || (dot_flag && rhs[i] == '.'))
			throw 0;
		if (rhs[i] == '.')
			dot_flag = true;
		if (rhs[i] == 'f' && i != rhs.size() - 1)
			throw 0;
	}
	if (rhs[rhs.size() - 1] == '.')
		throw 0;
	if (rhs[rhs.size() - 1] == 'f')
		float_flag = true;
}

static void convert_by_double(const std::string& rhs) {
	char	c;
	int		i;
	float	f;
	double	d;
	char*	endptr = 0;

	errno = 0;
	d = strtod(rhs.c_str(), &endptr);
	if (errno == ERANGE && (d == HUGE_VAL || d == 0))
		throw 0;
	if (d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min())
		std::cout << "char: impossible\n";
	else if	(!std::isprint(d))
		std::cout << "char: Non displayable\n";
	else {
		c = static_cast<char>(d);
		std::cout << "char: " << c << '\n';
	}
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "int: impossible\n";
	else {
		i = static_cast<int>(d);
		std::cout << "int: " << i << '\n';
	}
	if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min())
		std::cout << "float: impossible\n";
	else {
		f = static_cast<float>(d);
		if (f != std::floor(f))
			std::cout << "float: " << f << "f\n";
		else
			std::cout << "float: " << f << ".0f\n";
	}
	if (d != std::floor(d))
		std::cout << "double: " << d << '\n';
	else
		std::cout << "double: " << d << ".0\n";
}

static void convert_by_float(const std::string& rhs) {
	char	c;
	int		i;
	float	f;
	double	d;
	char*	endptr = 0;

	errno = 0;
	f = strtof(rhs.c_str(), &endptr);
	if (errno == ERANGE && (f == HUGE_VALF || f == 0))
		throw 0;
	d = static_cast<double>(f);
	if (f > std::numeric_limits<char>::max() || f < std::numeric_limits<char>::min())
		std::cout << "char: impossible\n";
	else if	(!std::isprint(f))
		std::cout << "char: Non displayable\n";
	else {
		c = static_cast<char>(f);
		std::cout << "char: " << c << '\n';
	}
	if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
		std::cout << "int: impossible\n";
	else {
		i = static_cast<char>(f);
		std::cout << "int: " << i << '\n';
	}
	if (f != std::floor(f))
		std::cout << "float: " << f << "f\n";
	else
		std::cout << "float: " << f << ".0f\n";
	if (d != std::floor(d))
		std::cout << "double: " << d << '\n';
	else
		std::cout << "double: " << d << ".0\n";
}

static void convert_by_int(const std::string& rhs) {
	std::istringstream	iss(rhs);
	char	c;
	int		i;
	float	f;
	double	d;

	iss >> i;
	if (iss.fail())
		throw 0;
	f = static_cast<float>(i);
	d = static_cast<double>(i);
	if (i > std::numeric_limits<char>::max() || i < std::numeric_limits<char>::min())
		std::cout << "char: impossible\n";
	else if	(!std::isprint(i))
		std::cout << "char: Non displayable\n";
	else {
		c = static_cast<char>(i);
		std::cout << "char: " << c << '\n';
	}
	std::cout << "int: " << i << '\n';
	std::cout << "float: " << f << ".0f\n";
	std::cout << "double: " << d << ".0\n";
}

static void convert_by_char(char rhs) {
	int	i;
	double d;
	float f;

	i = static_cast<int>(rhs);
	d = static_cast<double>(rhs);
	f = static_cast<float>(rhs);
	if (std::isprint(rhs))
		std::cout << "char: " << rhs << '\n';
	else
		std::cout << "char: Non displayable\n";
	std::cout << "int: " << i << '\n';
	std::cout << "float: " << f << ".0f\n";
	std::cout << "double: " << d << ".0\n";
}

void	print_minff(void) {
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: -inff\n";
	std::cout << "double: -inf\n";
}

void	print_pinff(void) {
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: +inff\n";
	std::cout << "double: +inf\n";
}

void	print_nan(void) {
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: nanf\n";
	std::cout << "double: nan\n";
}

void	ScalarConverter::convert(const std::string& rhs) {
	try {
		if (!rhs.size())
			throw 0;
		if (rhs.size() == 1 && !std::isdigit(rhs[0]))
			convert_by_char(rhs[0]);
		else if (rhs == "-inff" || rhs == "-inf")
			throw 1;
		else if (rhs == "+inff" || rhs == "+inf")
			throw 2;
		else if (rhs == "nanf" || rhs == "nan")
			throw 3;
		else {
			bool	dot_flag = false;
			bool	float_flag = false;
			check_dot_float(rhs, dot_flag, float_flag);
			if (float_flag == true)
				convert_by_float(rhs);
			else if (dot_flag == true)
				convert_by_double(rhs);
			else
				convert_by_int(rhs);
		}
	} catch (int i) {
		if (!i)
			std::cout << "Not a Valid Argument\n";
		else if (i == 1)
			print_minff();
		else if (i == 2)
			print_pinff();
		else if (i == 3)
			print_nan();
	}
}