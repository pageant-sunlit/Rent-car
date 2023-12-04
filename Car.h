// Car.h
#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
public:
    Car(const std::string& make, const std::string& model, int year, double pricePerDay);

    const std::string& getMake() const;
    const std::string& getModel() const;
    int getYear() const;
    double getPricePerDay() const;
    bool isAvailable() const;
    void setAvailable(bool available);

private:
    std::string make;
    std::string model;
    int year;
    double pricePerDay;
    bool available;
};

#endif // CAR_H

// Car.cpp
#include "Car.h"

Car::Car(const std::string& make, const std::string& model, int year, double pricePerDay)
    : make(make), model(model), year(year), pricePerDay(pricePerDay), available(true) {}

const std::string& Car::getMake() const {
    return make;
}

const std::string& Car::getModel() const {
    return model;
}

int Car::getYear() const {
    return year;
}

double Car::getPricePerDay() const {
    return pricePerDay;
}

bool Car::isAvailable() const {
    return available;
}

void Car::setAvailable(bool available) {
    this->available = available;
}
