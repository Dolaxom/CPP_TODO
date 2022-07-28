#ifndef SRC_TODO_H
#define SRC_TODO_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <ctime>
#include <stdlib.h>
#include "libs/termcolor.hpp"
#include "settings.h"

using std::string;

class ToDoList
{
    public:
        ToDoList();
        int TUI(int mode);
        void choiceHandle(int choice);

    protected:
        void newTask(string newTask);
        bool deleteTask(int index);

    private:
        string pathToTasks;
        string pathToLogs;
        string pathToSettings;
        int makeChoice();
        void writeLogs(int mode, string description);
        void output();
        void text(int mode);
        void clearScreen();
};

#endif