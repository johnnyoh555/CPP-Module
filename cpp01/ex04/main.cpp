#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include <cstring>

int	main(int ac, char *av[]) {
	if (ac != 4) {
		std::cerr << "Wrong arguments" << std::endl;
		return 1;
	}

	std::ifstream	infile(av[1]);
	std::string		str;

	if (infile.is_open()) {
		// std::stringstream	sstr;
		// sstr << infile.rdbuf();
		// str = sstr.str();

		std::istream_iterator<char>	begin(infile);
		std::istream_iterator<char>	end;
		infile >> std::noskipws;
		str = std::string(begin, end);

		// infile.seekg(0, std::ios::end);
		// int size = infile.tellg();
		// str.resize(size);
		// infile.seekg(0, std::ios::beg);
		// infile.read(&str[0], size);
	}
	else {
		std::cerr << "파일을 찾을 수 없습니다." << std::endl;
		return 1;
	}
	std::string::size_type n = 0;
	while (n < str.size() && strlen(av[2]) && str.find(av[2], n) != std::string::npos) {
		n = str.find(av[2], n);
		str.erase(n, strlen(av[2]));
		str.insert(n, av[3]);
		n += strlen(av[3]);
	}
	
	std::string		outfile_name;
	outfile_name = av[1];
	outfile_name += ".replace";

	std::ofstream	outfile(outfile_name.c_str());
	if (outfile.is_open())
		outfile << str;

	return 0;
}