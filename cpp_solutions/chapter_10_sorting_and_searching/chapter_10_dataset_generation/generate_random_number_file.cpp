#include <iostream>
#include <fstream>
#include <random>
#include <string>

int main(int argc, const char* argv[]) {
    if (argc != 4) {
        std::cout << "Usage: \ngenerate_random_number_file filename.csv max_value count" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::cout << "Random number file generator outputting to " << filename << std::endl;
    // problem 10.7 specifies a max value of 2^32 = 0xFFFFFFFF ~= 4,294,967,296
    // for reasonable test dataset size, we use a smaller range of [0,4300]
    const int max_value = std::stoi(argv[2]);
    // problem 10.7 specifies 4 billion numbers, for testing speed, we only write 4000
    const int count = std::stoi(argv[3]);

    // initialize random integer generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint32_t> dis(1, max_value);
    // initialize file stream
    std::ofstream file;
    file.open(filename);
    // write to file line by line
    for (int i = 0; i < count; i++) {
        file << dis(gen);
        file << ",\n";
    }
    file.close();
	return 0;
}
