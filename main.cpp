#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string GetDataFromFile(string path);

bool validateData(string data);

int calcSizeArray(string data);

int main() {

    string path = "input.dat";

    string data = GetDataFromFile(path);
    cout << data << endl;

    cout << validateData(data) << endl;

    int size = calcSizeArray(data);
    cout << size << endl;

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

bool validateData(string data) {
    return !data.empty();
}

int calcSizeArray(string data) {
    int size = 1;

    for (int i = 0; i < data.length(); ++i) {
        if (data[i] == ' ') {
            size++;
        }
    }

    return size;
}