#include <iostream>

class Car {
    private:
        bool _started;
        int _speed;
        int _gear;
        int _direction;
        friend class CarLogger;

    public:
        Car(): _started(false), _speed(0), _gear(0), _direction(0) {}
        ~Car() {}
        void start() {
            if (!_started) {
                _started = true;
                _gear = 1;
            }
        }

        void stop() {
            if (_started) {
                _started = false;
                _gear = 0; // neutral
                _speed = 0;
            }
        }

        void accelerate(int speed) {
            if (_started) {
                _speed += speed;
            }
        }

        void shift_gears_up() {
            if (_started && _gear < 5) {
                _gear++;
            }
        }

        void shift_gears_down() {
            if (_started && _gear > 1) {
                _gear--;
            }
        }

        void reverse() {
            if (_started) {
                _gear = -1;
            }
        }

        void turn_wheel(int angle) {
            if (_started) {
                _direction += angle;
            }
        }

        void straighten_wheel() {
            if (_started) {
                _direction = 0;
            }
        }

        void apply_force_on_brakes(int force) {
            if (_started) {
                _speed -= force;
                if (_speed < 0)
                    _speed = 0;
            }
        }

        void apply_emergency_brakes() {
            if (_started) {
                _speed = 0;
            }
        }
};

// We log in a separate class to respect first SOLID principle (Single Responsibility)
class CarLogger {
    public:
        static void log(const Car& car) {
            std::cout << "Car status: ";
            if (car._started) {
                std::cout << "started";
            } else {
                std::cout << "stopped";
            }
            std::cout << std::endl;
            std::cout << "Speed: " << car._speed << " km/h" << std::endl;
            std::cout << "Gear: ";
            if (car._gear == 0)
                std::cout << "neutral";
            else if (car._gear == -1)
                std::cout << "reverse";
            else
                std::cout << car._gear;
            std::cout << std::endl;
            std::cout << "Direction: " << car._direction << " degrees" << std::endl;
        }
};
