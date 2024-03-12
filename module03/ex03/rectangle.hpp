#pragma once

#include "shape.hpp"
#include <iostream>

class Rectangle : public Shape {
    public:
        Rectangle(double width, double height) : _width(width), _height(height) {}

        double area() const override {
            return _width * _height;
        }

        double perimeter() const override {
            return 2 * (_width + _height);
        }

        void printInfo() const override {
            std::cout << "Rectangle(width: " << _width << ", height: " << _height << ")" << std::endl;
        }

    private:
        double _width;
        double _height;
};