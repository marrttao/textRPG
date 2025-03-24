// File: example.h
#ifndef SWORDS_H
#define SWORDS_H

#include "../../models/itemm/sword/sword.h"

using namespace std;

class Swords : public JsonObject
{
public:
    vector<Sword> swords;

    vector<string> toJsonFields() override
    {
        return { "swords" };
    }

    void fromJson(map<string, string> jsonMap) override
    {
        swords.clear();
        for (int i = 0; ; ++i)
        {
            string prefix = "swords[" + to_string(i) + "]";
            if (jsonMap.count(prefix + ".id"))
            {
                Sword sword;
				sword.fromJson({
					{"id", jsonMap[prefix + ".id"]},
					{"name", jsonMap[prefix + ".name"]},
					{"type", jsonMap[prefix + ".type"]},
					{"damage", jsonMap[prefix + ".damage"]},
					{"weight", jsonMap[prefix + ".weight"]}
					});


                swords.push_back(sword);
            }
            else
            {
                break;
            }
        }
    }
};

#endif // SWORDS_H
