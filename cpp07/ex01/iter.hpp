#ifndef ITER_HPP
#define ITER_HPP

# include <iostream>

template<typename T, size_t N, typename F>
void	iter(T (&arr)[N], const size_t length, const F func) {
	for (size_t i = 0; i < length; i++) {
		arr[i] = func(arr[i]);
	}
}

#endif