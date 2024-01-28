#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	private:
		std::string	name;
		
		DiamondTrap();

	public:
		DiamondTrap(const std::string name);
		DiamondTrap(const DiamondTrap &ref);
		DiamondTrap& operator= (const DiamondTrap &ref);
		~DiamondTrap();

		void	whoAmI();
};

#endif