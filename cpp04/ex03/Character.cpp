#include "Character.hpp"

Character::Character() : name("Character") {
	for (int i = 0; i < 4; i++)
		inventory[i] = 0;
}

Character::Character(const std::string& name) {
	this->name = name;
	for (int i = 0; i < 4; i++)
		inventory[i] = 0;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (inventory[i])
			delete inventory[i];
}

Character::Character(const Character& ref) {
	if (this != &ref) {
		this->name = ref.name;
		for (int i = 0; i < 4; i++) {
			if (ref.inventory[i] != 0)
				inventory[i] = ref.inventory[i]->clone();
			else
				inventory[i] = 0;
		}
	}
}

Character& Character::operator=(const Character& ref) {
	if (this != &ref) {
		this->name = ref.name;
		for (int i = 0; i < 4; i++) {
			if (inventory[i] != 0) {
				delete inventory[i];
				inventory[i] = 0;
			}
			if (ref.inventory[i] != 0)
				inventory[i] = ref.inventory[i]->clone();
		}
	}
	return *this;
}

std::string const& Character::getName() const {return name;}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (inventory[i] == 0) {
			inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return ;
	if (inventory[idx] == 0)
		return ;
	inventory[idx] = 0;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3)
		return ;
	if (inventory[idx] == 0)
		return ;
	inventory[idx]->use(target);
}

void	Character::save_unequip(int idx, AMateria* floor[]) {
	if (idx < 0 || idx > 3)
		return ;
	if (inventory[idx] == 0)
		return ;
	for (int i = 0; i < 500000; i++) {
		if (floor[i] == 0) {
			floor[i] = inventory[idx];
			break ;
		}
		if (i == 499999) {
			std::cout << "There is no more space on the floor\n";
			return;
		}
	}
	unequip(idx);
}