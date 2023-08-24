#include <iostream>
#include <fstream>
#include <random>
using namespace std;

int main() {
    ofstream outputFile("data.in");

    if (!outputFile) {
        cout << "Error opening the file.\n";
        return 1;
    }

    // Total number of integers you want to generate
    int totalNumbers = 1000000; // Here you can specify how many numbers you want to generate

    // Random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 1000000); // Here you can set the generation limits

    for (int i = 0; i < totalNumbers; ++i) {
        int num = dis(gen); // Generate a random integer
        outputFile << num << endl;
    }

    outputFile.close();

    cout << "The 'data.in' file has been generated successfully!\n";

    return 0;
}

