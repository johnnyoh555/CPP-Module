#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
	private:
		ClapTrap();
	protected:
		std::string	name;
		int			hit_point;
		int			energy_point;
		int			attack_damage;

	public:
		ClapTrap(const std::string name);
		~ClapTrap();
		ClapTrap(const ClapTrap &ref);
		ClapTrap& operator= (const ClapTrap &ref);

		std::string	getname(void) const;
		int			gethit_point(void) const;
		int			getenergy_point(void) const;
		int			getattack_damage(void) const;

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif