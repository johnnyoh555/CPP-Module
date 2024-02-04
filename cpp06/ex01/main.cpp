#include "Serializer.hpp"

int main(void) {
	Data 		D;
	uintptr_t	tmp;
	Data*		result;

	D.flag = 1;
	D.i = 55;
	D.str = "Qwer";
	
	tmp = Serializer::serialize(&D);
	result = Serializer::deserialize(tmp);

	std::cout << "Flag: " << result->flag << '\n';
	std::cout << "Int: " << result->i << '\n';
	std::cout << "String: " << result->str << '\n';
	if (result == &D)
		std::cout << "Same\n";
	else
		std::cout << "Fail\n";
}