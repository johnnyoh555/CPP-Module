#ifndef CAT_HPP
#define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal {
	private:
		Brain	*brain;

	public:
		Cat();
		virtual ~Cat();
		Cat(const Cat &ref);
		virtual Cat &operator= (const Cat &ref);

		virtual void		makeSound() const;
		std::string getBrainIdea(const int i) const;
};

#endif