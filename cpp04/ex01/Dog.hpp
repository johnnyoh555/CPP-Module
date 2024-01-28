#ifndef DOG_HPP
#define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal {
	private:
		Brain	*brain;

	public:
		Dog();
		~Dog();
		Dog(const Dog &ref);
		virtual Dog &operator= (const Dog &ref);

		virtual void		makeSound() const;
		std::string getBrainIdea(const int i) const;
};

#endif