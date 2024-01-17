#ifndef HUMANA_HPP
#define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA {
	private:
		Weapon		&MyWeapon;
		std::string	name;

	public:
		HumanA(const std::string& name, Weapon& Weapon);
		~HumanA();

		void	attack();
};

#endif