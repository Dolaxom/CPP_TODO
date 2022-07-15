CFLAGS:=-Wall -Werror -Wextra -std=c++1z

TODOLIST:=todo

all: $(TODOLIST)

$(TODOLIST): main.cpp todo.cpp
	g++ $(CFLAGS) todo.cpp main.cpp -o $(TODOLIST)


clean:
	rm $(TODOLIST)

rebuild: clean all
