#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

int main() {
    Shape* shapes[] = {
        new Circle(5),
        new Rectangle(4, 5),
        new Triangle(3, 4, 5)
    };

    for (auto shape : shapes) {
        shape->printInfo();
        std::cout << "Area: " << shape->area() << std::endl;
        std::cout << "Perimeter: " << shape->perimeter() << std::endl;
        std::cout << std::endl;
    }
}