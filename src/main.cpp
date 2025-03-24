#include "domain/services/json/core/json_parser.h"
#include "domain/repositories/item_repository/item_repository.h"
#define FILE_PATH "src/domain/services/json/assets/json/example.json"

// utf-8



int main() {
    try {
      
        // Загрузка предметов
        auto items = ItemRepository::load(FILE_PATH);

        if (items.empty()) {
            std::cerr << "Error: No items loaded!" << std::endl;
            return 1;
        }

        // Проверка существования предмета
        if (!items.count("sword_001")) {
            std::cerr << "Error: Item sword_001 not found!" << std::endl;
            return 1;
        }

        Item sword = items.at("sword_001");
        std::cout << "Loaded item: " << sword.name << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Critical error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}