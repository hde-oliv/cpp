#include <iostream>
#include <string>

int main( void ) {
	std::string	 aString   = "HI THIS IS BRAIN";
	std::string *stringPTR = &aString;
	std::string &stringREF = aString;

	std::cout << "Memory address of string: " << &aString << std::endl;
	std::cout << "Helding memory address of stringPTR: " << stringPTR << std::endl;
	std::cout << "Helding memory address of stringREF: " << &stringREF << std::endl << std::endl;

	std::cout << "Value of string: " << aString << std::endl;
	std::cout << "Value of string by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of string by stringREF: " << stringREF << std::endl;

	return 0;
}
