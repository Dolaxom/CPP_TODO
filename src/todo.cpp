#include "todo.h"

ToDoList::ToDoList()
{
    nameOfFile = "../data/tasks.txt";
}

void ToDoList::newTask(string newTask)
{
    std::ofstream file(nameOfFile, std::ios_base::app);
    file << newTask << "\n";
    file.close();
}

bool ToDoList::deleteTask(int index)
{
    std::vector<string> tmp;

    std::ifstream file(nameOfFile);
    if (file.is_open())
    {
        string str;
        while (std::getline(file, str))
        {
            tmp.push_back(str);
        }
        file.close();

        if (index > tmp.size())
        {
            std::cout << termcolor::red << "ERROR: " << termcolor::white << "Your index > max num of tasks\n";
            return false;
        }
        tmp.erase(tmp.begin() + index - 1);

        std::ofstream outfile(nameOfFile);
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
    std::ifstream file(nameOfFile);
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

void ToDoList::TUI()
{
    std::cout << termcolor::white;
    std::cout << "1. New Task\n";
    std::cout << "2. Delete Task\n";
    std::cout << "3. Output Tasks\n";
}

int ToDoList::makeChoice()
{
    int result = 3;
    std::cin >> result;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return result; 
}