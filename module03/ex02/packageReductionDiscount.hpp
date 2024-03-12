#pragma once

#include "command.hpp"

class PackageReductionDiscountCommand : public Command {
    public:
        float get_total_price() {
            float total = Command::get_total_price();
            if (total > 150.0)
                total -= 10.0;
            return total;
        }
};