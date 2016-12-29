//
// Created by alfss on 26.12.16.
//

#ifndef JOURNAL_VERSION_23_MENU_H
#define JOURNAL_VERSION_23_MENU_H


#include <vector>

#include "../core/JournalItem.h"

class App {
public:
    void menu();
private:
    void addJournalItem();
    void calculateTotalJournalItemsPerYear();
    void listJournalItems();
    std::vector<JournalItem> journalVector;
};


#endif //JOURNAL_VERSION_23_MENU_H
