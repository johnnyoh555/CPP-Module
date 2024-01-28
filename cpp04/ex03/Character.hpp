#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		AMateria*	inventory[4];
		std::string name;
		void unequip(int idx);
	
	public:
		Character();
		Character(const std::string& name);
		~Character();
		Character(const Character& ref);
		Character& operator= (const Character& ref);

		std::string const & getName() const;
		void 		equip(AMateria* m);
		void 		use(int idx, ICharacter& target);
		void		save_unequip(int idx, AMateria* floor[]);
};

#endif