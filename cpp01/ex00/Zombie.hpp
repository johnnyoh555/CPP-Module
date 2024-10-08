#ifndef ZOMBIE_CPP
#define ZOMBIE_CPP

# include <iostream>

class Zombie {
	private:
		std::string	name;
		Zombie();

	public:
		Zombie(std::string name);
		~Zombie();
	
		void announce(void);
};

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );

#endif