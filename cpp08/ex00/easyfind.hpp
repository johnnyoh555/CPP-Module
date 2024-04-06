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
typename T::iterator	easyfind(T& con, int idx) {
	typename T::iterator it = std::find(con.begin(), con.end(), idx);
	if (it == con.end())
		throw CantFindExcption();
	return it;
}

#endif 