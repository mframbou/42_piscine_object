#pragma once

#include <string>
#include <vector>

class ArticleQuantity {
    private:
        std::string _name;
        float _price;
        int _quantity;

    public:
        ArticleQuantity(std::string name, float price, int quantity): _name(name), _price(price), _quantity(quantity) {}

        float getTotalPrice() {
            return _price * _quantity;
        }

        std::string getName() {
            return _name;
        }
};

class Command {
    private:
        int _id;
        int _date;

    protected:
        int _client;
        std::vector<ArticleQuantity> _articles;

    public:
        virtual float get_total_price() {
            float total = 0;
            for (auto article : _articles) {
                total += article.getTotalPrice();
            }
            return total;
        }

        void addArticle(ArticleQuantity article) {
            _articles.push_back(article);
        }

        int getDate() {
            return _date;
        }

        void setDate(int date) {
            _date = date;
        }
};