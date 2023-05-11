#include <iostream>
#include <vector>
using namespace std;

class Car
{
public:
    string licensePlate;
    string brand;
    string color;
    Car(string licensePlate, string brand, string color)
    {
        this->licensePlate = licensePlate;
        this->brand = brand;
        this->color = color;
    }
};

class ParkingLot
{
public:
    int capacity;
    vector<Car> parked_cars;
    ParkingLot(int capacity)
    {
        this->capacity = capacity;
    }

    bool parkCar(Car car)
    {
        if (parked_cars.size() < capacity)
        {
            parked_cars.push_back(car);
            cout << "Car parked successfully!" << endl;
            return true;
        }
        else
        {
            cout << "Sorry, parking lot is full." << endl;
            return false;
        }
    }

    bool unParkCar(Car car)
    {
        for (int i = 0; i < parked_cars.size(); i++)
        {
            if (parked_cars[i].licensePlate == car.licensePlate)
            {
                parked_cars.erase(parked_cars.begin() + i);
                cout << "Car unparked successfully!" << endl;
                return true;
            }
        }
        cout << "Sorry, car not found in parking lot." << endl;
        return false;
    }

    void showParkedCars()
    {
        if (parked_cars.size() == 0)
        {
            cout << "No cars parked in the parking lot." << endl;
        }
        else
        {
            cout << "List of parked cars:" << endl;
            for (int i = 0; i < parked_cars.size(); i++)
            {
                cout << i + 1 << ". " << parked_cars[i].brand << " " << parked_cars[i].color << " - " << parked_cars[i].licensePlate << endl;
            }
        }
    }
};

class Admin
{
public:
    ParkingLot *parkingLot;
    Admin(ParkingLot *parkingLot)
    {
        this->parkingLot = parkingLot;
    }

    void addParkingLotCapacity(int capacity)
    {
        parkingLot->capacity += capacity;
        cout << "Parking lot capacity increased to " << parkingLot->capacity << endl;
    }
};

int main()
{
    ParkingLot *parkingLot = new ParkingLot(3);
    Admin *admin = new Admin(parkingLot);

    Car car1("ABC123", "Toyota", "Red");
    Car car2("XYZ789", "Honda", "Blue");
    Car car3("DEF456", "Ford", "Green");
    Car car4("GHI789", "Tesla", "White");

    parkingLot->parkCar(car1);
    parkingLot->parkCar(car2);
    parkingLot->parkCar(car3);
    parkingLot->parkCar(car4);

    admin->addParkingLotCapacity(2);

    parkingLot->unParkCar(car2);

    parkingLot->showParkedCars();

    return 0;
}
