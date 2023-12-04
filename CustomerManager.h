// CustomerManager.h
#ifndef CUSTOMER_MANAGER_H
#define CUSTOMER_MANAGER_H

#include "Customer.h"
#include <vector>

class CustomerManager {
public:
    const Customer& createCustomer(const std::string& name);
    void displayCustomers() const;

private:
    std::vector<Customer> customers;
};

#endif // CUSTOMER_MANAGER_H

// CustomerManager.cpp
#include "CustomerManager.h"
#include <iostream>

const Customer& CustomerManager::createCustomer(const std::string& name) {
    customers.emplace_back(name);
   
