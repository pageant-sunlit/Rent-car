#include "CarManager.h"
#include "CustomerManager.h"
#include "RentalManager.h"

int main() {
    // Initialize car, customer, and rental managers
    CarManager carManager;
    CustomerManager customerManager;
    RentalManager rentalManager(carManager);

    // Add cars
    carManager.addCar("Toyota", "Camry", 2022, 50);
    carManager.addCar("Honda", "Civic", 2022, 40);

    // Display available cars
    carManager.displayCars();

    // Create customers
    Customer customer1 = customerManager.createCustomer("John Doe");
    Customer customer2 = customerManager.createCustomer("Jane Doe");

    // Display customers
    customerManager.displayCustomers();

    // Customers rent cars
    rentalManager.rentCar(customer1, carManager.getCarByIndex(0), 5);
    rentalManager.rentCar(customer2, carManager.getCarByIndex(1), 3);

    // Display rental details
    rentalManager.displayRentals();

    // Customers return cars
    rentalManager.returnCar(customer1, carManager.getCarByIndex(0));
    rentalManager.returnCar(customer2, carManager.getCarByIndex(1));

    // Display available cars after returns
    carManager.displayCars();

    return 0;
}
