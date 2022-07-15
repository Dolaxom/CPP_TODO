#include "todo.h"

int main() {
    ToDoList ToDoListInstance;
    ToDoList *ToDo = &ToDoListInstance;
    while (true)
    {
        int choice = ToDo->TUI(3);

        ToDo->choiceHandle(choice);
    }

}
