// Copyright (C) 2022  Henrique Rocha (hde-oliv)

#include <fstream>
#include <iostream>
#include <string>

int main( int argc, char *argv[] ) {
	if ( argc != 4 ) {
		std::cout << "Invalid number of arguments." << std::endl;
		return 1;
	}

	std::fstream file( argv[1] );
	std::string	 s1( argv[2] );
	std::string	 s2( argv[3] );

	file.seekg( 0, file.end );
	int length = file.tellg();
	file.seekg( 0, file.beg );

	if ( file.fail() ) {
		std::cout << "Invalid file." << std::endl;
		return 1;
	}

	char *buffer = new char[length];

	file.read( buffer, length );
	file.close();

	std::string content( buffer );
	delete[] buffer;

	std::size_t position = 0;
	while ( true ) {
		position = content.find( s1, position );
		if ( position == std::string::npos ) break;
		content.erase( position, s1.length() );
		content.insert( position, s2 );
	}

	std::string	  fileName( argv[1] );
	std::ofstream resultFile( fileName.append( ".replace" ).c_str() );
	resultFile << content;
	resultFile.close();
	return 0;
}
