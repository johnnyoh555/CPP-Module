#ifndef SPAN_HPP
#define SPAN_HPP

# include <iostream>
# include <vector>
# include <exception>

class Span {
	private:
		std::vector<int>	V;
		unsigned int		max;
		Span();
	
	public:
		Span(const unsigned int N);
		~Span();
		Span(const Span& rhs);
		Span& operator=(const Span& rhs);

		void	addNumber(int i);


		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		class SpanIsFull : public std::logic_error {
			public:
				SpanIsFull();
		};

		class CantFindSpan : public std::logic_error {
			public:
			CantFindSpan();
		};

		template <typename iter>
		void 	addNumber(iter begin, iter end) {
			if (V.size() + std::distance(begin, end) > max)
        		throw SpanIsFull();
			while (begin != end) {
				addNumber(*begin);
				begin++;
			}
		}
};

#endif