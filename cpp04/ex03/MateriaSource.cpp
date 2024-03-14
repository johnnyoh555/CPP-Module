#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		materia[i] = 0;
	}
}

MateriaSource::MateriaSource(const MateriaSource& rhs) {
	for (int i = 0; i < 4; i++) {
		if (rhs.materia[i] != 0)
			materia[i] = rhs.materia[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 4; i++) {
			if (materia[i] != 0) {
				delete materia[i];
				materia[i] = 0;
			}
			if (rhs.materia[i] != 0)
				materia[i] = rhs.materia[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (materia[i]) delete materia[i];
	}
}

void	MateriaSource::learnMateria(AMateria *rhs) {
	for (int i = 0; i < 4; i++) {
		if (materia[i] == 0) {
			materia[i] = rhs;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++) {
		if (materia[i]->getType() == type)
			return materia[i]->clone();
	}
	return 0;
}