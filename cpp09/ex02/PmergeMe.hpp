#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <vector>
# include <deque>
# include <ctime>

class VectorFJ {
	public:
		VectorFJ();
		~VectorFJ();

		void	makeVector(int ac, char* av[]);
		std::vector<std::pair<long, long> > mergeInsertion(std::vector<std::pair<long, long> > v, int dep);
		void	execute();
		void	print();
		void	result();
		
	private:
		std::vector<long> v;
		clock_t start;
		clock_t end;
		bool		flag;
		
		VectorFJ(const VectorFJ& rhs);
		VectorFJ& operator=(const VectorFJ& rhs);
};

class DequeFJ {
	public:
		DequeFJ();
		~DequeFJ();

		void	makeDeque(int ac, char* av[]);
		std::deque<std::pair<long, long> > mergeInsertion(std::deque<std::pair<long, long> > dq, int dep);
		void	execute();
		void	print();
		void	result();
		
	private:
		std::deque<long> dq;
		clock_t start;
		clock_t end;
		bool		flag;
		
		DequeFJ(const DequeFJ& rhs);
		DequeFJ& operator=(const DequeFJ& rhs);
};

#endif