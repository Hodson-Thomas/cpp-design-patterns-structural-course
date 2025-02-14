//
// Created by thoma on 14/02/2025.
//

#include <iostream>
#include <memory>
using namespace std;

class Pizza {
public:
    virtual string description() const = 0;

    virtual double price() const = 0;

    virtual ~Pizza() = default;
};

class MargheritaPizza : public Pizza {
public:
    string description() const override {
        return "Margherita Pizza";
    }

    double price() const override {
        return 9.99;
    }
};

class HawaiianPizza : public Pizza {
public:
    string description() const override {
        return "Hawaiian Pizza";
    }

    double price() const override {
        return 11.99;
    }
};

class PepperoniPizza : public Pizza {
public:
    string description() const override {
        return "Pepperoni Pizza";
    }

    double price() const override {
        return 12.99;
    }
};

class ToppingDecorator : Pizza {
private:
    const unique_ptr<Pizza> pizza;

public:
    explicit ToppingDecorator(Pizza *pizza) : pizza(pizza) {
    }

    string description() const override {
        return pizza->description();
    }

    double price() const override {
        return pizza->price();
    }
};


class MushroomDecorator : ToppingDecorator {
public:
    explicit MushroomDecorator(Pizza *pizza)
        : ToppingDecorator(pizza) {
    }

    string description() const override {
        return ToppingDecorator::description() + " with mushrooms";
    }

    double price() const override {
        return ToppingDecorator::price() + 10;
    }
};

class TomatoDecorator : ToppingDecorator {
public:
    explicit TomatoDecorator(Pizza *pizza)
        : ToppingDecorator(pizza) {
    }

    string description() const override {
        return ToppingDecorator::description() + " with tomatoes";
    }

    double price() const override {
        return ToppingDecorator::price() + 15;
    }
};

class ExtraCheeseDecorator : ToppingDecorator {
public:
    explicit ExtraCheeseDecorator(Pizza *pizza)
        : ToppingDecorator(pizza) {
    }

    string description() const override {
        return ToppingDecorator::description() + " with extra cheese";
    }

    double price() const override {
        return ToppingDecorator::price() + 20;
    }
};
