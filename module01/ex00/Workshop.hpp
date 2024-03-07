#pragma once

#include <algorithm>
#include <iostream>

#include "Tools.hpp"
#include "Worker.hpp"

class Workshop {
    private:
        std::vector<Worker *> workers;

    public:
        Workshop();
        ~Workshop();
        
        template <typename T>
        void registerWorker(Worker *worker) {
            // check if worker already in the vector
            if (std::find(this->workers.begin(), this->workers.end(), worker) != this->workers.end())
            {
                std::cout << "Worker " << worker << " already registered to workshop " << this << std::endl;
                return;
            }
            
            Tool *tool = worker->getTool<T>();
            if (tool == NULL)
            {
                std::cout << "Worker " << worker << " does not have the required tool" << std::endl;
                return;
            }
            std::cout << "Worker " << worker << " registered to workshop " << this << std::endl;
            this->workers.push_back(worker);
            worker->workshops.push_back(this);
        }

        void unregisterWorker(Worker *worker);
        void printWorkers();
};