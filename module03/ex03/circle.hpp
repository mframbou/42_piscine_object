#pragma once

#include "shape.hpp"
#include <iostream>

class Circle : public Shape {
    public:
        Circle(double radius) : _radius(radius) {}

        double area() const override {
            return 3.14159 * (_radius * _radius); // pi r carré
        }
        
        double perimeter() const override {
            return 2 * 3.14159 * _radius; // 2 pi r
        }

        void printInfo() const override {
            std::cout << "Circle(radius: " << _radius << ")" << std::endl;
        }

    private:
        double _radius;
};