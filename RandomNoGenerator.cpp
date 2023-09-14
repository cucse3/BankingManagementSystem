#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate an 8-digit random integer
    int min = 10000000; // Smallest 8-digit number
    int max = 99999999; // Largest 8-digit number
    int randomInteger = min + (rand() % (max - min + 1));

    // Output the generated integer
    cout << "Random 8-digit integer: " << randomInteger <<endl;

    return 0;
}
