#include <iostream>
#include <limits>

#include "App.h"
#include "../core/JournalController.h"

void App::menu() {
    int selectAction = 0;
    bool enableLoopMenu = true;

    JournalController& controller = JournalController::instance();
    controller.load();

    while( enableLoopMenu ) {
        std::cout << "###### Меню ######" << std::endl;
        std::cout << "1 - Добавить журнал" << std::endl;
        std::cout << "2 - Вывод всех журналов" << std::endl;
        std::cout << "3 - Подсчет журналов за конкретный год" << std::endl;
        std::cout << "4 - Завершить программу" << std::endl;

        std::cout << "Выбирите действие: ";
        std::cin >> selectAction;

        switch ( selectAction ) {
            case 1:
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                addJournalItem();
                break;
            case 2:
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                listJournalItems();
                break;
            case 3:
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                calculateTotalJournalItemsPerYear();
                break;
            case 4:
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                enableLoopMenu = false;
                controller.save();
                std::cout << "Выход" << std::endl;
                break;
            default:
                std::cin.clear();
                std::cout << "Такого действия нету! = " << std::cin.get() << std::endl;
        }
    }
}

void App::addJournalItem() {
    JournalController& controller = JournalController::instance();

    JournalItem item = JournalItem();
    std::string tmpString;
    int tmpNumber;

    std::cout << "Добавление журнала" << std::endl;

    std::cout << "Введите название:";
    std::getline(std::cin, tmpString);
    item.setName(tmpString);

    std::cout << "Введите номер:";
    std::cin>>tmpNumber;
    item.setNumber(tmpNumber);

    std::cout << "Введите год:";
    std::cin>>tmpNumber;
    item.setYear(tmpNumber);

    controller.add(item);
}

void App::calculateTotalJournalItemsPerYear() {
    std::cout << "Подсчет жураналов за конкретный год" << std::endl;
    int journalYear = 2000;

    std::cout << "Введите год:";
    std::cin>>journalYear;

    int totalJournalInYear = 0;

    JournalController& controller = JournalController::instance();

    std::vector<JournalItem> itemList = controller.findByYear(journalYear);
    for(auto &item: itemList) {
        totalJournalInYear++;
    }

    std::cout << "Количество журанлов за " << journalYear << ": "
              << totalJournalInYear
              << std::endl;
}

void App::listJournalItems() {
    std::cout << "Список журналов: " << std::endl;
    JournalController& controller = JournalController::instance();
    std::vector<JournalItem> itemList = controller.list();
    for(auto &item: itemList) {
        std::cout << item.toYamlString() << std::endl;
    }
}
