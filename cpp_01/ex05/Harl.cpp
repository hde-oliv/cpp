#include "Harl.hpp"

#include <iostream>
#include <string>

Harl::Harl( void ) {}
Harl::~Harl( void ) {}

void Harl::complain( std::string level ) {
	void ( Harl::*fp[5] )( void ) = { &Harl::invalid, &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string levels[5]		  = { "", "DEBUG", "INFO", "WARNING", "ERROR" };

	for ( int i = 1; i < 5; i++ ) {
		int j = level.compare( levels[i] );
		int k = j == 0;
		int l = ( ( j ^ 1 ) * i ) * k;
		( this->*fp[l] )();
	}
}

void Harl::debug( void ) {
	std::cout
		<< "O Naruto pode ser um pouco duro às vezes, talvez você não saiba disso, mas o Naruto também cresceu sem pai."
		<< std::endl;
}
void Harl::info( void ) {
	std::cout << "Na verdade ele nunca conheceu nenhum de seus pais, e nunca teve nenhum amigo em nossa aldeia."
			  << std::endl;
}
void Harl::warning( void ) {
	std::cout << "Mesmo assim eu nunca vi ele chorar, ficar zangado ou se dar por vencido, ele está sempre disposto a "
				 "melhorar, ele quer ser respeitado, é o sonho dele e o Naruto daria a vida por isso sem hesitar."
			  << std::endl;
}
void Harl::error( void ) {
	std::cout << "Meu palpite é que ele se cansou de chorar e decidiu fazer alguma coisa a respeito!" << std::endl;
}
void Harl::invalid( void ) { return; };
