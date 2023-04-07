#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string GetDataFromFile(string path);

bool ValidateData(string data);

int CalcSizeArray(string data);

int* CreateArrayFromData(int* size, string data);

void PrintArray(int* array, int size);

int main() {
    string data = "12 12 0 5 8 9 12 45";

    int size;
    int* array = CreateArrayFromData(&size, data);
    PrintArray(array, size);


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

bool ValidateData(string data) {
    return !data.empty();
}

int CalcSizeArray(string data) {
    int size = 1;

    for (int i = 0; i < data.length(); ++i) {
        if (data[i] == ' ') {
            size++;
        }
    }

    return size;
}

int* CreateArrayFromData(int* size, string data) {
    *size = CalcSizeArray(data);
    int* array = new int[*size];

    for (int i = 0; i < *size; ++i) {
        int position = data.find(' ');
        if (position == string::npos) {
            array[i] = stoi(data);
        } else {
            array[i] = stoi(data.substr(0, position));
            data = data.substr(position + 1);
        }
    }

    return array;
}

void PrintArray(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}