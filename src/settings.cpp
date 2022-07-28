#include "settings.h"

Settings::Settings()
{
    pathToSettings = "../data/settings.txt";
}

int Settings::settingsScreen()
{
    TUI_Settings();
    int result = makeChoice();
    if (result == 3)
        return 0;

    choiceHandle(result);

    return 1;
}

void Settings::TUI_Settings()
{
    std::cout << "\e[H\e[2J\e[3J";
    std::cout << termcolor::white;
    std::cout << "1. Set Password\n";
    std::cout << "2. Watch log file\n";
    std::cout << "3. Back to tasks list\n";
    std::cout << termcolor::red << "> " << termcolor::white;
}

int Settings::makeChoice()
{
    int result = 0;
    std::cin >> result;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return result; 
}

void Settings::choiceHandle(int choice)
{
    if (choice == 1)
    {
        std::string str;
        std::ifstream file(pathToSettings);
        std::getline(file, str);
        bool oldPasswordIsValid = false;
        if (str.length() > 1)
        {
            oldPasswordIsValid = true;
            std::cout << "\e[H\e[2J\e[3J";
            std::cout << "Enter your old password: ";
            std::string oldPassword = inputString();
            if (oldPassword != str)
            {
                std::cout << termcolor::red << "ERROR: " << termcolor::white << "invalid password\n";
                std::cout << "Try again: ";
                oldPassword = inputString();
            }
            else
            {
                oldPasswordIsValid = false;
            }
        }

        file.close();
        if (oldPasswordIsValid == false)
        {
            std::cout << "Enter new password:\n" << "> ";
            std::string newPassword = inputString();
            
            std::ofstream file(pathToSettings);
            file << newPassword << "\n";
            file.close();
        }
        
    }
}

std::string Settings::inputString()
{
    std::string result;
    std::cin >> result;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return result; 

}
