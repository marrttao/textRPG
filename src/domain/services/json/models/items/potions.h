#ifndef POTIONS_H
#define POTIONS_H
#include "../../models/itemm/potion/potion.h"

using namespace std;

class Potions : public JsonObject
{
public:
    vector<Potion> potions;

    vector<string> toJsonFields() override
    {
        return { "potions" };
    }

    void fromJson(map<string, string> jsonMap) override
    {
        potions.clear();
        for (int i = 0; ; ++i)
        {
            string prefix = "potions[" + to_string(i) + "]";
            if (jsonMap.count(prefix + ".id"))
            {
                Potion potion;
				potion.fromJson({
					{"id", jsonMap[prefix + ".id"]},
					{"name", jsonMap[prefix + ".name"]},
					{"type", jsonMap[prefix + ".type"]},
					{"heal", jsonMap[prefix + ".heal"]},
					{"strength", jsonMap[prefix + ".strength"]},
					{"armour", jsonMap[prefix + ".armour"]},
					{"rage", jsonMap[prefix + ".rage"]},
					{"duration", jsonMap[prefix + ".duration"]},
					{"weight", jsonMap[prefix + ".weight"]}
					});


                potions.push_back(potion);
            }
            else
            {
                break;
            }
        }
    }
};

#endif // !POTIONS_H
