// CarManager.h
#ifndef CAR_MANAGER_H
#define CAR_MANAGER_H

#include "Car.h"
#include <vector>

class CarManager {
public:
    void addCar(const std::string& make, const std::string& model, int year, double pricePerDay);
    void displayCars() const;
    const Car& getCarByIndex(int index) const;
    double rentCar(int index, int days);
    void returnCar(int index);

private:
    std::vector<Car> cars;
};

#endif // CAR_MANAGER_H

// CarManager.cpp
#include "CarManager.h"
#include <iostream>

void CarManager::addCar(const std::string& make, const std::string& model, int year, double pricePerDay) {
    Car car(make, model, year, pricePerDay);
    cars.push_back(car);
}

void CarManager::displayCars() const {
    std::cout << "Available Cars:\n";
    for (size_t i = 0; i < cars.size(); ++i) {
        const Car& car = cars[i];
        std::string availability = car.isAvailable() ? "Available" : "Rented";
        std::cout << i + 1 << ". " << car.getYear() << " " << car.getMake() << " " << car.getModel()
                  << " - " << availability << "\n";
    }
    std::cout << "\n";
}

const Car& CarManager::getCarByIndex(int index) const {
    return cars[index];
}

double CarManager::rentCar(int index, int days) {
    Car& car = cars[index];
    if (car.isAvailable()) {
        car.setAvailable(false);
        return car.getPricePerDay() * days;
    } else {
        std::cout << "Car not available for rent.\n";
        return 0.0;
    }
}

void CarManager::returnCar(int index) {
    cars[index].setAvailable(true);
}
