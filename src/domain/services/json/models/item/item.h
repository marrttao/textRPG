// item.h
#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    virtual ~Item() = default;
    virtual std::string getID() const = 0;    // ���������� �������������
    virtual std::string getName() const = 0;  // �������� ��������
};

#endif // ITEM_H