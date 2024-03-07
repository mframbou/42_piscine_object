#include "Worker.hpp"
#include "Workshop.hpp"

Worker::Worker(): coordonnee({0, 0, 0}), stat({0, 0}) {
    std::cout << "Worker " << this << " created" << std::endl;
    (void) this->coordonnee;
    (void) this->stat;
}

Worker::~Worker() {
    std::cout << "Worker " << this << " destroyed" << std::endl;
    for (std::vector<Tool *>::iterator it = this->tools.begin(); it != this->tools.end(); it++)
        (*it)->owner = nullptr;
    // copy workshops vector to avoid modifying it while iterating
    std::vector<Workshop *> copy = this->workshops;
    for (std::vector<Workshop *>::iterator it = copy.begin(); it != copy.end(); it++)
        (*it)->unregisterWorker(this);
}

void Worker::giveTool(Tool *tool) {
    std::cout << tool->getName() << " " << tool << " given to worker " << this << std::endl;
    if (tool->owner != nullptr)
        tool->owner->removeTool(tool);
    this->tools.push_back(tool);
    tool->owner = this;
}

void Worker::removeTool(Tool *tool) {
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
            std::vector<Workshop *> copy = this->workshops;
            for (std::vector<Workshop *>::iterator it = copy.begin(); it != copy.end(); it++)
                (*it)->unregisterWorker(this);
            break;
        }
    }
    if (!found)
        std::cout << tool->getName() << " " << tool << " not found in worker " << this << std::endl;
}

void Worker::printTools() {
    if (this->tools.size() == 0)
    {
        std::cout << "Worker " << this << " does not have any tools" << std::endl;
        return;
    }
    
    std::cout << "Worker " << this << " has the following tools:" << std::endl;
    for (std::vector<Tool *>::iterator it = this->tools.begin(); it != this->tools.end(); it++)
        std::cout << "   - " << (*it)->getName() << " " << *it << std::endl;
}

void Worker::work() {
    if (this->workshops.size() == 0)
    {
        std::cout << "Worker " << this << " is not registered in any workshops" << std::endl;
        return;
    }

    for (std::vector<Workshop *>::iterator it = this->workshops.begin(); it != this->workshops.end(); it++)
        std::cout << "Worker " << this << " working in workshop " << *it << std::endl;
}