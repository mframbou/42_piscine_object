#include <iostream>
#include "command.hpp"
#include "packageReductionDiscount.hpp"
#include "thuesdayDiscount.hpp"

int main() {
    ArticleQuantity article1("tortillas", 1.5, 3); // 4.5
    ArticleQuantity article2("tofu", 8.5, 3); // 25.5
    ArticleQuantity article3("parmigiano", 4.5, 1); // 4.5
    // total: 34.5
    ArticleQuantity article4("pomme de terre gucci", 125.0, 1);
    // total: 159.5

    Command *command = new Command();
    Command *thuesdayDiscountCommand = new ThuesdayDiscountCommand();
    Command *packageReductionDiscountCommand = new PackageReductionDiscountCommand();
    command->addArticle(article1);
    command->addArticle(article2);
    command->addArticle(article3);
    thuesdayDiscountCommand->addArticle(article1);
    thuesdayDiscountCommand->addArticle(article2);
    thuesdayDiscountCommand->addArticle(article3);
    packageReductionDiscountCommand->addArticle(article1);
    packageReductionDiscountCommand->addArticle(article2);
    packageReductionDiscountCommand->addArticle(article3);

    std::cout << "Command total price: " << command->get_total_price() << std::endl;
    std::cout << "Thuesday command total price (on sunday): " << command->get_total_price() << std::endl;
    std::cout << "Package reduction command total price: " << command->get_total_price() << std::endl;

    std::cout << "-------------------------" << std::endl;

    command->addArticle(article4);
    thuesdayDiscountCommand->addArticle(article4);
    packageReductionDiscountCommand->addArticle(article4);

    thuesdayDiscountCommand->setDate(2); // thuesday

    std::cout << "Command total price: " << command->get_total_price() << std::endl;
    std::cout << "Thuesday command total price (on thuesday): " << thuesdayDiscountCommand->get_total_price() << std::endl;
    std::cout << "Package reduction command total price: " << packageReductionDiscountCommand->get_total_price() << std::endl;
}