#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class NumberProcessor {
public:
    void processFile(const string& inputFile, const string& outputFile) {
        ifstream input(inputFile);
        ofstream output(outputFile);

        if (!input || !output) {
            cout << "Error opening files.\n";
            return;
        }

        vector<long long> numbers;

        long long num;
        while (input >> num) {
            string numAsString = to_string(num);
            size_t found = numAsString.find("123");

            while (found != string::npos) {
                numAsString.replace(found, 3, "321");
                found = numAsString.find("123", found + 3);
            }

            try {
                long long modifiedNum = stoll(numAsString);
                numbers.push_back(modifiedNum);
            } catch (const std::out_of_range& e) {
                // Ignore numbers that exceed limits
            }
        }

        sort(numbers.begin(), numbers.end());

        for (long long n : numbers) {
            output << n << endl;
        }

        input.close();
        output.close();

        cout << "Processed input from '" << inputFile << "' and wrote results to '" << outputFile << "'.\n";
    }
};

int main() {
    NumberProcessor processor;

    // Process input and generate output
    processor.processFile("data.in", "data.out");

    return 0;
}

