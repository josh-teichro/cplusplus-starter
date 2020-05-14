#include <iostream>
#include "lib1.h"
#include "header.h"

int main(int argc, char** argv) {
	std::cout << "Hello World!" << std::endl;
	std::cout << get_message() << std::endl;
	std::cout << lib1::get_message() << std::endl;

	return 0;
}