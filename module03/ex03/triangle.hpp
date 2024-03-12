#pragma once

#include "shape.hpp"
#include <cmath>
#include <iostream>

class Triangle : public Shape {
    public:
        Triangle(double length1, double length2, double length3) : _length1(length1), _length2(length2), _length3(length3) {}

        double area() const override {
            double semiPerimeter = (_length1 + _length2 + _length3) / 2; // Here, "s" is the semi-perimeter of the triangle, i.e., s = (a + b + c)/2.
            return std::sqrt(semiPerimeter * (semiPerimeter - _length1) * (semiPerimeter - _length2) * (semiPerimeter - _length3)); // Area = √[s(s-a)(s-b)(s-c)]
        }
        
        double perimeter() const override {
            return _length1 + _length2 + _length3;
        }

        void printInfo() const override {
            std::cout << "Triangle(length1: " << _length1 << ", length2: " << _length2 << ", length3: " << _length3 << ")" << std::endl;
        }
        
    private:
        double _length1;
        double _length2;
        double _length3;
};