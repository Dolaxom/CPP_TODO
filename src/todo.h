#ifndef TODO_H
#define TODO_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include "libs/termcolor.hpp"

using std::string;

class ToDoList {
    public:
        ToDoList();
        void newTask(string newTask);
        bool deleteTask(int index);
        void output();
        void TUI();
        int makeChoice();

    private:
        string nameOfFile;
};

#endif