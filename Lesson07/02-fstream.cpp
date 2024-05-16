//
// Created by Ignorant on 2024/5/16.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // include <fstream> for writeFile-oriented io
    // 1. open a writeFile
    // ofstream writeFile(filename, mode); mode can be ios::out (output) / ios::app (append) / ios::binary (binary mode)
    ofstream writeFile("./output.txt", ios::out | ios::binary);
    if (!writeFile.is_open()) {
        cout << "Error: cannot open writeFile" << endl;
        return 1;
    }
    // 2. write to the writeFile
    // through text
    writeFile << "Hello, world!" << endl;
    // or through binary
    int x = 123;
    writeFile.write((char*)&x, sizeof(x));
    // 3. close the writeFile
    writeFile.close();
    
    ifstream readFile("./output.txt", ios::in | ios::binary);
    if (!readFile.is_open()) {
        cout << "Error: cannot open readFile" << endl;
        return 1;
    }
    string line;
    // read text
    while (getline(readFile, line)) {
        cout << line << endl;
    }
//   read binary
//    int y;
//    readFile.read((char*)&y, sizeof(y));
//    cout << "y = " << y << endl;
    readFile.close();
    return 0;
}
