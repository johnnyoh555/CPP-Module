#ifndef BRAIN_HPP
#define BRAIN_HPP

# include <sstream>
# include <iostream>

class Brain {
	private:
		std::string	ideas[100];
	
	public:
		Brain();
		~Brain();
		Brain(const Brain &ref);
		Brain& operator= (const Brain &ref);

		std::string getIdea(const int i) const;
};

#endif