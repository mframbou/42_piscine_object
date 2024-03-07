#pragma once

#include <vector>
#include <iostream>

class Tool;
class Workshop;

struct Position {
    int x;
    int y;
    int z;
};

struct Statistic {
    int level;
    int exp;
};

// Composition simply represents a "has-a" relationship, eg. a Worke rhas a position and statistics (eg. computer has a CPU)
// Aggregation means that both entities can survive independently (eg. computer might have a monitor, but the monitor can exist without the computer)
class Worker {
    private:
        Position coordonnee;
        Statistic stat;
        std::vector<Tool *> tools;
        std::vector<Workshop *> workshops;

        friend class Workshop;

    public:
        Worker();
        ~Worker();
        void giveTool(Tool *tool);
        void removeTool(Tool *tool);
        void printTools();
        void work();

        template <typename T>
        T *getTool() {
            for (std::vector<Tool *>::iterator it = this->tools.begin(); it != this->tools.end(); it++)
            {
                T *tool = dynamic_cast<T *>(*it); // dynamic_cast returns NULL if the cast fails
                if (tool != NULL)
                    return tool;
            }
            return NULL;
        }
};