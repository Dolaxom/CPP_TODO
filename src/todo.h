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
        int TUI(int mode);
        void choiceHandle(int choice);

    protected:
        void newTask(string newTask);
        bool deleteTask(int index);

    private:
        string nameOfFile;
        int makeChoice();
        void output();
};

#endif