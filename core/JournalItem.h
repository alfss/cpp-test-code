#ifndef JOURNAL_VERSION_23_JOURNAL_H
#define JOURNAL_VERSION_23_JOURNAL_H

#include <string>

class JournalItem {
public:
    JournalItem();
    JournalItem(std::string, int, int);
    void setName( std::string );
    void setNumber( int );
    void setYear( int );
    std::string getName();
    int getNumber();
    int getYear();
    std::string toYamlString();
private:
    std::string _name;
    int _number;
    int _year;
};


#endif //JOURNAL_VERSION_23_JOURNAL_H
