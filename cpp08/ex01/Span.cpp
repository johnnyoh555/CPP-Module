#include "Span.hpp"

Span::Span() {}

Span::Span(const unsigned int N) {
	V.resize(N);
	max = N;
	size = 0;
}

Span::~Span() {}

Span::Span(const Span& rhs) {
	V = rhs.V;
	max = rhs.max;
	size = rhs.size;
}

Span& Span::operator=(const Span& rhs) {
	if (this != &rhs) {
		V = rhs.V;
		max = rhs.max;
		size = rhs.size;
	}
	return *this;
}

void	Span::addNumber(int i) {
	if (size == max)
		throw SpanIsFull();
	size++;
	V.push_back(i);
}

// template <typename iter>
// void 	Span::addNumber(iter begin, iter end) {
// 	while (begin != end) {
// 		addNumber(*begin);
// 		begin++;
// 	}
// }

unsigned int	Span::shortestSpan() {
	if (size < 2)
		throw CantFindSpan();
	std::vector<int> tmp;
	tmp = V;
	sort(tmp.begin(), tmp.end());
	unsigned int min = tmp[1] - tmp[0];
	for (size_t i = 0; i < tmp.size() - 1; i++) {
		if (static_cast<unsigned int>(tmp[i + 1] - tmp[i]) < min)
			min = static_cast<unsigned int>(tmp[i + 1] - tmp[i]);
	}
	return min;
}

unsigned int	Span::longestSpan() {
	if (size < 2)
		throw CantFindSpan();
	std::vector<int> tmp;
	tmp = V;
	sort(tmp.begin(), tmp.end());
	unsigned int max = tmp[1] - tmp[0];
	for (size_t i = 0; i < tmp.size() - 1; i++) {
		if (static_cast<unsigned int>(tmp[i + 1] - tmp[i]) > max)
			max = static_cast<unsigned int>(tmp[i + 1] - tmp[i]);
	}
	return max;
}

Span::SpanIsFull::SpanIsFull(): logic_error("Span Is Full") {}

Span::CantFindSpan::CantFindSpan(): logic_error("Can't Find Span") {}