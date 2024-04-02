#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array {
	private:
		T* 				arr;
		unsigned int	arrlen;

	public:
		class OutOfBound : public std::out_of_range {
			public:
				OutOfBound() : std::out_of_range("Index is Out of Range") {}
		};

		Array() : arr(0), arrlen(0) {}

		Array(unsigned int n) {
			arr = new T[n];
			arrlen = n;
		}

		~Array() {
			delete[] arr;
		}

		Array(const Array& rhs) {
			arr = new T[rhs.arrlen];
			arrlen = rhs.arrlen;
			for (unsigned int i = 0; i < rhs.arrlen; i++) {
				arr[i] = rhs.arr[i];
			}
		}

		Array&	operator=(const Array& rhs) {
			if (this != &rhs) {
				delete[] arr;
				arr = new T[rhs.arrlen];
				arrlen = rhs.arrlen;
				for (unsigned int i = 0; i < rhs.arrlen; i++) {
					arr[i] = rhs.arr[i];
				}
			}
			return *this;
		}
		
		T&	operator[] (unsigned int idx) {
			if (idx < 0 || idx >= arrlen)
				throw OutOfBound();
			return arr[idx];
		}
		
		T&	operator[] (unsigned int idx) const {
			if (idx < 0 || idx >= arrlen)
				throw OutOfBound();
			return arr[idx];
		}
		
		unsigned int 	size() const {return arrlen;}

};

#endif