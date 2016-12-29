cmake_minimum_required(VERSION 3.5)
project(journal_version_23)

find_library(YAML_CPP_LIBRARY NAMES yaml-cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp core/JournalItem.cpp core/JournalItem.h ui/App.cpp ui/App.h core/JournalController.cpp core/JournalController.h)
add_executable(journal_version_23 ${SOURCE_FILES})
target_link_libraries(journal_version_23 ${YAML_CPP_LIBRARY})