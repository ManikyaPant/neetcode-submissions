class Vehicle {
public:
    virtual string getType() = 0;
};

class Car : public Vehicle {
public:
    string getType() override {
        return "Car";
    }
};

class Bike : public Vehicle {
public:
    string getType() override {
        return "Bike";
    }
};

class Truck : public Vehicle {
public:
    string getType() override {
        return "Truck";
    }
};

class VehicleFactory {
public:
    virtual Vehicle* createVehicle() = 0;
};

class CarFactory : public VehicleFactory {
    // Write your code here
    virtual Vehicle* createVehicle() {
        Vehicle* m_car = new Car();
        return m_car;
    }
};

class BikeFactory : public VehicleFactory {
    // Write your code here

    virtual Vehicle* createVehicle() {
        Vehicle* m_bike= new Bike();
        return m_bike;
    }
};

class TruckFactory : public VehicleFactory {
    // Write your code here

    virtual Vehicle* createVehicle() {
        Vehicle* m_truck = new Truck();
        return m_truck;
    }
};
