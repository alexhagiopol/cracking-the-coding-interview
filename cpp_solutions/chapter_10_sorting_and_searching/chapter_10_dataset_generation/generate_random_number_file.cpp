#include <iostream>
#include <fstream>
#include <random>
#include <string>

int main() {
    std::string filename = "random_number_dataset.csv";
    std::cout << "Random number file generator outputting to " << filename << std::endl;
    // problem 10.7 specifies a max value of 2^32 = 0xFFFFFFFF ~= 4,294,967,296
    // for reasonable test dataset size, we use a smaller range of [0,4300]
    const int numberRange = 1000;
    // problem 10.7 specifies 4 billion numbers, for testing speed, we only write 4000
    const int numberCount = 4000;

    // initialize random integer generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint32_t> dis(0, numberRange);
    // initialize file stream
    std::ofstream file;
    file.open(filename);
    // write to file line by line
    for (int i = 0; i < numberCount; i++) {
        file << dis(gen);
        file << ",\n";
    }
    file.close();
	return 0;
}
