#include "todo.h"

int main() {
    ToDoList ToDoListInstance;
    ToDoList *ToDo = &ToDoListInstance;
    while (true) {
        ToDo->TUI();
        std::cout << "Enter an item: ";
        int choice = ToDo->makeChoice();

        if (choice == 1) {
            string s1;
            std::cout << "Enter new task: ";
            std::getline(std::cin, s1);
            std::cout << "\e[H\e[2J\e[3J";
            ToDo->newTask(s1);
        } else if (choice == 2) {
            std::cout << "Enter number of task: ";
            int index = ToDo->makeChoice();
            if (ToDo->deleteTask(index) != false) {
                std::cout << "\e[H\e[2J\e[3J";
            }
        } else if (choice == 3) {
            std::cout << "\e[H\e[2J\e[3J";
            ToDo->output();
        }
    }

}
