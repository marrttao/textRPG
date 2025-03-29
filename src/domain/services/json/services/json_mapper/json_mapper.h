#ifndef JSON_MAPPER_H
#define JSON_MAPPER_H

#include "../../core/json_object.h"
#include <map>
#include <string>
#include <stack>

using namespace std;

class JsonMapper {
public:
    void parseJson(const string& jsonString, map<string, string>& jsonMap);
    void map_json(string json, JsonObject& object);


private:
    bool isWhitespace(char c);
    bool isDigit(char c);
    string parseStringValue(const string& json, size_t& i);
    string parseNumberValue(const string& json, size_t& i);
};
#endif // JSON_MAPPER_H