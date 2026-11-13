#ifndef MEDICINE_HPP
#define MEDICINE_HPP

#include <string>
#include <iostream>

class Medicine {
protected:
    int id;
    std::string brandName;
    std::string activeIngredient;
    double price;
    int stockCount;
    std::string expiryDate;

public:
    Medicine(int id, std::string bName, std::string aIng, double p, int s, std::string exp)
        : id(id), brandName(bName), activeIngredient(aIng), price(p), stockCount(s), expiryDate(exp) {}

    virtual ~Medicine() = default;

    int getId() const { return id; }
    std::string getBrandName() const { return brandName; }
    std::string getActiveIngredient() const { return activeIngredient; }
    double getPrice() const { return price; }
    int getStock() const { return stockCount; }
    std::string getExpiry() const { return expiryDate; }

    bool dispense(int qty) {
        if (stockCount >= qty) {
            stockCount -= qty;
            return true;
        }
        return false;
    }
};

#endif
