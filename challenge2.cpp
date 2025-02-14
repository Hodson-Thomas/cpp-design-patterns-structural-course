//
// Created by thoma on 14/02/2025.
//

#include <iostream>
#include <memory>

class IEngine {
public:
    virtual void start() const;

    ~IEngine() = default;
};


class IVehicule {
public:
    IVehicule(const IEngine &engine) : engine(engine) {
    }

    ~IVehicule() = default;

    void drive() const {
        engine.start();
        driveVehicule();
    }

protected:
    virtual void driveVehicule() const;

private:
    const IEngine &engine;
};


class GasEngine : public IEngine {
public:
    void start() const override {
        std::cout << "Starting gaz engine ...\n";
    }
};

class ElectricEngine : public IEngine {
public:
    void start() const override {
        std::cout << "Starting electric engine ...\n";
    }
};

class HybridEngine : public IEngine {
public:
    void start() const override {
        std::cout << "Starting both electric and gaz engines ...\n";
    }
};

class Car : public IVehicule {
public:
    Car(const IEngine& engine) : IVehicule(engine) {}
    void driveVehicule() const override {
        std::cout << "Driving car ...\n";
    }
};

class Truck : public IVehicule {
public:
    Truck(const IEngine& engine) : IVehicule(engine) {}
    void driveVehicule() const override {
        std::cout << "Driving truck ...\n";
    }
};
