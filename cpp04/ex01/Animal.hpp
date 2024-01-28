#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class Animal {
	protected:
		std::string	type;

	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal &ref);
		virtual Animal &operator= (const Animal &ref);

		virtual void	makeSound() const;
		std::string		getType() const;

};

#endif