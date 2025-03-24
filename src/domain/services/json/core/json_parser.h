#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include "../services/json_reader/json_reader.h"
#include "../services/json_mapper/json_mapper.h"

enum ParsingPath {
    STRING_FORMAT,
    FILE_FORMAT
};

class IJsonParser
{
public:
    virtual void parse(JsonObject& object, const string& path, ParsingPath type_of_path) = 0;
    virtual std::string serialize(const std::vector<std::map<std::string, std::string>>& jsonItems) = 0;
};

class JsonParser : public IJsonParser, public IJsonReader
{
public:
    string read(const string& filename) override
    {
        return (JsonReader::read(filename) == nullptr) ? "" : *JsonReader::read(filename);
    }
    void parse(JsonObject& object, const string& path, ParsingPath type_of_path) override
    {
        string json;
        (type_of_path == ParsingPath::FILE_FORMAT) ? json = read(path) : json = path;
        JsonMapper mapper;
        mapper.map_json(json, object);
    }
    std::string serialize(const std::vector<std::map<std::string, std::string>>& jsonItems) override
    {
        std::string jsonString = "[";
        for (const auto& item : jsonItems) {
            jsonString += "{";
            for (const auto& field : item) {
                jsonString += "\"" + field.first + "\":\"" + field.second + "\",";
            }
            if (!item.empty()) {
                jsonString.pop_back(); // Remove the trailing comma
            }
            jsonString += "},";
        }
        if (!jsonItems.empty()) {
            jsonString.pop_back(); // Remove the trailing comma
        }
        jsonString += "]";
        return jsonString;
    }
};

#endif // !JSON_PARSER_H
