// item.h
#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    virtual ~Item() = default;
    virtual std::string getID() const = 0;    // Уникальный идентификатор
    virtual std::string getName() const = 0;  // Название предмета
};

#endif // ITEM_H