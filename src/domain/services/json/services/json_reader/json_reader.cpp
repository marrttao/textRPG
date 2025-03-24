// json_reader.cpp
#include "json_reader.h"
#include "../../../../../core/logger/LoggerMacro.h"

#include <fstream>

string* JsonReader::read(const string& filename)
{
    fstream file;
    string line;
    string* json = new string();

    try {
        file.open(filename, ios::in);
        if (!file.is_open())
        {
            LOG_ERROR("Failed to open file: " + filename);
            return nullptr;
        }
        while (getline(file, line))
        {
            *json += line;
        }
        file.close();
    }
    catch (const std::exception& e) {
        LOG_ERROR("Exception occurred while reading file: " + filename + " - " + e.what());
        delete json;
        return nullptr;
    }

    return json;
}
