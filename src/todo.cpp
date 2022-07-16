#include "todo.h"

ToDoList::ToDoList()
{
    pathToTasks = "../data/tasks.txt";
    pathToLogs = "../data/logs.txt";
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
        tmp.erase(tmp.begin() + index - 1);

        std::ofstream outfile(pathToTasks);
        if (outfile.is_open())
        {
            std::copy(tmp.begin(), tmp.end(), std::ostream_iterator<string>(outfile, "\n"));
            outfile.close();

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
        std::cout << termcolor::white;
        std::cout << "1. New Task\n";
        std::cout << "2. Delete Task\n";
        std::cout << "3. Output Tasks\n";

        return 0;
    }
    else if (mode == 2)
    {
        std::cout << "Enter an item: ";
        int choice = makeChoice();

        return choice;
    }
    else if (mode == 3)
    {
        std::cout << termcolor::white;
        std::cout << "1. New Task\n";
        std::cout << "2. Delete Task\n";
        std::cout << "3. Output Tasks\n";

        std::cout << "Enter an item: ";
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
        std::cout << "\e[H\e[2J\e[3J";
        newTask(s1);
    }
    else if (choice == 2)
    {
        std::cout << "Enter number of task: ";
        int index = makeChoice();
        if (deleteTask(index) != false)
        {
            std::cout << "\e[H\e[2J\e[3J";
        }
    }
    else if (choice == 3)
    {
        std::cout << "\e[H\e[2J\e[3J";
        output();
    }
}

void ToDoList::writeLogs(int mode, string description)
{
    std::ofstream file(pathToLogs, std::ios_base::app);
    time_t seconds = time(NULL);
    tm *timeinfo = localtime(&seconds);

    if (mode == 1) {
        file << asctime(timeinfo) << "* Creating a new task: " << description << "\n\n";
    }

    file.close();
}