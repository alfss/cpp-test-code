#include <boost/format.hpp>

#include "JournalItem.h"
JournalItem::JournalItem() {
    _number = -1;
    _year = -1;
    _name = "-1";
}

JournalItem::JournalItem(std::string name, int number, int year) {
    _name = name;
    _number = number;
    _year = year;
}

void JournalItem::setName(std::string name) {
    _name = name;
}

void JournalItem::setNumber(int number) {
    _number = number;
}

void JournalItem::setYear(int year) {
    _year = year;
}

std::string JournalItem::getName() {
    return _name;
}

int JournalItem::getNumber() {
    return _number;
}

int JournalItem::getYear() {
    return _year;
}

std::string JournalItem::toYamlString() {
    return (boost::format("{ name: %1%, number: %2%, year: %3% }") % _name % _number % _year).str();
}
