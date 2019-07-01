#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Usage: ./generate_random_number_file title.csv" << std::endl;
	}
	std::cout << "Hello World." << std::endl;
	return 0;
}
