#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main(void)
{
	AMateria*	floor[500000] = {0, };

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	ICharacter* bob = new Character("bob");
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);


	me->use(0, *bob);
	me->use(1, *bob);

	Character* jooh = new Character("jooh");
	tmp = src->createMateria("ice");
	jooh->equip(tmp);
	tmp = src->createMateria("cure");
	jooh->equip(tmp);
	tmp = src->createMateria("ice");
	jooh->equip(tmp);
	jooh->save_unequip(1, floor);
	jooh->use(0, *bob);
	jooh->use(1, *bob);
	jooh->use(2, *bob);
	
	for (int i = 0; i < 500000; i++) {
		if (floor[i])
			delete floor[i];
	}

	delete jooh;
	delete bob;
	delete me;
	delete src;

	return 0;
}