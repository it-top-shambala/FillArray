#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string GetDataFromFile(string path);

int main() {

    string path = "input.dat";
    cout << GetDataFromFile(path) << endl;

    return 0;
}

string GetDataFromFile(string path) {
    string line = "";

    ifstream file;
    file.open(path);

    if (!file.is_open()) {
        return line;
    }

    getline(file, line);

    file.close();

    return line;
}