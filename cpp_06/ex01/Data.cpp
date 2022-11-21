#include "Data.hpp"

Data::Data( void ) {}

Data::Data( std::string const &name ) { this->name = name; }

Data::Data( Data const &ref ) { this->name = ref.name; }

Data::~Data( void ) {}

Data &Data::operator=( Data const &ref ) {
	this->name = ref.name;
	return *this;
}

std::string Data::getName( void ) const { return this->name; }

void Data::setName( std::string const &name ) { this->name = name; }
