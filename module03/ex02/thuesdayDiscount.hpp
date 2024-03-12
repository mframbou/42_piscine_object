#pragma once

#include "command.hpp"

class ThuesdayDiscountCommand : public Command {
    public:
        float get_total_price() {
            float total = Command::get_total_price();
            if (getDate() == 2)
                total *= 0.9;
            return total;
        }
};