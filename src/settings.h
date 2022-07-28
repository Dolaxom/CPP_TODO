#ifndef SRC_SETTINGS_H
#define SRC_SETTINGS_H

#include <iostream>
#include <string>
#include <fstream>
#include "libs/termcolor.hpp"

class Settings
{
    public:
        Settings();
        int settingsScreen();

    private:
        void TUI_Settings();
        int makeChoice();
        std::string inputString();
        void choiceHandle(int choice);
        std::string pathToSettings;

};

#endif