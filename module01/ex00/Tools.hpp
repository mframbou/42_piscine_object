#pragma once

#include <iostream>

class Worker;


class Tool {
    public:
        int numberOfUses;
        virtual ~Tool() {}
        virtual void use() = 0;
        virtual std::string getName() = 0;
        Worker *owner;

    protected:
        Tool(int numberOfUses): numberOfUses(numberOfUses), owner(nullptr) {}
};

struct Shovel: public Tool {
    Shovel(): Tool(0) {
        std::cout << this->getName() << " " << this << " created" << std::endl;
    }

    ~Shovel() {
        std::cout << this->getName() << " " << this << " destroyed" << std::endl;
    }

    virtual void use() {
        this->numberOfUses++;
        std::cout << this->getName() << " " << this << " used (total " << this->numberOfUses << " uses)" << std::endl;
    }

    virtual std::string getName() {
        return "Shovel";
    }
};

struct Hammer: public Tool {
    Hammer(): Tool(0) {
        std::cout << this->getName() << " " << this << " created" << std::endl;
    }

    ~Hammer() {
        std::cout << this->getName() << " " << this << " destroyed" << std::endl;
    }

    virtual void use() {
        this->numberOfUses++;
        std::cout << this->getName() << " " << this << " used (total " << this->numberOfUses << " uses)" << std::endl;
    }

    virtual std::string getName() {
        return "Hammer";
    }
};