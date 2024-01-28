#ifndef CAT_HPP
#define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		~Cat();
		Cat(const Cat &ref);
		virtual Cat &operator= (const Cat &ref);

		virtual void		makeSound() const;
};

#endif