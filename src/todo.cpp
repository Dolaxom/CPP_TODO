#include "todo.h"

ToDoList::ToDoList()
{
    pathToTasks = "../data/tasks.txt";
    pathToLogs = "../data/logs.txt";
    pathToSettings = "../data/settings.txt";
}

void ToDoList::newTask(string newTask)
{
    std::ofstream file(pathToTasks, std::ios_base::app);
    file << newTask << "\n";
    writeLogs(1, newTask);
    file.close();
}

bool ToDoList::deleteTask(int index)
{
    std::vector<string> tmp;

    std::ifstream file(pathToTasks);
    if (file.is_open())
    {
        string str;
        while (std::getline(file, str))
        {
            tmp.push_back(str);
        }
        file.close();

        if (index > (int)tmp.size())
        {
            std::cout << termcolor::red << "ERROR: " << termcolor::white << "Your index > max num of tasks\n";
            return false;
        }

        string log = tmp[index - 1];
        tmp.erase(tmp.begin() + index - 1);

        std::ofstream outfile(pathToTasks);
        if (outfile.is_open())
        {
            std::copy(tmp.begin(), tmp.end(), std::ostream_iterator<string>(outfile, "\n"));
            outfile.close();
            writeLogs(2, log);
            return true;
        }

        return false;
    }

    return false;
}

void ToDoList::output()
{
    std::cout << termcolor::red << "\tTODO List:" << std::endl;
    string str;
    int count = 1;
    std::ifstream file(pathToTasks);
    while (!file.eof())
    {
        std::getline(file, str);
        if (str.length() < 2) { continue; }
        std::cout << "\t" << termcolor::color<100> << count << ": " << termcolor::white << str << std::endl;
        count++;
    }
    std::cout << "\n";

    file.close();
}

int ToDoList::TUI(int mode)
{
    if (mode == 1)
    {
        text(1);

        return 0;
    }
    else if (mode == 2)
    {
        text(3);
        int choice = makeChoice();

        return choice;
    }
    else if (mode == 3)
    {
        clearScreen();
        output();
        text(2);
        std::cout << "> ";
        int choice = makeChoice();

        return choice;
    }

    return 0;
}

int ToDoList::makeChoice()
{
    int result = 3;
    std::cin >> result;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return result; 
}

void ToDoList::choiceHandle(int choice)
{
    if (choice == 1)
    {
        string s1;
        std::cout << "Enter new task: ";
        std::getline(std::cin, s1);
        clearScreen();
        newTask(s1);
    }
    else if (choice == 2)
    {
        std::cout << "Enter number of task: ";
        int index = makeChoice();
        if (deleteTask(index) != false)
            clearScreen();
    }
    else if (choice == 3)
    {
        Settings settings;
        int working = 1;
        while (working)
        {
            working = settings.settingsScreen();
        }
    }
    else if (choice == 9)
    {
        clearScreen();
        exit(0);
    }
}

void ToDoList::writeLogs(int mode, string description)
{
    std::ofstream file(pathToLogs, std::ios_base::app);
    time_t seconds = time(NULL);
    tm *timeinfo = localtime(&seconds);

    if (mode == 1)
    {
        file << asctime(timeinfo) << "* Creating a new task: " << description << "\n\n";
    }
    else if(mode == 2)
    {
        file << asctime(timeinfo) << "* Remove a task: " << description << "\n\n";
    }

    file.close();
}

void ToDoList::text(int mode)
{
    if (mode == 1 || mode == 2)
    {
        std::cout << termcolor::white;
        std::cout << "1. New Task\n";
        std::cout << "2. Delete Task\n";
        std::cout << "3. Settings\n";
        std::cout << "9. Exit\n";
    }
    else if (mode == 2 || mode == 3)
    {
        std::cout << "Enter an item: ";
    }
}

void ToDoList::clearScreen()
{
    std::cout << "\e[H\e[2J\e[3J";
}