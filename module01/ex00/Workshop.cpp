#include <algorithm>
#include <iostream>
#include <vector>

#include "Workshop.hpp"
#include "Worker.hpp"

Workshop::Workshop() {
    std::cout << "Workshop " << this << " created with tool type " << std::endl;
}

Workshop::~Workshop() {
    std::cout << "Workshop " << this << " destroyed" << std::endl;
    for (std::vector<Worker *>::iterator it = this->workers.begin(); it != this->workers.end(); it++)
        this->unregisterWorker(*it);
}

void Workshop::unregisterWorker(Worker *worker) {
    bool found = false;
    for (std::vector<Worker *>::iterator it = this->workers.begin(); it != this->workers.end(); it++)
    {
        if (*it == worker)
        {
            found = true;
            std::cout << "Worker " << worker << " unregistered from workshop " << this << std::endl;
            this->workers.erase(it);
            worker->workshops.erase(std::find(worker->workshops.begin(), worker->workshops.end(), this));
            break;
        }
    }
    if (!found)
        std::cout << "Worker " << worker << " not found in workshop " << this << std::endl;
}

void Workshop::printWorkers() {
    if (this->workers.size() == 0)
    {
        std::cout << "Workshop " << this << " does not have any workers" << std::endl;
        return;
    }
    
    std::cout << "Workshop " << this << " has the following workers:" << std::endl;
    for (std::vector<Worker *>::iterator it = this->workers.begin(); it != this->workers.end(); it++)
        std::cout << "   - " << *it << std::endl;
}