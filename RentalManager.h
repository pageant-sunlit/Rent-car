// RentalManager.h
#ifndef RENTAL_MANAGER_H
#define RENTAL_MANAGER_H

#include "Rental.h"
#include "CarManager.h"
#include <vector>

class RentalManager {
public:
    RentalManager(CarManager& carManager);
    void rentCar(const Customer& customer, const Car& car, int days);
    void returnCar(const Customer& customer, const Car& car);
    void displayRentals() const;

private:
    CarManager& carManager;
    std::vector<Rental> rentals;
};

#endif // RENTAL_MANAGER_H

// RentalManager.cpp
#include "RentalManager.h"
#include <iostream>

RentalManager::RentalManager(CarManager& carManager) : carManager(carManager) {}

void RentalManager::rentCar(const Customer& customer, const Car& car, int days) {
    Rental rental(customer, car, days);
    double cost = carManager.rentCar(carManager.getCarIndex(car), days);
    rental.setCost(cost);
    rentals.push_back(rental);
}

void RentalManager::returnCar(const Customer& customer, const Car& car) {
    carManager.returnCar(carManager.getCarIndex(car));
    for (size_t i = 0; i < rentals.size(); ++i) {
        if (&rentals[i].getCustomer() ==
