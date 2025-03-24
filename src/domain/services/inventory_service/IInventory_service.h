#ifndef IINVENTORY_SERVICE_H
#define IINVENTORY_SERVICE_H
#include "../../entities/inventory/inventory.h"
#include "../../entities/character/character.h"

class IInventoryService {
public:
	virtual void useItem(Item item) = 0;
	virtual void addItem(Item item) = 0;
	virtual void removeItem(Item item) = 0;
	virtual Item getItemInfo(Item item) = 0;
};

#endif // !IINVENTORY_SERVICE_H
