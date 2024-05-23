//
// Created by Ignorant on 2024/5/16.
//

#include <iostream>
#include <fstream>
using namespace std;

void read(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Failed to open file " + filename);
    }
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main() {
    // 1. Find Exception
    try {
        read("non-existent-file.txt");
    } catch(char *e) {
        // 2. Handle Exception
        cerr << "Caught exception: " << e << endl;
    } catch (runtime_error &e) {
        cerr << "Caught runtime_error: " << e.what() << endl;
    }
    return 0;
}
