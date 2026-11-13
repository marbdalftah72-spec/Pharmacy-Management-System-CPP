#include <iostream>
#include <vector>
#include <memory>
#include "../include/Medicine.hpp"

int main() {
    std::cout << "====================================================\n";
    std::cout << "    HOSPITAL & PHARMACY DISPENSARY SYSTEM v1.5     \n";
    std::cout << "    Developed by Ammar Abdelfattah (NINU Eng)      \n";
    std::cout << "====================================================\n";

    std::vector<Medicine> catalog;
    catalog.emplace_back(201, "Augmentin 1g", "Amoxicillin / Clavulanic Acid", 95.00, 50, "2027-08");
    catalog.emplace_back(202, "Panadol Extra", "Paracetamol / Caffeine", 45.00, 120, "2028-01");
    catalog.emplace_back(203, "Concor 5mg", "Bisoprolol Fumarate", 62.50, 80, "2027-05");

    std::cout << "\nActive Pharmacy Formulary Loaded successfully:\n";
    for (const auto& med : catalog) {
        std::cout << " [" << med.getId() << "] " << med.getBrandName() 
                  << " (" << med.getActiveIngredient() << ") - Price: " 
                  << med.getPrice() << " EGP | Stock: " << med.getStock() << " units\n";
    }
    return 0;
}
