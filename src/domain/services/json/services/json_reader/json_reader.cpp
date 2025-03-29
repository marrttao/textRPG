#include "json_reader.h"
#include <fstream>
#include <iostream>

string* JsonReader::read(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return nullptr;
    }
    
    string* json = new string();
    string line;
    while (getline(file, line)) {
        *json += line;
    }
    file.close();
    return json;
}