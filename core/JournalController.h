//
// Created by alfss on 27.12.16.
//

#ifndef JOURNAL_VERSION_23_JOURNALCONTROLLER_H
#define JOURNAL_VERSION_23_JOURNALCONTROLLER_H


#include <vector>

#include "JournalItem.h"

class JournalController {
public:
    static JournalController& instance();

    void load();
    void save();
    void add(JournalItem item);
    std::vector<JournalItem> list();
    std::vector<JournalItem> findByYear(int year);
private:
    JournalController();
    ~JournalController();

    JournalController(JournalController const&) = delete;
    JournalController& operator= (JournalController const&) = delete;

    std::vector<JournalItem> _journalVector;
};


#endif //JOURNAL_VERSION_23_JOURNALCONTROLLER_H
