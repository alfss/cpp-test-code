//
// Created by alfss on 27.12.16.
//
#include <iostream>
#include <fstream>
#include <yaml-cpp/yaml.h>
#include <boost/format.hpp>

#include "JournalController.h"


JournalController &JournalController::instance() {
    static JournalController s;
    return s;
}

void JournalController::load() {
    YAML::Node node = YAML::LoadFile("data.yml");
    if (node.IsSequence()) {
        for (int i = 0; i < node.size(); ++i) {
            YAML::Node current_node = node[i];
            JournalItem journalItem = JournalItem();
            journalItem.setName(current_node["name"].as<std::string>());
            journalItem.setNumber(current_node["number"].as<int>());
            journalItem.setYear(current_node["year"].as<int>());
            this->add(journalItem);
        }
    }
}

void JournalController::save() {
    std::ofstream dataFile("data.yml", std::ios::out | std::ios::trunc);
    if (dataFile.is_open()) {
        for(auto &item: _journalVector) {
            dataFile << (boost::format("- %1%\n") % item.toYamlString()).str();
        }
    }
}

void JournalController::add(JournalItem item) {
    _journalVector.push_back(item);
}

std::vector<JournalItem> JournalController::list() {
    return _journalVector;
}

std::vector<JournalItem> JournalController::findByYear(int year) {
    std::vector<JournalItem> findJournalItems;

    for(auto &item: _journalVector) {
        if (item.getYear() == year) {
            findJournalItems.push_back(item);
        }
    }
    return findJournalItems;
}

JournalController::JournalController() {
}

JournalController::~JournalController() {
}

