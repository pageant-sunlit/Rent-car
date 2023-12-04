// Customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
public:
    Customer(const std::string& name);

    const std::string& getName() const;

private:
    std::string name;
};

#endif // CUSTOMER_H

// Customer.cpp
#include "Customer.h"

Customer::Customer(const std::string& name) : name(name) {}

const std::string& Customer::getName() const {
    return name;
}
