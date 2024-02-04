#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer& rhs) {(void)rhs;}

Serializer& Serializer::operator=(const Serializer& rhs) {(void)rhs; return *this;}

uintptr_t	Serializer::serialize(Data* ptr) {
	uintptr_t	tmp;

	tmp = reinterpret_cast<uintptr_t>(ptr);
	return tmp;
}

Data*	Serializer::deserialize(uintptr_t raw) {
	Data*	tmp;

	tmp = reinterpret_cast<Data*>(raw);
	return tmp;
}