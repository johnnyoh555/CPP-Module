#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	private:
		FragTrap();

	public:
		FragTrap(const std::string name);
		FragTrap(const FragTrap &ref);
		FragTrap& operator= (const FragTrap &ref);
		~FragTrap();

		void	highFivesGuys(void);
};

#endif