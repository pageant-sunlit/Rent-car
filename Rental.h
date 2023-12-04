// Rental.h
#ifndef RENTAL_H
#define RENTAL_H

#include "Customer.h"
#include "Car.h"

class Rental {
public:
    Rental(const Customer& customer, const Car& car, int days);

    const Customer& getCustomer() const;
    const Car& getCar() const;
    int getDays() const;
    double getCost() const;

private:
    const Customer& customer;
    const Car& car;
    int days;
    double cost;
};

#endif // RENTAL_H

// Rental.cpp
#include "Rental.h"

Rental::Rental(const Customer& customer, const Car& car, int days)
    : customer(customer), car(car), days(days), cost(car.getPricePerDay() * days) {}

const Customer& Rental::getCustomer() const {
    return customer;
}

const Car& Rental::getCar() const {
    return car;
}

int Rental::getDays() const {
    return days;
}

double Rental::getCost() const {
    return cost;
}
