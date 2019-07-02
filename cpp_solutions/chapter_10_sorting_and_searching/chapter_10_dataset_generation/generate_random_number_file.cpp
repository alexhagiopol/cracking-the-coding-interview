#include <iostream>
#include <fstream>
#include <random>
#include <string>

int main() {
    std::string filename = "random_number_dataset.csv";
    std::cout << "Random number file generator outputting to " << filename << std::endl;
    // initialize random integer generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint32_t> dis(0, 0xFFFFFFFF);
    // initialize file stream
    std::ofstream file;
    file.open(filename);
    // write to file line by line
    for (int i = 0; i < 10000; i++) {  // problem 10.7 specifies 4 billion numbers, for testing speed, we only write 10000
        file << dis(gen);
        file << ",\n";
    }
    file.close();
	return 0;
}
