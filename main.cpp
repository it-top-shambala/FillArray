#include "ArrayFunctions.h"

using namespace std;

int main() {
    string path = "input.dat";
    string data = GetDataFromFile(path);

    if (!ValidateData(data)) {
        cerr << "Error!" << endl;
        return 1;
    }

    int size;
    int* array = CreateArrayFromData(&size, data);
    PrintArray(array, size);


    return 0;
}
