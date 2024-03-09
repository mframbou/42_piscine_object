#include <iostream>
#include "car.hpp"

int main() {
    CarLogger logger;
    Car car;

    car.shift_gears_down();
    car.accelerate(100);
    
    logger.log(car);
    std::cout << "---------------" << std::endl;

    car.start();
    car.shift_gears_up();
    car.accelerate(100);

    logger.log(car);
    std::cout << "---------------" << std::endl;

    car.turn_wheel(45);
    car.apply_force_on_brakes(50);

    logger.log(car);
    std::cout << "---------------" << std::endl;

    car.apply_emergency_brakes();
    car.reverse();
    car.accelerate(10);

    logger.log(car);
    std::cout << "---------------" << std::endl;
    
    car.straighten_wheel();
    car.apply_force_on_brakes(100);
    
    logger.log(car);
    std::cout << "---------------" << std::endl;

    car.turn_wheel(10);
    car.accelerate(50);
    car.stop();

    logger.log(car);
    std::cout << "---------------" << std::endl;
}