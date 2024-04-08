#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <iostream>
# include <exception>
# include <vector>
# include <deque>
# include <list>
# include <algorithm>
# include <iterator>

class CantFindExcption : public std::logic_error {
	public:
		CantFindExcption() : logic_error("Can't Find Something Same") {}
};

template<typename T>
typename T::iterator	easyfind(T& con, int i) {
	typename T::iterator it = std::find(con.begin(), con.end(), i);
	if (it == con.end())
		throw CantFindExcption();
	return it;
}

template<typename T>
typename T::const_iterator	easyfind(const T& con, int i) {
	typename T::const_iterator it = std::find(con.begin(), con.end(), i);
	if (it == con.end())
		throw CantFindExcption();
	return it;
}

#endif 