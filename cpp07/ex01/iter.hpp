#ifndef ITER_HPP
#define ITER_HPP

# include <iostream>

template<typename T, typename F>
void	iter(T arr[], const size_t length, const F func) {
	for (size_t i = 0; i < length; i++) func(arr[i]);
}

template<typename T>
void	iter(T arr[], const size_t length, const T func) {
	for (size_t i = 0; i < length; i++) arr[i] = func(arr[i]);
}

#endif