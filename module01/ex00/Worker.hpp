#pragma once

#include <iostream>
#include <vector>
#include "Tools.hpp"

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

    public:
        Worker(): coordonnee({0, 0, 0}), stat({0, 0}) {
            std::cout << "Worker " << this << " created" << std::endl;
            (void) this->coordonnee;
            (void) this->stat;
        }

        ~Worker() {
            std::cout << "Worker " << this << " destroyed" << std::endl;
        }

        void giveTool(Tool *tool) {
            std::cout << tool->getName() << " " << tool << " given to worker " << this << std::endl;
            if (tool->owner != nullptr)
                tool->owner->removeTool(tool);
            this->tools.push_back(tool);
            tool->owner = this;
        }

        void removeTool(Tool *tool) {
            // check if the tool is in the vector
            bool found = false;
            for (std::vector<Tool *>::iterator it = this->tools.begin(); it != this->tools.end(); it++)
            {
                if (*it == tool)
                {
                    found = true;
                    std::cout << tool->getName() << " " << tool << " removed from worker " << this << std::endl;
                    this->tools.erase(it);
                    tool->owner = nullptr;
                    break;
                }
            }
            if (!found)
                std::cout << tool->getName() << " " << tool << " not found in worker " << this << std::endl;
        }

        void printTools() {
            if (this->tools.size() == 0)
            {
                std::cout << "Worker " << this << " does not have any tools" << std::endl;
                return;
            }
            
            std::cout << "Worker " << this << " has the following tools:" << std::endl;
            for (std::vector<Tool *>::iterator it = this->tools.begin(); it != this->tools.end(); it++)
                std::cout << "   - " << (*it)->getName() << " " << *it << std::endl;
        }
};