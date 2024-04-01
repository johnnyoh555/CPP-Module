#ifndef	SERIALIZER_HPP
#define	SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

struct Data {
	int 		i;
	std::string	str;
	bool		flag;
};

class Serializer {
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer& rhs);
		Serializer& operator=(const Serializer& rhs);
		
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif